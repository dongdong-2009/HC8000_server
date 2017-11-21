#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <pthread.h> 
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>

#include <stdint.h>
#include <getopt.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include "spidev.h"

#include <math.h>
#include <time.h>
#include <limits.h>
#include <stdarg.h>
#include <sys/types.h>    
#include <termios.h>  



#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define debug_pos() printf("%s-%d\n", __FUNCTION__, __LINE__);
#define PI 3.1415926535897932384626433832795028841971
#define RX_BUF_SIZE_DIV4 1024
#define RX_BUF_SIZE_DIV2 (RX_BUF_SIZE_DIV4 *2)
#define RX_BUF_SIZE_DIV8 512

#define PORT 32000  //网络端口
#define SIZEBUF 256 //接收信息buf的大小
#define DATALEN 8  //截取字段
#define MSGBUF 24  //发送信息buf大小
#define MSGSIZE 1024*11  //发送显示信息msg大小

#define DEBUG 0
#define UART_DEVICE "/dev/ttyS2" //uart设备文件名 


static int fdFpga1 = 0;
static const char *device = "/dev/spidev1.0";
static uint8_t mode;
static uint8_t bits = 8;
//static uint32_t speed = 500000;
static uint32_t speed = 20000000;
static uint16_t delay;

struct Reg{
	char name[32];
	int addr_base;
	int addr_offset;
	int width;
	uint32_t mask;
}tmp;

struct Reg reg[] = 
{	
	{ "evb_ver_minor",                           0x0,   0,        32,   0xffffff00},
	{ "evb_ver_major",                           0x0,   8,        32,   0xffff00ff},
	{ "evb_config_usb",                          0x0,   16,       32,   0xfffeffff},
	{ "evb_config_serial",                       0x0,   17,	      32,	0xfffdffff},
	{ "evb_config_ethernet",                     0x0,   18,       32,	0xfffbffff},
	{ "evb_config_tdm",	                         0x0,   19,	      32,	0xfff7ffff},
	{ "evb_config_aconf",	                     0x0,  	20,	      32,	0xffefffff},
	{ "evb_config_ethernet_que",                 0x0,  	21,	      32,	0xffdfffff},
	{ "evb_config_spim2",                        0x0,   22,	      32,	0xffbfffff},
	{ "evb_config_usb_ft232",                    0x0,   23,	      32,	0xff7fffff},
	{ "evb_config_spis",                         0x0,   24,	      32,	0xfeffffff},
	{ "evb_config_modem1",                       0x0,   25,	      32,	0xfdffffff},
	{ "evb_config_dpll",                         0x0,   26,	      32,	0xfbffffff},
	{ "evb_config_modem2",                       0x0,   27,	      32,	0xf7ffffff},
	{ "evb_config_ssm",                          0x0,   28,       32,	0xefffffff},
	{ "evb_config_odu",                          0x0,   29,	      32,	0xdfffffff},
	{ "evb_config_xpic_test_mod",                0x0,  	30,	      32,	0xbfffffff},
	{ "evb_config_cpuss",                        0x0,   31,	      32,	0x7fffffff},
	{ "evb_compile_time",                        0x4,   0,	      32,	0x0L      },
	{ "evb_aconf_start",                         0x8,   30,	      32,	0xbfffffff},
	{ "evb_aconf_done",                          0x8,   31,	      32,	0x7fffffff},
	{ "evb_scope_sel",                           0xc,   0,	      32,   0xffffffe0},
	{ "evb_scope_sel_spi",                       0xc,   8,	      32,   0xffffe0ff},
	{ "evb_scope_sel_cpu",                       0xc,   16,	      32,   0xffe0ffff},
	{ "evb_common_scope_sel_ena",                0xc,   31,	      32,   0x7fffffff},
	{ "evb_dac_sync",                            0x10,  0,        32,   0xfffffffe},
	{ "evb_idelay0",                             0x10,  8,	      32,	0xffff00ff},
	{ "evb_idelay1",                           	 0x10,  16,	      32,	0xff00ffff},
	{ "evb_gpo",                                 0x14,  0,	      32,	0xffffff00},
	{ "evb_gpo_oe",                              0x14,  8,	      32,	0xffff00ff},
	{ "evb_gpi",                                 0x14,  16,	      32,	0xff00ffff},
	{ "evb_gpi_irq_ena",                         0x14,  24,	      32,	0xffffff  },
	{ "evb_sw_reset",                            0x18,  0,	      32,	0xfffffffe},
	{ "evb_dlb_ena",                             0x1c,  0,	      32,	0xfffffffe},
	{ "evb_xpi12_swap",                          0x1c,  1,	      32,	0xfffffffd},
	{ "evb_xpi21_swap",                          0x1c,  2,	      32,	0xfffffffb},
	{ "evb_xpic_fifo_sclr",                      0x1c,  4,	      32,	0xffffffef},
	{ "evb_xpi12_dly",                           0x1c,  8,	      32,	0xffffc0ff},
	{ "evb_xpi21_dly",                           0x1c,  16,	      32,	0xffc0ffff},
	{ "evb_xpi12_lvl",                           0x20,  0,	      32,	0xfffff000},
	{ "evb_xpi21_lvl",                           0x20,  16,	      32,	0xf000ffff},
	{ "evb_irq_uc_rx_avail",                     0x28,  0,	      32,	0xfffffffe},
	{ "evb_irq_uc_tx_empty",                     0x28,  1,	      32,	0xfffffffd},
	{ "evb_irq_atpc_local",                      0x28,  2,	      32,	0xfffffffb},
	{ "evb_irq_atpc_remote",                     0x28,  3,	      32,   0xfffffff7},
	{ "evb_irq_dpll_status_change",            	 0x28, 	4,	      32,   0xffffffef},
	{ "evb_irq_dpll_ref_change",                 0x28,  5,	      32,   0xffffffdf},
	{ "evb_irq_gpi_status",                      0x28,  6,	      32,   0xffffffbf},
	{ "evb_irq_tdm_status",                      0x28,  7,	      32,   0xffffff7f},
	{ "evb_irq_uc2_rx_avail",                    0x28,  8,	      32,   0xfffffeff},
	{ "evb_irq_uc2_tx_empty",                    0x28, 	9,	      32,	0xfffffdff},
	{ "evb_irq_atpc2_local",                     0x28,  10,	      32,	0xfffffbff},
	{ "evb_irq_atpc2_remote",                    0x28,  11,	      32,	0xfffff7ff},
	{ "evb_irq_uc_rx_avail_ena",                 0x28,  16,	      32,	0xfffeffff},
	{ "evb_irq_uc_tx_empty_ena",                 0x28,  17,	      32,	0xfffdffff},
	{ "evb_irq_atpc_local_ena",                  0x28,  18,	      32,	0xfffbffff},
	{ "evb_irq_atpc_remote_ena",                 0x28,  19,	      32,	0xfff7ffff},
	{ "evb_irq_dpll_status_change_ena",          0x28,  20,	      32,	0xffefffff},
	{ "evb_irq_dpll_ref_change_ena",             0x28,  21,	      32,	0xffdfffff},
	{ "evb_irq_gpi_status_ena",                  0x28,  22,	      32,	0xffbfffff},
	{ "evb_irq_tdm_status_ena",                  0x28,  23,	      32,	0xff7fffff},
	{ "evb_irq_uc2_rx_avail_ena",                0x28,  24,	      32,	0xfeffffff},
	{ "evb_irq_uc2_tx_empty_ena",                0x28,  25,	      32,	0xfdffffff},
	{ "evb_irq_atpc2_local_ena",                 0x28,  26,	      32,	0xfbffffff},
	{ "evb_irq_atpc2_remote_ena",                0x28,  27,	      32,	0xf7ffffff},
	{ "evb_irq_global",                          0x28,  31,	      32,	0x7fffffff},
	{ "evb_gpi_irq",                             0x2c,  0,	      32,	0xffffff00},
	{ "evb_dbg_20_status",                       0x30,  0,	      32,	0x80000000},
	{ "evb_dbg_20_ena",                          0x30,  31,	      32,	0x7fffffff},

	{ "dpll_ver_minor",                          0x100, 	0 ,	  32,	0xffffff00},
	{ "dpll_ver_major",                          0x100, 	8 ,	  32,	0xffff00ff},
	{ "dpll_dpll_mode",                          0x104, 	0,	  32,	0xfffffff0},
	{ "dpll_dpll_state",                         0x104, 	16,	  32,	0xfff8ffff},
	{ "dpll_dpll_status_rx_1",                   0x108, 	0,	  32,	0xfffffffe},
	{ "dpll_dpll_status_rx_2",                   0x108, 	1,	  32,	0xfffffffd},
	{ "dpll_dpll_status_ref0",                   0x108, 	2,	  32,	0xfffffffb},
	{ "dpll_dpll_status_ref1",                   0x108, 	3,	  32,	0xfffffff7},
	{ "dpll_dpll_status_rcv0",                   0x108, 	6,	  32,	0xffffffbf},
	{ "dpll_dpll_status_rcv1",                   0x108, 	7,	  32,	0xffffff7f},
	{ "dpll_dpll_tx_kp",                         0x10c, 	0,	  32,	0xffffffe0},
	{ "dpll_dpll_tx_ki",                         0x10c, 	8,	  32,	0xffffe0ff},
	{ "dpll_dpll_rx_kp",                         0x10c, 	16,	  32,	0xffe0ffff},
	{ "dpll_dpll_rx_ki",                         0x10c, 	24,	  32,	0xe0ffffff},
	{ "dpll_divisor_ref0",                       0x110, 	0,	  32,	0xffff0000},
	{ "dpll_divisor_ref1",                       0x110, 	16,	  32,	0xffff    },
	{ "dpll_ext_rx_ref_divisor",                 0x118, 	0,	  32,	0xffff8000},
	{ "dpll_adj_override_ref0",                  0x11c, 	0,	  32,	0xffffff00},
	{ "dpll_adj_override_ref1",                  0x11c, 	8,	  32,	0xffff00ff},
	{ "dpll_dpll_state_change",                  0x120, 	0,	  32,	0xfffffffc},
	{ "dpll_dpll_tx_symrate_adj",                0x124, 	0,	  32,	0x0       },

	{ "tdm_ver_minor",                           0x1a0, 	0,	  32,	0xffffff00},
	{ "tdm_ver_major",                           0x1a0, 	8,	  32,	0xffff00ff},
	{ "tdm_tdm_e1_liu",                          0x1a0, 	16,	  32,	0xfffeffff},
	{ "tdm_tdm_6144",                            0x1a0, 	17,	  32,	0xfffdffff},
	{ "tdm_tdm_hdb3_loop",                       0x1a0, 	18,	  32,	0xfffbffff},
	{ "tdm_tdm_stm1_supported",                  0x1a0, 	19,	  32,	0xfff7ffff},
	{ "tdm_tdm_e1_channels",                     0x1a0, 	20,	  32,	0xffcfffff},
	{ "tdm_tdm_irq",                             0x1a0, 	24,	  32,	0xffffff  },
	{ "tdm_tdm_bytes",                           0x1a4, 	0,	  32,	0xffffe000},
	{ "tdm_tdm_test",                            0x1a4, 	13,	  32,	0xffff9fff},
	{ "tdm_tdm_pdh_mux_n",                       0x1a4, 	15,	  32,	0xff007fff},
	{ "tdm_tdm_tributaries",                     0x1a4, 	24,	  32,	0xe0ffffff},
	{ "tdm_tdm_stm1",                            0x1a4, 	30,	  32,	0xbfffffff},
	{ "tdm_tdm_vcxo",                            0x1a4, 	31,	  32,	0x7fffffff},
	{ "tdm_tdm_source_target",                   0x1a8, 	0,	  32,	0xfffff000},
	{ "tdm_tdm_sink_target",                     0x1a8, 	12,	  32,	0xff000fff},
	{ "tdm_tdm_target_coef",                     0x1a8, 	24,	  32,	0xfcffffff},
	{ "tdm_tdm_stm1_tx_s1",                      0x1a8, 	28,	  32,	0xfffffff },
	{ "tdm_tdm_status",                          0x1ac, 	0,	  32,	0xffffffc0},
	{ "tdm_tdm_vcxo_fault",                      0x1ac, 	6,	  32,	0xffffff3f},
	{ "tdm_tdm_stm1_tx_OOF",                     0x1ac, 	10,	  32,	0xfffffbff},
	{ "tdm_tdm_stm1_rx_OOF",                   	 0x1ac, 	11,	  32,	0xfffff7ff},
	{ "tdm_tdm_stm1_rx_s1",                      0x1ac, 	12,	  32,	0xffff0fff},
	{ "tdm_tdm_e1_active",                       0x1ac, 	16,	  32,	0xffff    },
	{ "tdm_tdm_vco_n",                           0x1b0, 	0,	  32,	0xffffff00},
	{ "tdm_tdm_vco_m",                           0x1b4, 	0,	  32,	0xffffff00},
	{ "tdm_tdm_vco_c0",                          0x1b8, 	0,	  32,	0xffffff00},
	{ "tdm_tdm_vco_pre",                         0x1bc, 	0,	  32,	0xfffffffc},

	{ "tme_conf_rx_pause_addr0",                 0x800, 	0,	  32,    	   0x0       },
	{ "tme_conf_rx_pause_addr1",                 0x804, 	0,	  32,		   0xffff0000},
	{ "tme_conf_rx_crc_err_disable",             0x804, 	24,	  32,		   0xfeffffff},
	{ "tme_conf_rx_len_err_disable",             0x804, 	25,	  32,		   0xfdffffff},
	{ "tme_conf_rx_half_duplex",                 0x804, 	26,	  32,		   0xfbffffff},
	{ "tme_conf_rx_vlan_enable",                 0x804, 	27,	  32,		   0xf7ffffff},
	{ "tme_conf_rx_enable",                      0x804, 	28,	  32,		   0xefffffff},
	{ "tme_conf_rx_crc_forward",                 0x804, 	29,	  32,		   0xdfffffff},
	{ "tme_conf_rx_jumbo_enable",                0x804, 	30,	  32,		   0xbfffffff},
	{ "tme_conf_rx_reset",                       0x804, 	31,	  32,		   0x7fffffff},
	{ "tme_conf_tx_ifg_adj_ena",                 0x808, 	25,	  32,		   0xfdffffff},
	{ "tme_conf_tx_half_duplex",                 0x808, 	26,	  32,		   0xfbffffff},
	{ "tme_conf_tx_vlan_enable",                 0x808, 	27,	  32,		   0xf7ffffff},
	{ "tme_conf_tx_enable",                      0x808, 	28,	  32,		   0xefffffff},
	{ "tme_conf_tx_crc_forward",                 0x808, 	29,	  32,		   0xdfffffff},
	{ "tme_conf_tx_jumbo_enable",                0x808, 	30,	  32,		   0xbfffffff},
	{ "tme_conf_tx_reset",                       0x808, 	31,	  32,		   0x7fffffff},
	{ "tme_conf_rx_flow_cntrl_ena",              0x80c, 	29,	  32,		   0xdfffffff},
	{ "tme_conf_tx_flow_cntrl_ena",              0x80c, 	30,	  32,		   0xbfffffff},
	{ "tme_conf_mac_speed",                      0x810, 	30,	  32,		   0x3fffffff},
	{ "tme_conf_rx_max_frame",                   0x814, 	0,	  32,		   0xffff8000},
	{ "tme_conf_rx_max_frame_ena",               0x814, 	16,	  32,		   0xfffeffff},
	{ "tme_conf_tx_max_frame",                   0x818, 	0,	  32,		   0xffff8000},
	{ "tme_conf_tx_max_frame_ena",               0x818, 	16,	  32,		   0xfffeffff},
	{ "tme_conf_id_patch_level",                 0x8f8, 	0,	  32,		   0xffffff00},
	{ "tme_conf_ver_minor",                      0x8f8, 	16,	  32,		   0xff00ffff},
	{ "tme_conf_ver_major",                      0x8f8, 	24,	  32,		   0xffffff  },
	{ "tme_conf_ability_10m",                    0x8fc, 	0,	  32,		   0xfffffffe},
	{ "tme_conf_ability_100m",                   0x8fc, 	1,	  32,		   0xfffffffd},
	{ "tme_conf_ability_1g",                     0x8fc, 	2,	  32,		   0xfffffffb},
	{ "tme_conf_ability_statistics",             0x8fc, 	8,	  32,		   0xfffffeff},
	{ "tme_conf_ability_hd",                     0x8fc, 	9,	  32,		   0xfffffdff},
	{ "tme_conf_ability_framefilter",            0x8fc, 	10,	  32,		   0xfffffbff},

	{ "tme_mdio_clk_div",                        0x900, 	0,	  32,		   0xffffffc0},
	{ "tme_mdio_enable",                         0x900, 	6,	  32,		   0xffffffbf},
	{ "tme_mdio_ready",                          0x904, 	7,	  32,		   0xffffff7f},
	{ "tme_mdio_initiate",                       0x904, 	11,	  32,		   0xfffff7ff},
	{ "tme_mdio_op",                             0x904, 	14,	  32,		   0xffff3fff},
	{ "tme_mdio_regad",                          0x904, 	16,	  32,		   0xffe0ffff},
	{ "tme_mdio_phyad",                          0x904, 	24,	  32,		   0xe0ffffff},
	{ "tme_mdio_wdata",                          0x908, 	0,	  32,		   0xffff0000},
	{ "tme_mdio_rdata",                          0x90c, 	0,	  32,		   0xffff0000},
	{ "tme_mdio_rdata_rdy",                      0x90c, 	16,	  32,		   0xfffeffff},

	{ "tme_stat_rx_bytes",                       0xa00, 	0,	  32,		   0x0},
	{ "tme_stat_tx_bytes",                       0xa08, 	0,	  32,		   0x0},
	{ "tme_stat_rx_usize_frames",                0xa10, 	0,	  32,		   0x0},
	{ "tme_stat_tx_usize_frames",                0xa18, 	0,	  32,		   0x0},
	{ "tme_stat_rx_64_frames",                   0xa20, 	0,	  32,		   0x0},
	{ "tme_stat_rx_65to127_frames",              0xa28, 	0,	  32,		   0x0},
	{ "tme_stat_rx_128to255_frames",             0xa30, 	0,	  32,		   0x0},
	{ "tme_stat_rx_256to511_frames",             0xa38, 	0,	  32,		   0x0},
	{ "tme_stat_rx_512to1023_frames",            0xa40, 	0,	  32,		   0x0},
	{ "tme_stat_rx_1024toMax_frames",            0xa48, 	0,	  32,		   0x0},
	{ "tme_stat_rx_osize_frames",                0xa50, 	0,	  32,		   0x0},
	{ "tme_stat_tx_64_frames",                   0xa58, 	0,	  32,		   0x0},
	{ "tme_stat_tx_65to127_frames",              0xa60, 	0,	  32,		   0x0},
	{ "tme_stat_tx_128to255_frames",             0xa68, 	0,	  32,		   0x0},
	{ "tme_stat_tx_256to511_frames",             0xa70, 	0,	  32,		   0x0},
	{ "tme_stat_tx_512to1023_frames",            0xa78, 	0,	  32,		   0x0},
	{ "tme_stat_tx_1024toMax_frames",            0xa80, 	0,	  32,		   0x0},
	{ "tme_stat_tx_osize_frames",                0xa88, 	0,	  32,		   0x0},
	{ "tme_stat_rx_good_frames",                 0xa90, 	0,	  32,		   0x0},
	{ "tme_stat_rx_crc_errors",                  0xa98, 	0,	  32,		   0x0},
	{ "tme_stat_rx_bcast_frames",                0xaa0, 	0,	  32,		   0x0},
	{ "tme_stat_rx_mcast_frames",                0xaa8, 	0,	  32,		   0x0},
	{ "tme_stat_rx_cntrl_frames",                0xab0, 	0,	  32,		   0x0},
	{ "tme_stat_rx_len_errors",                  0xab8, 	0,	  32,		   0x0},
	{ "tme_stat_rx_vlan_frames",                 0xac0, 	0,	  32,		   0x0},
	{ "tme_stat_rx_pause_frames",                0xac8, 	0,	  32,		   0x0},
	{ "tme_stat_rx_op_errors",                   0xad0, 	0,	  32,		   0x0},
	{ "tme_stat_tx_good_frames",                 0xad8, 	0,	  32,		   0x0},
	{ "tme_stat_tx_bcast_frames",                0xae0, 	0,	  32,		   0x0},
	{ "tme_stat_tx_mcast_frames",                0xae8, 	0,	  32,		   0x0},
	{ "tme_stat_tx_urun_errors",                 0xaf0, 	0,	  32,		   0x0},
	{ "tme_stat_tx_cntrl_frames",                0xaf8, 	0,	  32,		   0x0},
	{ "tme_stat_tx_vlan_frames",                 0xb00, 	0,	  32,		   0x0},
	{ "tme_stat_tx_pause_frames",                0xb08, 	0,	  32,		   0x0},
	{ "tme_stat_tx_single_collisions",           0xb10, 	0,	  32,		   0x0},
	{ "tme_stat_tx_multi_collisions",            0xb18, 	0,	  32,		   0x0},
	{ "tme_stat_tx_deferred",                    0xb20, 	0,	  32,		   0x0},
	{ "tme_stat_tx_late_collisions",             0xb28, 	0,	  32,		   0x0},
	{ "tme_stat_tx_excess_collisions",           0xb30, 	0,	  32,		   0x0},
	{ "tme_stat_tx_excess_deferral",             0xb38, 	0,	  32,		   0x0},
	{ "tme_stat_tx_align_errors",                0xb40, 	0,	  32,		   0x0},

	{ "eth_ver_minor",                           0xc00, 	0,	  32,		   0xffffff00},
	{ "eth_ver_major",                           0xc00, 	8,	  32,		   0xffff00ff},
	{ "eth_rx_fifo_len",                         0xc04, 	0,	  32,		   0x0       },
	{ "eth_tx_fifo_len",                         0xc08, 	0,	  32,		   0x0       },
	{ "eth_xon_thres",                           0xc0c, 	0,	  32,		   0xffff0000},
	{ "eth_xoff_thres",                          0xc10, 	0,	  32,		   0xffff0000},
	{ "eth_xoff_timeout",                        0xc14, 	0,	  32,		   0xfffffc00},
	{ "eth_xon_xoff_dis",                        0xc14, 	31,	  32,		   0x7fffffff},
	{ "eth_eth_local_loopback",                  0xc18, 	0,	  32,		   0xfffffffe},
	{ "eth_eth_lb_ena_override",                 0xc18, 	1,	  32,		   0xfffffffd},
	{ "eth_pause_quanta",                        0xc1c, 	0,	  32,		   0xffff0000},
	{ "eth_rx_detected",                         0xc20, 	0,	  32,		   0x0       },
	{ "eth_rx_dropped",                          0xc24, 	0,	  32,		   0x0       },
	{ "eth_tx_detected",                         0xc28, 	0,	  32,		   0x0       },
	{ "eth_tx_dropped",                          0xc2c, 	0,	  32,		   0x0       },

	{ "tx_info",                                 0x4000,	0,	  32,		   0xffff0000},
	{ "tx_ver_minor",                            0x4000,	16,	  32,		   0xff00ffff},
	{ "tx_ver_major",                            0x4000,	24,	  32,		   0xffffff  },
	{ "tx_pilot_level",                          0x4004,	0,	  32,		   0xffffff00},
	{ "tx_pilot_only_ena",                       0x4004,	8,	  32,		   0xfffffeff},
	{ "tx_scrambler_seed",                       0x4004,	16,	  32,		   0xfffeffff},
	{ "tx_symrate",                              0x4008,	0,	  32,		   0xffffff00},
	{ "tx_mod_indx",                             0x4008,	8,	  32,		   0xfffff0ff},
	{ "tx_ilv_depth",                            0x4008,	16,	  32,		   0xff00ffff},
	{ "tx_wayside_len",                          0x4008,	24,	  32,		   0xffffffL },
	{ "tx_fec_cw_len",                           0x400c,	0,	  32,		   0xffffff00},
	{ "tx_fec_pl_len",                           0x400c,	8,	  32,		   0xffff00ff},
	{ "tx_fec_override_ena",                     0x400c,	16,	  32,		   0xfffeffff},
	{ "tx_symadjust",                            0x4010,	8,	  32,		   0xff      },
	{ "tx_dpd_sqr_a",                            0x4014,	0,	  32,		   0xfffffffc},
	{ "tx_dpd_sqr_p",                            0x4014,	4,	  32,		   0xffffff0f},
	{ "tx_dpd_dbg_level_a",                      0x4014,	8,	  32,		   0xffff00ff},
	{ "tx_dpd_dbg_level_p",                      0x4014,	16,	  32,		   0xff00ffff},
	{ "tx_dpd_enable",                           0x4014,	24,	  32,		   0xfeffffff},
	{ "tx_dpd_status_lock",                      0x4014,	25,	  32,		   0xfdffffff},
	{ "tx_dpd_status_a",                         0x4018,	0,	  32,		   0xffffff00},
	{ "tx_dpd_status_p",                         0x4018,	8,	  32,		   0xffff00ff},
	{ "tx_dpd_override_a",                       0x4018,	16,	  32,		   0xff00ffff},
	{ "tx_dpd_override_p",                       0x4018,	24,	  32,		   0xffffffL },
	{ "tx_dc_offset_i",                          0x401c,	0,	  32,		   0xffff0000},
	{ "tx_dc_offset_q",                          0x401c,	16,	  32,		   0xffff    },
	{ "tx_awgn_scaler",                          0x4020,	0,	  32,		   0xffff0000},
	{ "tx_attenuate",                            0x4024,	0,	  32,		   0xfffffff0},
	{ "tx_lsb_mask_sel",                         0x4024,	8,	  32,		   0xfffff8ff},
	{ "tx_lo_dds_freq",                          0x4028,	0,	  32,		   0x0       },
	{ "tx_dbg_sqsig_load",                       0x402c,	0,	  32,		   0xffff8000},
	{ "tx_dbg_mls_len",                          0x4030,	0,	  32,		   0xfffffffc},
	{ "tx_dbg_mls_mode",                         0x4030,	4,	  32,		   0xffffff0f},
	{ "tx_dbg_lo_out_ena",                       0x4030,	8,	  32,		   0xfffffeff},
	{ "tx_dbg_bert_ena",                         0x4030,	16,	  32,		   0xfffeffff},
	{ "tx_dbg_zeroes_ena",                       0x4030,	17,	  32,		   0xfffdffff},
	{ "tx_dac_i_delay_ena",                      0x4034,	0,	  32,		   0xfffffffe},
	{ "tx_dac_q_delay_ena",                      0x4034,	1,	  32,		   0xfffffffd},
	{ "tx_dac_iq_swap",                          0x4034,	2,	  32,		   0xfffffffb},
	{ "tx_dpd_override_ena",                     0x4034,	3,	  32,		   0xfffffff7},
	{ "tx_coef_data",                            0x4034,	8,	  32,		   0xffff00ff},
	{ "tx_coef_addr",                            0x4034,	16,	  32,		   0xffff    },
	{ "tx_coef_addr_data",                       0x4038,	0,	  32,		   0x0       },

	{ "rx_hw_xpic_eq",                           0x4100,	1,	  32,		   0xfffffffd},
	{ "rx_hw_ifsampling_mode",                   0x4100,	2,	  32,		   0xfffffffb},
	{ "rx_ver_minor",                            0x4100,	16,	  32,		   0xff00ffff},
	{ "rx_ver_major",                            0x4100,	24,	  32,		   0xffffff  },
	{ "rx_lo_dds_freq",                          0x4104,	8,	     32,	       0xff      },              
	{ "rx_symrate",                              0x4108,	0,	     32,	       0xffffff00},              
	{ "rx_mod_indx",                             0x4108,	8,	     32,	       0xfffff0ff},              
	{ "rx_ilv_depth",                            0x4108,	16,	     32,	       0xff00ffff},              
	{ "rx_wayside_len",                          0x4108,	24,	     32,	       0xffffff  },              
	{ "rx_fec_cw_len",                           0x410c,	0,	     32,	       0xffffff00},              
	{ "rx_fec_pl_len",                           0x410c,	8,	     32,	       0xffff00ff},              
	{ "rx_fec_override_ena",                     0x410c,	16,	     32,	       0xfffeffff},              
	{ "rx_symadjust",                            0x4110,	8,	     32,	       0xff      },              
	{ "rx_dde_step",                             0x4114,	0,	     32,  		   0xffffffc0},                  
	{ "rx_dde_qpsk_zf_ena",                      0x4114,	6,	     32,  		   0xffffffbf},                  
	{ "rx_dde_zf_reset",                         0x4114,	7,	     32,  		   0xffffff7f},
	{ "rx_agc1_gain_override",                   0x4114,	8,	     32,  		   0xffff00ff},
	{ "rx_agc1_gain_invert",                     0x4114,	16,	     32,		   0xfffeffff},
	{ "rx_scrambler_seed",                       0x4114,	17,	     32,  		   0xfffdffff},
	{ "rx_corr_disable",                         0x4114,	18,	     32,  		   0xfffbffff},
	{ "rx_corr_dc_ofs_i",                        0x4118,	0,	     32,  		   0xffffff00},
	{ "rx_corr_dc_ofs_q",                        0x4118,	8,	     32,  		   0xffff00ff},
	{ "rx_corr_iq_magnitude",                    0x4118,	16,	     32,  		   0xff00ffff},
	{ "rx_corr_iq_phase",                        0x4118,	24,	     32,  		   0xffffff  },
	{ "rx_corr_gdelay",                          0x411c,	0,	     32,  		   0xffffffe0},
	{ "rx_coef_data",                            0x411c,	8,	     32,  	       0xffff00ff},
	{ "rx_coef_addr",                            0x411c,	16,	     32,  		   0xffff    },
	{ "rx_agc1_adj",                             0x4120,	0, 	     32,  		   0xfffffff8},
	{ "rx_agc1_thres_adj",                       0x4120,	8, 	     32,		   0xffff00ff},
	{ "rx_agc2_adj",                             0x4120,	16,	     32,		   0xfff8ffff},
	{ "rx_agc2_thres",                           0x4120,	24,	     32,	       0xffffff  },
	{ "rx_ccr_delay_adj",                        0x4124,	0,	     32,	       0xffffff00},
	{ "rx_ccr_pilot_delay_adj",                  0x4124,	8,	     32,	       0xffff00ff},
	{ "rx_ccr_pid_p",                            0x4124,	16,	     32,	       0xff00ffff},
	{ "rx_ccr_pid_i",                            0x4124,	24,	     32,	       0xffffff  },
	{ "rx_fcr_adj",                              0x4128,	0, 	     32,	       0xffffff00},
	{ "rx_fcr_rc_adj",                           0x4128,	8, 	     32,	       0xfffff8ff},
	{ "rx_fcr_cffk_ofs",                         0x4128,	16,	     32,	       0xff00ffff},
	{ "rx_pdc_fmixer",                           0x412c,	0, 	     32,	       0xffffff00},
	{ "rx_pdc_pmixer",                           0x412c,	8, 	     32,		   0xffff00ff},
	{ "rx_sr_pid_p",                             0x4130,	0, 	     32,		   0xfffffffc},
	{ "rx_sr_pid_i",                             0x4130,	8,	     32,		   0xfffff8ff},
	{ "rx_sr_pid_adj",                           0x4130,	16,	     32,		   0xff00ffff},
	{ "rx_alarm_loc",                            0x4134,	0,	     32,		   0xfffffffe},
	{ "rx_alarm_hde",                            0x4134,	1,	     32,		   0xfffffffd},
	{ "rx_alarm_sde",                            0x4134,	2,	     32,		   0xfffffffb},
	{ "rx_dist_err_a",                           0x4138,	0,	     32,		   0xffffff00},
	{ "rx_dist_err_p",                           0x4138,	16,	     32,		   0xff00ffff},
	{ "rx_mse_avg",                              0x413c,	0,	     32,		   0xffffff00},
	{ "rx_ber_avg",                              0x413c,	8,	     32,		   0xffff00ff},
	{ "rx_agc1_gain",                            0x4140,	0,	     32,		   0xfffc0000},
	{ "rx_dbg_rx",                               0x4144,	0,	     32,	       0xffffff00},
	{ "rx_dbg_fdet_ofs",                         0x4144,	8,	     32,		   0xffff00ff},
	{ "rx_dbg_agc1_step_ena",                    0x4144,	16,	     32,		   0xfffeffff},
	{ "rx_dbg_agc2_step_ena",                    0x4144,	17,	     32,		   0xfffdffff},
	{ "rx_dbg_sr_step_ena",                      0x4144,	18,	     32,		   0xfffbffff},
	{ "rx_dbg_sr_csr_force",                     0x4144,	19,	     32,	       0xfff7ffff},
	{ "rx_dbg_rx_mask",                          0x4144,	24,	     32,	       0xf0ffffff},
	{ "rx_digital_loop_ena",                     0x4148,	0, 	     32,	       0xfffffffe},
	{ "rx_dsp_data_loop_ena",                    0x4148,	1, 	     32,	       0xfffffffd},
	{ "rx_adc_i_delay_ena",                      0x4148,	8,	     32,	       0xfffffeff},
	{ "rx_adc_q_delay_ena",                      0x4148,	9,	     32,	       0xfffffdff},
	{ "rx_adc_iq_swap",                          0x4148,	10,	     32,	       0xfffffbff},
	{ "rx_bert_uncoded",                         0x414c,	0,	     32,	       0x0       },
	{ "rx_bert_coded",                           0x4150,	0,	     32,	       0x0       },
	{ "rx_bert_coded_errors",                    0x4154,	0,	     32,		   0x0       },
	{ "rx_xpic_enable",                          0x4158,	0,	     32,		   0xfffffffe},
	{ "rx_xpic_eq_reset",                        0x4158,	1,	     32,		   0xfffffffd},
	{ "rx_xpic_eq_step",                         0x4158,	8,	     32,		   0xfffff0ff},
	{ "rx_xpic_eq_delay",                        0x4158,	16,	     32,		   0xff80ffff},
	{ "rx_xpic_level",                           0x415c,	0,	     32,		   0xffff0000},
	{ "rx_uncoded_window_count",                 0x415c,	16,	     32,		   0xffff    },
	{ "rx_dbg_scope_sqwave",                     0x4160,	0,	     32,		   0xffff0000},
	{ "rx_coded_window_count",                   0x4160,	16,	     32,		   0xffff    },
	{ "rx_coded_nrwin",                          0x4164,	0,	     32,		   0xffffffc0},
	{ "rx_ber_zeroes",                           0x4164,	7,	     32,		   0xffffff7f},
	{ "rx_alarm_loc_irq_ena",                    0x416c,	0,	     32,		   0xfffffffe},
	{ "rx_alarm_hde_irq_ena",                    0x416c,	1,	     32,	       0xfffffffd},
	{ "rx_alarm_sde_irq_ena",                    0x416c,	2,	     32,		   0xfffffffb},
	{ "rx_alarm_state",                          0x4170,	0,	     32,		   0xfffffff8},
	{ "rx_corr_txiq_phase",                      0x4174,	0,	     32,		   0xffffff00},
	{ "rx_corr_txiq_magnitude",                  0x4174,	8,	     32,		   0xff0000ff},
	{ "rx_rx_freq_offset",                       0x4174,	16,	     32,	       0xffff    },
	{ "rx_corr_txdc_ofs_i",                      0x4178,	0,	     32,	       0xffff0000},
	{ "rx_corr_txdc_ofs_q",                      0x4178,	16,	     32,	       0xffff    },

	{ "acm_info",                                0x7000,	0,	     32,	       0xffff0000},
	{ "acm_version",                             0x7000,	16,	     32,	       0xffff    },
	{ "acm_acm_enable",                          0x7004,	0,	     32,	       0xfffffffe},
	{ "acm_force_state",                         0x7004,	1,	     32,	       0xfffffffd},
	{ "acm_acm_update_enable",                   0x7004,	2,	     32,	       0xfffffffb},
	{ "acm_acm_ber_based",                       0x7004,	3,	     32,		   0xfffffff7},
	{ "acm_state_low_index",                     0x7004,	8,	     32,		   0xffff00ff},
	{ "acm_state_high_index",                    0x7004,	16,	     32,		   0xff00ffff},
	{ "acm_disabled_state",                      0x7004,	24,	     32,		   0xffffff  },
	{ "acm_forced_state",                        0x7008,	0,	     32,		   0xffffff00},
	{ "acm_svc_ch_exlen",                        0x7008,	8,	     32,		   0xffff00ff},
	{ "acm_tx_acm_state",                        0x700c,	0,	     32,		   0xffffff00},
	{ "acm_rx_acm_state",                        0x700c,	8,	     32,		   0xffff00ff},
	{ "acm_rx_mse_avg",                          0x700c,	16,	     32,		   0xff00ffff},
	{ "acm_fec_broken_packets",                  0x700c,	24,	     32,		   0xffffff  },
	{ "acm_atpc_mse_low",                        0x7010,	0,	     32,		   0xffffff00},
	{ "acm_atpc_mse_high",                       0x7010,	8,	     32,		   0xffff00ff},
	{ "acm_atpc_local_state",                    0x7010,	16,	     32,	       0xfffcffff},
	{ "acm_atpc_remote_state",                   0x7010,	18,	     32,		   0xfff3ffff},
	{ "acm_atpc_state_change_irq",               0x7014,	0,	     32,		   0xfffffffc},

	{ "acm_usr_rx_fifo_data",                    0x7400,	0,	     32,		   0xffffff00},
	{ "acm_usr_rx_fifo_cnt",                     0x7400,	8,	     32,	       0xffff00ff},
	{ "acm_usr_rx_fifo_full",                    0x7400,	16,	     32,	       0xfffeffff},
	{ "acm_usr_rx_channel_fail",                 0x7400,	18,	     32,	       0xfffbffff},
	{ "acm_usr_tx_fifo_avail",                   0x7404,	0,	     32,	       0xffffff00},
	{ "acm_usr_tx_fifo_data",                    0x7408,	0,	     32,	       0x0       },
};



static void pabort(const char *s)
{
    perror(s);
    abort();
}

static int tranfer_msg(int fd, uint8_t *tx, uint8_t *rx, int len)
{
	int ret;
	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)rx,
		.len = len,
		//.delay_usecs = delay,
		.delay_usecs = 0,
		.speed_hz = 0,
		.bits_per_word = 0,
		.cs_change = 0,
	};
	

	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	
	if (ret == 1){ perror("SPI_IOC_MESSAGE"); return -1;}
	
	return 0;
}

static int fpga_read(unsigned int addr, uint8_t *buf)
{
	int i, len = 4;
	uint8_t tx_buf[32] = {0};
	uint8_t rx_buf[32] = {0};

	//printf("\nfpga_read(0x%x):", addr);

	tx_buf[0] = 0x4;
	tx_buf[1] = (addr>>24) & 0xff;
	tx_buf[2] = (addr>>16) & 0xff;
	tx_buf[3] = (addr>>8) & 0xff;
	tx_buf[4] = addr & 0xff;
	tx_buf[5] = 0x8f;
	tranfer_msg(fdFpga1, tx_buf, rx_buf, 6);
	
	for (i = 0; i < 10; i ++)
	{
		tx_buf[0] = 0x8f; tx_buf[1] = 0xff;
		tranfer_msg(fdFpga1, tx_buf, rx_buf, 2);
		if ((rx_buf[1] & 0x01) == 0x00) break;
		usleep(100);
	}

	if ((rx_buf[1] & 0x01) != 0x00) return -1;

	//usleep(500);
	tx_buf[0]=0x8e;
	for (i = 0; i < len; i++)
		tx_buf[1+i] = 0xff;
	tranfer_msg(fdFpga1, tx_buf, rx_buf, len+1);

	memcpy(buf, rx_buf+1, len);
	//printf("\nfpga_read end.");
	return 0;
}

static uint32_t fpga_read_uint32(uint32_t addr)
{
	uint32_t rd = -1u;
	uint8_t buf[8] = {0};
	if (0 == fpga_read(addr, buf)){
		rd = ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
	}
	//printf("fpga_read_uint32 R(0x%x)=0x%08x\n", addr, rd);
	return rd;
}

static int fpga_write(unsigned int addr, uint8_t *buf)
{
	uint8_t tx_buf[] = {0x08, 
		buf[0], buf[1], buf[2], buf[3], 
		((addr>>24)&0xff), ((addr>>16)&0xff), ((addr>>8)&0xff), ((addr)&0xff),
		0x0f};
	return tranfer_msg(fdFpga1, tx_buf, 0, sizeof(tx_buf));
}

static int fpga_write_uint32(uint32_t addr, uint32_t data)
{
	uint8_t buf[] = {
		((data>>24)&0xff), ((data>>16)&0xff), ((data>>8)&0xff), ((data)&0xff)};
	return fpga_write(addr, buf);
}

static int wReg(char name[], int wdata)
{
	int i, itmp;
	//寻找寄存器数组
	for( i=0; i < (sizeof(reg)/sizeof(tmp)); i++)
	{
		if( strcmp( name, (char *)reg[i].name) == 0)
		{
			itmp = i;
			break;
		}
	}
	if(i == (sizeof(reg)/sizeof(tmp)))
	{
		printf("no this register\n");
		return -1;
	}
	printf("reg[%d]  addr_base 0x%x  addr_offset %d  width %d  mask 0x%x  mane %s\n", itmp, reg[itmp].addr_base, reg[itmp].addr_offset, reg[itmp].width, reg[itmp].mask, reg[itmp].name);
	
	uint32_t src_data = fpga_read_uint32( reg[itmp].addr_base);
	
	printf("R(0x%x)=0x%08x\n", reg[itmp].addr_base, src_data);
	
	uint32_t w_data = (( src_data & reg[itmp].mask) | (wdata << reg[itmp].addr_offset));
	printf("w_data=0x%08x\n", w_data);
	
	fpga_write_uint32( reg[itmp].addr_base, w_data);
	
	src_data = fpga_read_uint32( reg[itmp].addr_base);
	
	printf("R(0x%x)=0x%08x\n", reg[itmp].addr_base, src_data);
	return 0;
}


static uint32_t rReg(char name[])
{
	int i, itmp;
	//寻找寄存器数组
	for( i=0; i < (sizeof(reg)/sizeof(tmp)); i++)
	{
		if( strcmp( name, (char *)reg[i].name) == 0)
		{
			itmp = i;
			break;
		}
	}
	if(i == (sizeof(reg)/sizeof(tmp)))
	{
		printf("no this register\n");
		return -1;
	}
	printf("reg[%d]  addr_base 0x%x  addr_offset %d  width %d  mask 0x%x  mane %s\n", itmp, reg[itmp].addr_base, reg[itmp].addr_offset, reg[itmp].width, reg[itmp].mask, reg[itmp].name);
	
	uint32_t src_data = fpga_read_uint32( reg[itmp].addr_base);
	
	printf("R(0x%x)=0x%08x\n", reg[itmp].addr_base, src_data);
	
	return src_data;
}


int set_wb(int cmd)  
{  
  
    int    fdWB;  
    struct termios  oldtio, newtio;  
	char wbuf[1];
	uint32_t chnel;
//-----------打开uart设备文件------------------  
    fdWB = open(UART_DEVICE, O_RDWR|O_NOCTTY);//没有设置 O_NONBLOCK，所以这里 read 和 write 是阻塞操作  
    if (fdWB < 0) {  
        perror(UART_DEVICE);  
        exit(-1);  
    }  
    else  
        printf("Open %s success\n", UART_DEVICE);  

//-----------设置操作参数-----------------------    
    tcgetattr(fdWB, &oldtio);//获取当前操作模式参数  
    memset( &newtio, 0, sizeof(newtio));  
	
    //波特率=115200 数据位=8 使能数据接收   
    newtio.c_cflag = B115200|CS8|CLOCAL|CREAD;  
    newtio.c_iflag = IGNPAR;   
    //newtio.c_oflag = OPOST | OLCUC; //  
    /* 设定为正规模式 */  
    //newtio.c_lflag = ICANON;  
  
    tcflush(fdWB, TCIFLUSH);//清空输入缓冲区和输出缓冲区  
    tcsetattr(fdWB, TCSANOW, &newtio);//设置新的操作参数  

	//------------向urat发送数据-------------------
	
	chnel = rReg("tx_symrate") & 0xff;
	printf("tx_symrate = %d\n", chnel);
	if(chnel == 32) //28M带宽
	{
		printf("28M带宽\n");
		switch(cmd)
		{
			case 1:
				wbuf[0] = 31; 
				break;
			case 2:
				wbuf[0] = 32;
				break;	
			case 3:
				wbuf[0] = 33;
				break;
			case 4:
				wbuf[0] = 34;
				break;	
			case 5:
				wbuf[0] = 35; 
				break;
			case 6:
				wbuf[0] = 36;
				break;	
			case 7:
				wbuf[0] = 37;
				break;
			case 8:
				wbuf[0] = 38;
				break;		
			default:
				printf("set_WB cmd = %d\n", cmd);
		}
		write( fdWB, wbuf, 1);  
	}
	if(chnel == 64) //56M带宽
	{
		printf("56M带宽\n");
		switch(cmd)
		{
			case 1:
				wbuf[0] = 21; 
				break;
			case 2:
				wbuf[0] = 22;
				break;	
			case 3:
				wbuf[0] = 23;
				break;
			case 4:
				wbuf[0] = 24;
				break;
			default:
				printf("set_WB cmd = %d\n", cmd);
		}
		write( fdWB, wbuf, 1);  
	}
	if(chnel == 128) //118M带宽
	{
		printf("118M带宽\n");
		switch(cmd)
		{
			case 1:
				wbuf[0] = 11; 
				break;
			case 2:
				wbuf[0] = 12;
				break;	
			default:
				printf("set_WB cmd = %d\n", cmd);
		}
		write( fdWB, wbuf, 1);  
	}
	
//------------关闭uart设备文件，恢复原先参数--------  
    close(fdWB);  
    printf("Close %s\n", UART_DEVICE);  
    tcsetattr(fdWB, TCSANOW, &oldtio); //恢复原先的设置  
  
    return 0;  
}

int main()
{
	int c, ret;
	int wdata;
	char buf[128]={0};
	char Modulation[3]={0};
	char Channel[3]={0};
	char Data_source[3]={0};
	char Code_rate[3]={0};
	char interleaver_depth[3]={0};
	char Digital_Loopback[3]={0};
	char Dagain[4]={0};
	char Adgain[4]={0};
	char WB_mode[4] = {0};
	
	
	FILE *fp;
	
	fdFpga1 = open(device, O_RDWR);
    if (fdFpga1 < 0)
        pabort("can't open device");
	printf("fdFpga1 = %d\n",fdFpga1);
    /*
     * spi mode
     */
    ret = ioctl(fdFpga1, SPI_IOC_WR_MODE, &mode);
    if (ret == -1)
        pabort("can't set spi mode");

    ret = ioctl(fdFpga1, SPI_IOC_RD_MODE, &mode);
    if (ret == -1)
        pabort("can't get spi mode");

    /*
     * bits per word
     */
    ret = ioctl(fdFpga1, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't set bits per word");

    ret = ioctl(fdFpga1, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't get bits per word");

    /*
     * max speed hz
     */
    ret = ioctl(fdFpga1, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't set max speed hz");

    ret = ioctl(fdFpga1, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't get max speed hz");

    printf("spi mode: %d\n", mode);
    printf("bits per word: %d\n", bits);
    printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
	
	
	if((fp = fopen("config.txt","r+"))==NULL)//打开文件，之后判断是否打开成功
	{
		perror("cannot open file");
		exit(0);
	}
	while(fgets(buf,128,fp)!=NULL)
	{
		if(buf[0] == 'z')
		{
			bzero(Modulation,2);
			Modulation[0] = buf[13];
			Modulation[1] = buf[14];
			Modulation[2] = buf[15];				
			wdata = atoi( Modulation);
			printf("buf=%s wdata=%d\n", buf, wdata);
			if(wdata == 20)
			{	
				wReg("tx_mod_indx", 0xf);
				wReg("rx_mod_indx", 0xf);	
			}
			if((wdata == 13) || (wdata == 9) || (wdata == 7) || (wdata == 5) || (wdata == 3) || (wdata == 1) || (wdata == 0) || (wdata == 4) || (wdata == 2))
			{
				wReg("tx_mod_indx", wdata);
				wReg("rx_mod_indx", wdata);		
			}
		}
		if(buf[0] == 'y')
		{
			bzero(Channel,2);
			Channel[0] = buf[10];
			Channel[1] = buf[11];
			Channel[2] = buf[12];
			wdata = atoi( Channel);
			printf("buf=%s wdata=%d\n", buf, wdata);
			/*
			3.5MHz 5MHz
			
			rx_dde_step=49
			acm_state_low_index=0
			acm_state_high_index=8
			rx_ccr_pid_p=0x44
			rx_ccr_pid_i=0x33
			rx_fcr_adj=0303
			rx_fcr_rc_adj=2
			*/
#if 0
			if(wdata == 1)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 4);
				wReg("rx_symrate", 4);
				wReg("tx_symadjust", 0x00051eb7);
				wReg("rx_symadjust", 0x00055554);
				
				wReg("rx_dde_step", 0x31);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x44);
				wReg("rx_ccr_pid_i", 0x33);
				wReg("rx_fcr_adj", 0xc3);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x80);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 2)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 8);
				wReg("rx_symrate", 8);
				wReg("tx_symadjust", 0x002493b7);
				wReg("rx_symadjust", 0x00333600);
				
				wReg("rx_dde_step", 0x31);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x44);
				wReg("rx_ccr_pid_i", 0x33);
				wReg("rx_fcr_adj", 0xc3);
				wReg("rx_fcr_rc_adj", 2);

				wReg("tx_pilot_level", 0xdc);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			/*
			7MHz 10MHz
			rx_dde_step=48
			acm_state_low_index=0
			acm_state_high_index=8
			rx_ccr_pid_p=0x55
			rx_ccr_pid_i=0x55
			rx_fcr_adj=0304
			rx_fcr_rc_adj=2
			*/
			if(wdata == 3)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 8);
				wReg("rx_symrate", 8);
				wReg("tx_symadjust", 0x00051eb7);
				wReg("rx_symadjust", 0x00055554);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x55);
				wReg("rx_ccr_pid_i", 0x55);
				wReg("rx_fcr_adj", 0xc4);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x60);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 4)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x10);
				wReg("rx_symrate", 0x10);
				wReg("tx_symadjust", 0x002493b7);
				wReg("rx_symadjust", 0x00333600);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x55);
				wReg("rx_ccr_pid_i", 0x55);
				wReg("rx_fcr_adj", 0xc4);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0xdc);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);	
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}			
			/*
			14MHz 15MHz
			rx_dde_step=48
			acm_state_low_index=0
			acm_state_high_index=8
			rx_ccr_pid_p=0x66
			rx_ccr_pid_i=0x77
			rx_fcr_adj=0005
			rx_fcr_rc_adj=2
			*/
			if(wdata == 5)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x10);
				wReg("rx_symrate", 0x10);
				wReg("tx_symadjust", 0x00051eb7);
				wReg("rx_symadjust", 0x00055554);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x66);
				wReg("rx_ccr_pid_i", 0x77);
				wReg("rx_fcr_adj", 5);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x72);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 6)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x20);
				wReg("rx_symrate", 0x20);
				wReg("tx_symadjust", 0x003b6ec9);
				wReg("rx_symadjust", 0x006ef2ab);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x66);
				wReg("rx_ccr_pid_i", 0x77);
				wReg("rx_fcr_adj", 5);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0xc8);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			/*
			20MHz 28MHz 30MHz 40MHz 50MHz
			rx_dde_step=51
			acm_state_low_index=0
			acm_state_high_index=8
			rx_ccr_pid_p=0x76
			rx_ccr_pid_i=0x66
			rx_fcr_adj=0006
			rx_fcr_rc_adj=2
			*/
			if(wdata == 7)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x20);
				wReg("rx_symrate", 0x20);
				wReg("tx_symadjust", 0x002493b7);
				wReg("rx_symadjust", 0x00333600);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x66);
				wReg("rx_ccr_pid_i", 0x77);
				wReg("rx_fcr_adj", 5);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0xb4);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);	
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
#endif
			if(wdata == 8)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x20);
				wReg("rx_symrate", 0x20);
				wReg("tx_symadjust", 0x00000200);
				wReg("rx_symadjust", 0x00000200);
				
				wReg("rx_dde_step", 0x33);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x76);
				wReg("rx_ccr_pid_i", 0x66);
				wReg("rx_fcr_adj", 6);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x58);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 9)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x40);
				wReg("rx_symrate", 0x40);
				wReg("tx_symadjust", 0x003b6ec9);
				wReg("rx_symadjust", 0x006ef2ab);
				
				wReg("rx_dde_step", 0x33);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x76);
				wReg("rx_ccr_pid_i", 0x66);
				wReg("rx_fcr_adj", 6);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0xa0);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 10)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x40);
				wReg("rx_symrate", 0x40);
				wReg("tx_symadjust", 0x002493b7);
				wReg("rx_symadjust", 0x00333600);
				
				wReg("rx_dde_step", 0x33);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x76);
				wReg("rx_ccr_pid_i", 0x66);
				wReg("rx_fcr_adj", 6);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x8c);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);	
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 11)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x40);
				wReg("rx_symrate", 0x40);
				wReg("tx_symadjust", 0x000db8a4);
				wReg("rx_symadjust", 0x000f5e66);
				
				wReg("rx_dde_step", 0x33);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x76);
				wReg("rx_ccr_pid_i", 0x66);
				wReg("rx_fcr_adj", 6);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x78);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			/*
			56MHz 60MHz 80MHz 112MHz
			rx_dde_step=48
			acm_state_low_index=0
			acm_state_high_index=8
			rx_ccr_pid_p=0x77
			rx_ccr_pid_i=0x88
			rx_fcr_adj=0207
			rx_fcr_rc_adj=2
			*/
			if(wdata == 12)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x40);
				wReg("rx_symrate", 0x40);
				wReg("tx_symadjust", 0x00000200);
				wReg("rx_symadjust", 0x00000200);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x77);
				wReg("rx_ccr_pid_i", 0x88);
				wReg("rx_fcr_adj", 0x87);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x6a);
				wReg("rx_pdc_fmixer", 0xb8);
				wReg("rx_ccr_delay_adj", 0x88);	
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 13)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x80);
				wReg("rx_symrate", 0x80);
				wReg("tx_symadjust", 0x003b6ec9);
				wReg("rx_symadjust", 0x006ef2ab);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x77);
				wReg("rx_ccr_pid_i", 0x88);
				wReg("rx_fcr_adj", 0x87);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x6e);
				wReg("rx_pdc_fmixer", 0x32);
				wReg("rx_ccr_delay_adj", 0x2);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 14)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x80);
				wReg("rx_symrate", 0x80);
				wReg("tx_symadjust", 0x002493b7);
				wReg("rx_symadjust", 0x00333600);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x77);
				wReg("rx_ccr_pid_i", 0x88);
				wReg("rx_fcr_adj", 0x87);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x64);
				wReg("rx_pdc_fmixer", 0x32);
				wReg("rx_ccr_delay_adj", 0x2);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
			if(wdata == 15)
			{
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x410c);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x104);
				
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				fpga_read_uint32(0x110);
				fpga_write_uint32( 0x110, 0xffffffff);
				fpga_read_uint32(0x11c);
				fpga_write_uint32( 0x11c, 0);
				
				wReg("tx_symrate", 0x80);
				wReg("rx_symrate", 0x80);
				wReg("tx_symadjust", 0x00000200);
				wReg("rx_symadjust", 0x00000200);
				
				wReg("rx_dde_step", 0x30);
				wReg("acm_state_low_index", 0);
				wReg("acm_state_high_index", 8);
				wReg("rx_ccr_pid_p", 0x77);
				wReg("rx_ccr_pid_i", 0x88);
				wReg("rx_fcr_adj", 0x7);
				wReg("rx_fcr_rc_adj", 2);
				
				wReg("tx_pilot_level", 0x58);
				wReg("rx_pdc_fmixer", 0x32);
				wReg("rx_ccr_delay_adj", 0x2);
				
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4008);
				fpga_read_uint32(0x4010);
				fpga_read_uint32(0x124);
			}
		}
		if(buf[0] == 'x')
		{
			bzero(Data_source,2);
			Data_source[0] = buf[13];
			Data_source[1] = buf[14];
			Data_source[2] = buf[15];			
			wdata = atoi( Data_source);
			printf("buf=%s wdata=%d\n", buf, wdata);
			if((wdata == 1) || (wdata == 0))
			{
				wReg("tx_dbg_bert_ena", wdata);
			}
		}
		if(buf[0] == 'w')
		{
			bzero(Code_rate,2);
			Code_rate[0] = buf[11];
			Code_rate[1] = buf[12];	
			Code_rate[2] = buf[13];
			wdata = atoi( Code_rate);
			printf("buf=%s wdata=%d\n", buf, wdata);
		}
		if(buf[0] == 'v')
		{
			bzero(interleaver_depth,2);
			interleaver_depth[0] = buf[19];
			interleaver_depth[1] = buf[20];	
			interleaver_depth[2] = buf[21];
			wdata = atoi( interleaver_depth);
			printf("buf=%s wdata=%d\n", buf, wdata);
			if((wdata > 0) && (wdata < 20))
			{
				wReg("tx_ilv_depth", wdata);
				wReg("rx_ilv_depth", wdata);
			}
		}
		if(buf[0] == 'u')
		{
			bzero(Digital_Loopback,2);
			Digital_Loopback[0] = buf[18];
			Digital_Loopback[1] = buf[19];	
			Digital_Loopback[2] = buf[20];			
			wdata = atoi( Digital_Loopback);
			printf("buf=%s wdata=%d\n", buf, wdata);
			if((wdata == 1) || (wdata == 0))
			{
				wReg("rx_digital_loop_ena", wdata);
			}
		}
		if(buf[0] == '5')
		{
			bzero(Dagain,3);
			Dagain[0] = buf[9];
			Dagain[1] = buf[10];
			Dagain[2] = buf[11];
			Dagain[3] = buf[12];			
			wdata = atoi( Dagain);
			printf("buf=%s wdata=%d\n", buf, wdata);

			int DA_fd;	
			if((DA_fd = open("/dev/dac_dev0", O_RDWR)) < 0)
			{
				perror("Open io driver error");
				exit(1);
			}
			
			ioctl( DA_fd, 0, wdata);
			close( DA_fd);
		}
		if(buf[0] == '6')
		{
			bzero(Adgain,3);
			Adgain[0] = buf[9];
			Adgain[1] = buf[10];
			Adgain[2] = buf[11];
			Adgain[3] = buf[12];			
			wdata = atoi( Adgain);
			printf("buf=%s wdata=%d\n", buf, wdata);
			if((wdata == 0) || (wdata == 1) || (wdata == 2) || (wdata == 3) || (wdata == 4) || (wdata == 5) || (wdata == 6) || (wdata == 7))
			{
				wReg("tx_attenuate", wdata);
			}
		}
		if(buf[0] == '7')
		{
			bzero(WB_mode,3);
			WB_mode[0] = buf[9];
			WB_mode[1] = buf[10];
			WB_mode[2] = buf[11];
			WB_mode[3] = buf[12];			
			wdata = atoi( WB_mode);
			printf("buf=%s wdata=%d\n", buf, wdata);
			if((wdata == 1) || (wdata == 2) || (wdata == 3) || (wdata == 4) || (wdata == 5) || (wdata == 6) || (wdata == 7) || (wdata == 8) || (wdata == 9) || (wdata == 10) || (wdata == 11) || (wdata == 12))
			{
				set_wb( wdata);
			}
		}	
		bzero(buf,128);  //将字符数组清零，需要头文件strings.h
		sleep(1);
	}
	fclose(fp);
	close(fdFpga1);
	return 0;
}
