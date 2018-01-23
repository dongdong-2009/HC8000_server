#include "protocol.h"

struct Reg reg_r[] = 
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

static const char *device = "/dev/spidev1.0";
static uint8_t mode;
static uint8_t bits = 8;
//static uint32_t speed = 500000;
static uint32_t speed = 20000000;
static uint16_t delay;

int fdFpga;

static void print_usage(const char *prog)
{
    printf("Usage: %s [-DsbdlHOLC3]\n", prog);
    puts(" -D --device device to use (default /dev/spidev1.1)\n"
     " -s --speed max speed (Hz)\n"
     " -d --delay delay (usec)\n"
     " -b --bpw bits per word \n"
     " -l --loop loopback\n"
     " -H --cpha clock phase\n"
     " -O --cpol clock polarity\n"
     " -L --lsb least significant bit first\n"
     " -C --cs-high chip select active high\n"
     " -3 --3wire SI/SO signals shared\n");
    exit(1);
}

static void parse_opts(int argc, char *argv[])
{
    while (1) {
        static const struct option lopts[] = {
            { "device", 1, 0, 'D' },
            { "speed", 1, 0, 's' },
            { "delay", 1, 0, 'd' },
            { "bpw", 1, 0, 'b' },
            { "loop", 0, 0, 'l' },
            { "cpha", 0, 0, 'H' },
            { "cpol", 0, 0, 'O' },
            { "lsb", 0, 0, 'L' },
            { "cs-high", 0, 0, 'C' },
            { "3wire", 0, 0, '3' },
            { "no-cs", 0, 0, 'N' },
            { "ready", 0, 0, 'R' },
            { NULL, 0, 0, 0 },
        };
        int c;

        c = getopt_long(argc, argv, "D:s:d:b:lHOLC3NR", lopts, NULL);

        if (c == -1)
            break;

        switch (c) {
        case 'D':
            device = optarg;
            break;
        case 's':
            speed = atoi(optarg);
            break;
        case 'd':
            delay = atoi(optarg);
            break;
        case 'b':
            bits = atoi(optarg);
            break;
        case 'l':
            mode |= SPI_LOOP;
            break;
        case 'H':
            mode |= SPI_CPHA;
            break;
        case 'O':
            mode |= SPI_CPOL;
            break;
        case 'L':
            mode |= SPI_LSB_FIRST;
            break;
        case 'C':
            mode |= SPI_CS_HIGH;
            break;
        case '3':
            mode |= SPI_3WIRE;
            break;
        default:
            print_usage(argv[0]);
            break;
        }
    }
}

//发送信息 与spi交互
static int tranfer_msg(int fd, uint8_t *tx, uint8_t *rx, int len)
{
	//memset(rx, 0, len);
	//printf("\ntranfer_msg len:%d", len);

	int ret;
	struct spi_ioc_transfer tr = {
		.tx_buf = (unsigned long)tx,
		.rx_buf = (unsigned long)rx,
		.len = len,
		.delay_usecs = delay,
		.speed_hz = 0,
		.bits_per_word = 0,
		.cs_change = 0,
	};
	
	ret = ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
	
	if (ret == 1){ perror("SPI_IOC_MESSAGE"); return -1;}
#if 0
	printf("\nioctl SPI_IOC_MESSAGE ret:%d", ret);

	hex_dump("tx", tx, len);
	hex_dump("rx", rx, len);
	printf("\n");
#endif
	return 0;
}

static int fpga_write(unsigned int addr, uint8_t *buf)
{
	uint8_t tx_buf[] = {0x08, 
		buf[0], buf[1], buf[2], buf[3], 
		((addr>>24)&0xff), ((addr>>16)&0xff), ((addr>>8)&0xff), ((addr)&0xff),
		0x0f};
	return tranfer_msg(fdFpga, tx_buf, 0, sizeof(tx_buf));
}

static int fpga_write_uint32(uint32_t addr, uint32_t data)
{
	uint8_t buf[] = {
		((data>>24)&0xff), ((data>>16)&0xff), ((data>>8)&0xff), ((data)&0xff)};
	return fpga_write(addr, buf);
}

//读取spi数据到buf
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
	tranfer_msg(fdFpga, tx_buf, rx_buf, 6);
	
	for (i = 0; i < 10; i ++)
	{
		tx_buf[0] = 0x8f; tx_buf[1] = 0xff;
		tranfer_msg(fdFpga, tx_buf, rx_buf, 2);
		if ((rx_buf[1] & 0x01) == 0x00) break;
		usleep(100);
	}

	if ((rx_buf[1] & 0x01) != 0x00) return -1;

	//usleep(500);
	tx_buf[0]=0x8e;
	for (i = 0; i < len; i++)
		tx_buf[1+i] = 0xff;
	tranfer_msg(fdFpga, tx_buf, rx_buf, len+1);

	memcpy(buf, rx_buf+1, len);
	//printf("\nfpga_read end.");
	return 0;
}
//read 32位
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


//读寄存器

static uint32_t rReg(char name[])
{
	int i, itmp;
	uint32_t rdata;
	//寻找寄存器数组
	for( i = 0; i < (sizeof(reg_r)/sizeof(tmp)); i++)
	{
		if( strcmp( name, (char *)reg_r[i].name) == 0)
		{
			itmp = i;
			break;
		}
	}
	//printf("sizeof(reg_r)=%d,sizeof(tmp)=%d,sizeof(reg_r)/sizeof(tmp)=%d", sizeof(reg_r), sizeof(tmp), sizeof(reg_r)/sizeof(tmp));
	if(i == (sizeof(reg_r)/sizeof(tmp)))
	{
		printf("no this register\n");
		return -1;
	}
	//printf("reg_r[%d]  addr_base 0x%x  addr_offset %d  width %d  mask 0x%x  mane %s\n", itmp, reg_r[itmp].addr_base, reg_r[itmp].addr_offset, reg_r[itmp].width, reg_r[itmp].mask, reg_r[itmp].name);
	
	uint32_t src_data = fpga_read_uint32( reg_r[itmp].addr_base);
	
	//printf("R(0x%x)=0x%08x\n", reg_r[itmp].addr_base, src_data);
	
	rdata = ((src_data & ( ~( reg_r[itmp].mask))) >> reg_r[itmp].addr_offset);
	
	return rdata;
}

#if 0
static int wReg(char name[], int wdata)
{
	int i, itmp;
	//寻找寄存器数组
	for( i=0; i < (sizeof(reg_r)/sizeof(tmp)); i++)
	{
		if( strcmp( name, (char *)reg_r[i].name) == 0)
		{
			itmp = i;
			break;
		}
	}
	if(i == (sizeof(reg_r)/sizeof(tmp)))
	{
		printf("no this register\n");
		return -1;
	}
	printf("reg_r[%d]  addr_base 0x%x  addr_offset %d  width %d  mask 0x%x  mane %s\n", itmp, reg_r[itmp].addr_base, reg_r[itmp].addr_offset, reg_r[itmp].width, reg_r[itmp].mask, reg_r[itmp].name);
	
	uint32_t src_data = fpga_read_uint32( reg_r[itmp].addr_base);
	
	printf("R(0x%x)=0x%08x\n", reg_r[itmp].addr_base, src_data);
	
	uint32_t w_data = (( src_data & reg_r[itmp].mask) | (wdata << reg_r[itmp].addr_offset));
	printf("w_data=0x%08x\n", w_data);
	
	fpga_write_uint32( reg_r[itmp].addr_base, w_data);
	
	src_data = fpga_read_uint32( reg_r[itmp].addr_base);
	
	printf("R(0x%x)=0x%08x\n", reg_r[itmp].addr_base, src_data);
	return 0;
}
#endif
//判断spi状态 等待就绪
static inline int fpga_spi_status_ready()
{
	int i;
	uint8_t tx_buf[2] = {0};
	uint8_t rx_buf[2] = {0};

	for (i = 0; i < 500; i ++)
	{
		tx_buf[0] = 0x8f; tx_buf[1] = 0xff;
		tranfer_msg(fdFpga, tx_buf, rx_buf, 2);
		if ((rx_buf[1] & 0x01) == 0x00) break;
		usleep(10);
	}

	//printf("fpga_spi_status_ready 0x%x\n", rx_buf[1]);
	return ((rx_buf[1] & 0x01) == 0x00) ? 1 : 0;
}

//把地址写入spi
static inline int fpga_spi_write_addr(uint32_t addr)
{
	uint8_t tx_buf[8] = {0};

	tx_buf[0] = 0x04;
	tx_buf[1] = (addr>>24) & 0xff;
	tx_buf[2] = (addr>>16) & 0xff;
	tx_buf[3] = (addr>>8) & 0xff;
	tx_buf[4] = addr & 0xff;
	tx_buf[5] = 0x8f;
	return tranfer_msg(fdFpga, tx_buf, NULL, 6);
}

//读取spi中的数据
static inline uint32_t fpga_spi_read_uint32()
{
	uint8_t tx_buf[8] = {0x8e, 0xff};
	uint8_t rx_buf[8] = {0}, *buf = rx_buf+1;

	tranfer_msg(fdFpga, tx_buf, rx_buf, 5);
	return ((buf[0]<<24) | (buf[1]<<16) | (buf[2]<<8) | buf[3]);
}

static inline uint32_t fpga_spi_read_uint32_2()
{
	uint8_t tx_buf[8] = {0x8e, 0xff};
	uint8_t rx_buf[8] = {0}, *buf = rx_buf+1;

	tranfer_msg(fdFpga, tx_buf, rx_buf, 5);
	return ((buf[3]<<24) | (buf[2]<<16) | (buf[1]<<8) | buf[0]);
}

//spi 读取FPGA中的数据1024
static int fpga_read_scope(int addr, uint32_t *buf)
{
	int i;
#if DEBUG
	printf("fpga_read_scope addr=0x%x\n", addr);
#endif
	fpga_spi_status_ready();
	//while (fpga_spi_read_status() == 0);
	//printf("fpga_spi_read_status sucess\n");

	uint32_t status;
	
	i = 0;
	do{
		//fpga_spi_rewrite_addr();
		fpga_spi_write_addr(addr);
		fpga_spi_status_ready();
		status = fpga_spi_read_uint32();
		i++;
		printf("status 0x%x i=%d\n", status, i);
		if(i > 100)
		{
			printf("fpga_spi_status_ready error\n");
			return -1;
		}
	}while (!(status&0x1));
	
	debug_pos();
	for (i = 0; i < 1024; i ++){
		fpga_spi_write_addr(addr+4);
		fpga_spi_status_ready();
		buf[i] = fpga_spi_read_uint32_2();

		//printf("buf[%d]=0x%08x\n", i, buf[i]);
	}

	
	return 0;
}

//fft 算法

typedef struct COMPLEX_S{
	double re, im;
}Complex;

/*********************************/
void conjugate_complex(int n,Complex in[],Complex out[])
{  
	int i = 0;  
	for(i=0;i<n;i++)  
	{  
		out[i].im = -in[i].im;  
		out[i].re = in[i].re;  
	}   
}  

void c_abs(Complex f[],float out[],int n)  
{  
	int i = 0;  
	float t;  
	for(i=0;i<n;i++)  
	{  
		t = f[i].re * f[i].re + f[i].im * f[i].im;  
		out[i] = sqrt(t);  
	}   
}  

void c_plus(Complex a,Complex b,Complex *c)  
{  
	c->re = a.re + b.re;  
	c->im = a.im + b.im;  
}  

void c_sub(Complex a,Complex b,Complex *c)  
{  
	c->re = a.re - b.re;  
	c->im = a.im - b.im;   
}  

void c_mul(Complex a,Complex b,Complex *c)  
{  
	c->re = a.re * b.re - a.im * b.im;  
	c->im = a.re * b.im + a.im * b.re;     
}  

void c_div(Complex a,Complex b,Complex *c)  
{  
	c->re = (a.re * b.re + a.im * b.im)/(b.re * b.re +b.im * b.im);  
	c->im = (a.im * b.re - a.re * b.im)/(b.re * b.re +b.im * b.im);  
}  

#define SWAP(a,b)  tempr=(a);(a)=(b);(b)=tempr  

void Wn_i(int n,int i,Complex *Wn,char flag)  
{  
	Wn->re = cos(2*PI*i/n);  
	if(flag == 1)  
		Wn->im = -sin(2*PI*i/n);  
	else if(flag == 0)  
		Wn->im = -sin(2*PI*i/n);  
}  


void fft(int N,Complex f[])  
{  
	Complex t,wn;  
	int i,j,k,m,n,l,r,M;  
	int la,lb,lc;  
	/*----计算分解的级数M=log2(N)----*/  
	for(i=N,M=1;(i=i/2)!=1;M++);   
	/*----按照倒位序重新排列原信号----*/  
	for(i=1,j=N/2;i<=N-2;i++)  
	{  
		if(i<j)  
		{  
			t=f[j];  
			f[j]=f[i];  
			f[i]=t;  
		}  
		k=N/2;  
		while(k<=j)  
		{  
			j=j-k;  
			k=k/2;  
		}  
		j=j+k;  
	}  

	/*----FFT算法----*/  
	for(m=1;m<=M;m++)  
	{  
		la=pow(2,m);       
		lb=la/2;    

		/*----碟形运算----*/  
		for(l=1;l<=lb;l++)  
		{  
			r=(l-1)*pow(2,M-m);     
			for(n=l-1;n<N-1;n=n+la) 
			{  
				lc=n+lb;         
				Wn_i(N,r,&wn,1);  
				c_mul(f[lc],wn,&t); 
				c_sub(f[n],t,&(f[lc])); 
				c_plus(f[n],t,&(f[n]));  
			}  
		}  
	}  
}  


void ifft(int N,Complex f[])  
{  
	int i=0;  
	conjugate_complex(N,f,f);  
	fft(N,f);  
	conjugate_complex(N,f,f);  
	for(i=0;i<N;i++)  
	{  
		f[i].im = (f[i].im)/N;  
		f[i].re = (f[i].re)/N;  
	}  
} 
/*************************************/

int currentFrame = 0;
static double spi_fft(uint32_t *currentData)
{
	double spectrumAverage[RX_BUF_SIZE_DIV4] = {0.0f};
	double spectrumAverages[16][RX_BUF_SIZE_DIV4] = {0.0f};
	Complex jh[RX_BUF_SIZE_DIV4];
	//int currentData[RX_BUF_SIZE_DIV2] = {0};
	int hann_windowOn  = 1;
	int averagingFrameCount = 1024;
	double wind_hann[RX_BUF_SIZE_DIV4];


	int i;

#if 0
	srand(time(NULL));
	for (i = 0; i < RX_BUF_SIZE_DIV4; i+=2){
		//currentData[i] = (rand()%4096);
		currentData[i] = 4096.0 * cos(2.0*PI*i/1000.0);// (rand()%4096);
		currentData[i+1] = 4096.0 * sin(2.0*PI*i/1000.0);// (rand()%4096);


	//	printf("\t %d", currentData[i]);
	}
#endif
		
	for (i = 0; i < 1024; i ++) {
		jh[i].re = (currentData[i] & 0xffff);
		jh[i].im = ((currentData[i]>>16) & 0xffff);//currentData[i + 1];
		if( jh[i].re > pow(2,15)) jh[i].re -= pow(2,16);
		if( jh[i].im > pow(2,15)) jh[i].im -= pow(2,16);
	}

	for (i = 0; i < RX_BUF_SIZE_DIV4; i++) 
		wind_hann[i] = hann_windowOn ? 0.5  * (1 - cos((2 * 3.1415926535 * i) / (RX_BUF_SIZE_DIV4 - 1))) : 1.0;

	double koef_12bits = 1.0;
	for (i = 0; i < RX_BUF_SIZE_DIV4; i++) {
		jh[i].re = jh[i].re * koef_12bits * wind_hann[i];
		jh[i].im = jh[i].im * koef_12bits * wind_hann[i];
	}

	
#if 0
	printf("fft before:\n");
	for (i = 0; i < RX_BUF_SIZE_DIV4; i++)
		printf("\t %lf", jh[i]);
	printf("end\n\n");
#endif
	fft(1024, jh);
	
#if 0
	printf("fft after:\n");
	for (i = 0; i < RX_BUF_SIZE_DIV4; i++)
		printf("\t %lf", jh[i]);
	printf("end\n\n");
#endif

	for (i = 0; i < RX_BUF_SIZE_DIV4; i++)
		spectrumAverage[i] = 0.0f;

	for (i = 0; i < RX_BUF_SIZE_DIV8; i++) {
		double jooksev_m_sag = sqrt(jh[i + 512].re * jh[i + 512].re + jh[i + 512].im * jh[i + 512].im);
		double jooksev_p_sag = sqrt(jh[i].re * jh[i].re + jh[i].im * jh[i].im);
		spectrumAverage[i] += jooksev_m_sag - spectrumAverages[currentFrame][i];
		spectrumAverage[i + 512] += jooksev_p_sag - spectrumAverages[currentFrame][i + 512];
		//printf("\t spectrumAverage[%d]=%lf, spectrumAverage[%d]=%lf", i, spectrumAverage[i],i+512, spectrumAverage[i+512]);
		spectrumAverages[currentFrame][i] = jooksev_m_sag;
		spectrumAverages[currentFrame][i + 512] = jooksev_p_sag;
	}

	double sum = 0.0, y1 = 20.0 * log10(spectrumAverage[0] / averagingFrameCount);
	//if (!_finite(y1)) y1 = 0;
	for (i = 1; i < RX_BUF_SIZE_DIV4; i++) {
		double y = 20.0 * log10(spectrumAverage[i] / averagingFrameCount);
		//if (!_finite(y)) y = 0;
		y1 = y;
		sum += spectrumAverage[i] / averagingFrameCount;
	}

	double retv = 20.0 * log10(sum) - 101.6;
	printf("sum %f, retv %lf\n", sum, retv);
	return retv;
}
//fft 接收电平
double spi_fpga_rcv_fft1024_power(uint32_t *buf)
{
	int ret;
	
	ret = fpga_read_scope( 328, buf);
	if(ret < 0)
	{
		return -1;
	}
	else{
		return spi_fft(buf);
	}
}

//通信带宽计算 带宽为3.5 7 14 滚降系数为1.1666666 其余滚降系数为1.1200684
static double tx_symrate(uint32_t R08, uint32_t R10)
{
	uint32_t symrate = (R08 & 0xff);
	uint32_t symadjust = ((R10>>8) & 0xffffff);
	double roll_off_factor;
	if(symadjust == 335543)
	{
		roll_off_factor = 1.1666666;
	}else{
		roll_off_factor = 1.1200684;
	}
	
	double SR = (200.0f * symrate / 256.0f) * (pow(2,24)/(symadjust+pow(2,24)));
	return SR * roll_off_factor;	
}

static double rx_symrate(uint32_t R08, uint32_t R10)
{
	uint32_t symrate = (R08 & 0xff);
	uint32_t symadjust = ((R10>>8) & 0xffffff);
	double roll_off_factor;
	if(symadjust == 349524)
	{
		roll_off_factor = 1.1666666;
	}else{
		roll_off_factor = 1.1200684;
	}
	
	double SR = (200.0f * symrate / 256.0f) * (pow(2,24)/(symadjust+pow(2,24)));
	return SR * roll_off_factor;	
}

//调制类型
char *s_mod_index_arr[] = {"QAM256", "QAM128", "QAM1024", "QAM64", "QAM512", "QAM32", "", "QAM16", "", "QAM8", "", "", "", "QPSK", "", "AUTO"};
static char *r_mod_indx(uint32_t R08, uint32_t R04, uint32_t R0c)
{
	uint32_t mod_index;
	if(((R08 >> 8)&0x0f) == 15)
	{	
		mod_index = 15;
		//mod_index = ((R0c >> 0)&0xff);
	}else
	{
		mod_index = ((R08 >> 8)&0x0f);
	}
	return s_mod_index_arr[mod_index];
}


//传输速率

//int s_mod2M_arr[] = {8, 7, 10, 6, 9, 5, 0, 4, 0, 3, 0, 0, 0, 2, 0, 1};
int s_mod2M_arr[] = {8, 7, 10, 6, 9, 5, 0, 4, 0, 3, 0, 0, 0, 2, 0, 1};
static uint32_t r_mod2M(uint32_t R08, uint32_t R04, uint32_t R70c)
{
	uint32_t mod_index;
	if(((R08 >> 8)&0x0f) == 15)
	{	
		mod_index = ((R70c >> 0)&0xff);
	}else
	{
		mod_index = ((R08 >> 8)&0x0f);
	}
	return s_mod2M_arr[mod_index];
}

static double r_THR(uint32_t R08, uint32_t R0c, uint32_t R10, uint32_t R04, uint32_t R70c)
{
	uint32_t symrate = (R08 & 0xff);
	uint32_t symadjust = ((R10>>8) & 0xffffff);
	uint32_t fec_cw_len = (R0c & 0xff);
	uint32_t fec_pl_len = ((R0c>>8) & 0xff);
	uint32_t wayside_len = ((R08>>24) & 0xff);
	uint32_t mod_index = r_mod2M(R08, R04, R70c);

	//printf("symrate=0x%x symadjust=0x%x fec_cw_len=0x%x fec_pl_len=0x%x wayside_len=0x%x mod_index=0x%x\n", symrate, symadjust, fec_cw_len, fec_pl_len, wayside_len, mod_index);
	double SR = (200.0f * symrate / 256.0f) * (pow(2,24)/(symadjust+pow(2,24)));
	double AFE = 16.0f*fec_cw_len/(23.0f+2*wayside_len+16.0f*fec_cw_len);
	double CR = (double)fec_pl_len/(double)fec_cw_len;
	double THR = SR * AFE * CR * (double) mod_index;
	//printf("SR=%f AFE=%f CR=%f THR=%f\n", SR, AFE, CR, THR);
	
	return THR;
}

//符号速率 Symbol_rate
static double Symbol_rate(uint32_t R08, uint32_t R10)
{
	uint32_t symrate = (R08 & 0xff);
	uint32_t symadjust = ((R10>>8) & 0xffffff);
	
	double SR = (200.0f * symrate / 256.0f) * (pow(2,24)/(symadjust+pow(2,24)));
	return SR;
}
//交织深度Interleavel
static uint32_t r_ilv_depth(uint32_t data)
{
	return ((data>>16)&0xff);
}

//编码速率 Code rate
static uint32_t r_fec_cw_len(uint32_t data)
{
	return ((data)&0xff);
}

static uint32_t r_fec_pl_len(uint32_t data)
{
	return ((data>>8)&0xff);
}

//杂散Distortion
static uint32_t r_Distortion_AMAM(uint32_t data)
{
	return (data&0xff);
}
static uint32_t r_Distortion_AMAP(uint32_t data)
{
	return ((data>>16)&0xff);
}

//数字自回环Digital Loopback 读取寄存器rx_digital_loop_ena
char *Loopback[] = { "Digital_Loopback=0", "Digital_Loopback=1"};
static char *Digital_LoopbackM(uint32_t data)
{
	uint32_t digital_Loopback= ((data)&0x01);
	return Loopback[digital_Loopback];
}

//增益值DA的数值
int get_DA()
{
	int wdata;
	char buf[128]={0};
	char Dagain[4]={0};
	
	FILE *fp;
	
	if((fp = fopen("config.txt","r+"))==NULL)//打开文件，之后判断是否打开成功
	{
		perror("cannot open file");
		exit(0);
	}
	while(fgets(buf,128,fp)!=NULL)
	{

		if(buf[0] == '5')
		{
			bzero(Dagain,3);
			Dagain[0] = buf[9];
			Dagain[1] = buf[10];
			Dagain[2] = buf[11];
			Dagain[3] = buf[12];			
			wdata = atoi( Dagain);
			printf("buf=%s wdata=%d\n", buf, wdata);
		}
	}
	fclose(fp);
	return wdata;
}
//level的值
int get_AD()
{
	int wdata;
	char buf[128]={0};
	char Adgain[4]={0};
	
	FILE *fp;
	
	if((fp = fopen("config.txt","r+"))==NULL)//打开文件，之后判断是否打开成功
	{
		perror("cannot open file");
		exit(0);
	}
	while(fgets(buf,128,fp)!=NULL)
	{

		if(buf[0] == '6')
		{
			bzero(Adgain,3);
			Adgain[0] = buf[9];
			Adgain[1] = buf[10];
			Adgain[2] = buf[11];
			Adgain[3] = buf[12];			
			wdata = atoi( Adgain);
			printf("buf=%s wdata=%d\n", buf, wdata);
		}
		bzero(buf,128);
	}
	fclose(fp);
	return wdata;
}

//微波高低栈的编号
int get_WB()
{
	int wdata;
	char buf[128]={0};
	char WB_mode[4]={0};
	
	FILE *fp;
	
	if((fp = fopen("config.txt","r+"))==NULL)//打开文件，之后判断是否打开成功
	{
		perror("cannot open file");
		exit(0);
	}
	while(fgets(buf,128,fp)!=NULL)
	{

		if(buf[0] == '7')
		{
			bzero(WB_mode,3);
			WB_mode[0] = buf[9];
			WB_mode[1] = buf[10];
			WB_mode[2] = buf[11];
			WB_mode[3] = buf[12];			
			wdata = atoi( WB_mode);
			printf("buf=%s wdata=%d\n", buf, wdata);
		}
		bzero(buf,128);
	}
	fclose(fp);
	return wdata;
}

//误码率
static uint32_t uncoded_ber(uint32_t data)
{
	return ((data>>16)&0xff);
}
static uint32_t coded_ber(uint32_t data)
{
	return ((data>>16)&0xff);
}
static uint32_t cumulative_be(uint32_t data)
{
	return ((data>>16)&0xff);
}

//获取版本号
static uint32_t r_ver_minor(uint32_t data)
{
	return (data&0x0f);
}


static uint32_t r_ver_major(uint32_t data)
{
	return ((data>>8)&0x0f);
}

//获取本地MAC IP 时间
int systemx(char *result, int size, const char *format, ...)
{
    int ret;
    char cmd[1024] = {0};
    
    va_list args;   
    va_start(args, format);
    ret = vsnprintf(cmd, 1024, format, args);
    va_end (args);
    
    //printf("system_p cmd: %s\n", cmd);
	if (ret < 0 || ret >= 1024){ printf("vsnprintf failed, cmd %s.\n", cmd); return -1;};
	
	FILE * fp;
	if ((fp = popen(cmd, "r")) == NULL)	return -1;
	if (result && size > 0)
	{ 
		int ret = fread(result, 1, size, fp);
		if (ret == size) ret -= 1; 
		*(result + ret) = '\0';
	};
	
	return pclose(fp);
}

int get_eth0_IP(char *buf, int buf_size)
{
	return systemx(buf, buf_size, "ifconfig eth0 | grep \"inet addr\" | awk '{ print $2}' | awk -F: '{print $2}' | xargs echo -n");
}

int get_eth0_MAC(char *buf, int buf_size)
{
	return systemx(buf, buf_size, "ifconfig eth0 | grep \"HWaddr\" | awk '{ print $5}' | xargs echo -n");
}

int get_uptime(char *buf, int buf_size)
{
	return systemx(buf, buf_size, "cat /proc/uptime | awk '{ print $1}'");
}

int get_uptime_str(char *buf, int len)
{
	char uptime_buf[32] = {0};
	get_uptime(uptime_buf, 30);

	int uptime_secs = atoi(uptime_buf);
	int nday = uptime_secs/(3600*24);
	uptime_secs %= (3600*24);
	int HH = uptime_secs/(3600);
	uptime_secs %= (3600);
	int MM = uptime_secs/(60);
	uptime_secs %= (60);
	int SS = uptime_secs;
	if (nday > 0)
		snprintf(buf, len, "%d天 %02d:%02d:%02d", nday, HH, MM, SS);  
	else
		snprintf(buf, len, "%02d:%02d:%02d", HH, MM, SS);  

	return 0;
}

int get_ip_mac(char *buf, int len)
{
	char IP[32] = {0};	
	char MAC[32] = {0};	
	get_eth0_IP(IP, 30);
	get_eth0_MAC(MAC, 30);

	snprintf(buf, len, "IP=%s, MAC=%s", IP, MAC);
	return 0;
}

int runinfo(char *buf, int len)
{
	char uptime_buf[32] = {0};
	get_uptime_str(uptime_buf, 30);

	snprintf(buf, len, "status=0, uptime=%s", uptime_buf);
	return 0;
}

int read_stonmsg(char *buf_stationmsg, int len)
{
	FILE *fpston;
	char stonbuf[256] = {0};
	char buf_number[64] = {0};
	char buf_name[64] = {0};
	char buf_longitude[64] = {0};
	char buf_atitude[64] = {0};
	
	if((fpston = fopen("stationmsg.txt","r+"))==NULL)//打开文件，之后判断是否打开成功
	{
		perror("cannot open file");
		exit(0);
	}
	while(fgets( stonbuf, 256, fpston) != NULL)
	{
		if(stonbuf[1] == 'u')
		{
			strcpy(buf_number, stonbuf);
		}
		if(stonbuf[1] == 'a')
		{
			strcpy(buf_name, stonbuf);
		}
		if(stonbuf[1] == 'o')
		{
			strcpy(buf_longitude, stonbuf);
		}
		if(stonbuf[1] == 't')
		{
			strcpy(buf_atitude, stonbuf);
		}
		bzero(stonbuf,256);
	}
	buf_number[strlen(buf_number)-1] = '\0';
	buf_name[strlen(buf_name)-1] = '\0';
	buf_longitude[strlen(buf_longitude)-1] = '\0';
	buf_atitude[strlen(buf_atitude)-1] = '\0';
	snprintf( buf_stationmsg, len, "%s,%s,%s,%s", buf_number, buf_name, buf_longitude, buf_atitude);
	
	fclose(fpston);
	return 0;
}

int get_date(char *date, int len)
{
	time_t timep;
	time (&timep);
	snprintf( date, len, "%s", ctime(&timep));
	date[strlen(date)-1] = '\0';
	return 0;
}

double get_temperature()  
{  
  
    int fdWB, res, i;  
    struct termios  oldtio, newtio;  
    char buf[256] = {0}; 
	double tem;
	char t[4];
//-----------打开uart设备文件------------------  
    fdWB = open(UART_DEVICE, O_RDWR|O_NOCTTY);
    if (fdWB < 0) {  
        perror(UART_DEVICE);  
        exit(-1);  
    }  
    else  
        printf("Open %s successfully\n", UART_DEVICE);  

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

//-------------从uart接收数据-------------------  	
	for(i = 0; i < 100000; i++)
	{
		res = read( fdWB, buf, 255);//程序将在这里挂起，直到从uart接收到数据（阻塞操作）  
		if (res == 0)   
			continue;  
		
		printf("%s\n", buf);//将uart接收到的字符打印出来  
		// if (buf[0] == '!')//uart接收到！字符后退出while  
			// break;  
		if (buf[0] == 'p') //p 高低栈pin脚的值  1-high  0-low
			pin = buf[1];
		if (buf[0] == 'l') //l 锁pin脚的值 1-lock 0-unlock
			lock = buf[1];
		if (buf[0] == 't') //t temperature温度值 
		{
			t[0] = buf[1];
			t[1] = buf[2];
			t[2] = buf[3];
			t[3] = buf[4];
			tem = (double)atoi(t) / 100;
		}
		printf("p=%c l=%c tem=%4.2f\n", pin, lock, tem);
	}
//------------关闭uart设备文件，恢复原先参数--------  
    close(fdWB);  
    printf("Close %s\n", UART_DEVICE);  
    tcsetattr(fdWB, TCSANOW, &oldtio); //恢复原先的设置  
  
    return tem;  
}

void pthread_spi(void *arg)
{
    int ret, i;
	char msg[MSGSIZE] = {0};
	char msg_AD[1024] = {0};
	char netbuf[128] = {0};
	char timebuf[128] = {0};
	char stonmsg[256] = {0};
	char datebuf[128] = {0};
	
	int sockfd = *((int *)arg);
	
	uint32_t buf[1024] = {0};
	char TLevelbuf[1024*10] = {0};
	double fft1024_power;
	double tlevel_avg[5];
	double avg_sum;
	flag = 0;
	flag1 = 0;
	flag2 = 0;
	flag3 = 0;
	flag4 = 0;
	
    fdFpga = open(device, O_RDWR);
    if (fdFpga < 0)
        pabort("can't open device");
	printf("fdFpga = %d\n",fdFpga);
    /*
     * spi mode
     */
    ret = ioctl(fdFpga, SPI_IOC_WR_MODE, &mode);
    if (ret == -1)
        pabort("can't set spi mode");

    ret = ioctl(fdFpga, SPI_IOC_RD_MODE, &mode);
    if (ret == -1)
        pabort("can't get spi mode");

    /*
     * bits per word
     */
    ret = ioctl(fdFpga, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't set bits per word");

    ret = ioctl(fdFpga, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't get bits per word");

    /*
     * max speed hz
     */
    ret = ioctl(fdFpga, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't set max speed hz");

    ret = ioctl(fdFpga, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't get max speed hz");

    printf("spi mode: %d\n", mode);
    printf("bits per word: %d\n", bits);
    printf("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
	
	//读取配置文件获得增益、LEVEL、高低栈编号
	da_data = get_DA();
	ad_data = get_AD();
	wb_data = get_WB();
	get_temperature();
	while(1)
	{
		usleep(1000);
		if(flag)
		{
			printf("__FILE__=%s __FUNCTION__=%s __LINE__=%d __DATE__=%s __TIME__=%s\n", __FILE__, __FUNCTION__, __LINE__, __DATE__, __TIME__);		
			
			close(fdFpga);
			printf("pthread_spi close\n");
			return;
		}	
		
		if(flag1 || flag2 || flag3 || flag4)
		{
			sockfd = static_socket;
			//IP MAC TIME
			get_ip_mac(netbuf, 100);
			runinfo(timebuf, 100);
			read_stonmsg(stonmsg, 256);
			get_date(datebuf, 100);
			
			//寄存器的设定
			uint32_t R0 = fpga_read_uint32(0);
			uint32_t R4008 = fpga_read_uint32(0x4008);
			uint32_t R400c = fpga_read_uint32(0x400c);
			uint32_t R4010 = fpga_read_uint32(0x4010);
			uint32_t R4108 = fpga_read_uint32(0x4108);
			uint32_t R410c = fpga_read_uint32(0x410c);
			uint32_t R4110 = fpga_read_uint32(0x4110);
			uint32_t R414c = fpga_read_uint32(0x414c);
			uint32_t R4150 = fpga_read_uint32(0x4150); 
			
			uint32_t R4138 = fpga_read_uint32(0x4138); 
			uint32_t R4148 = fpga_read_uint32(0x4148);
			uint32_t R413c = fpga_read_uint32(0x413c);

			uint32_t R7004 = fpga_read_uint32(0x7004);
			uint32_t R700c = fpga_read_uint32(0x700c);
			
			uint32_t R4164 = fpga_read_uint32(0x4164);
			
			//传输速率
			double sndTHR,rcvTHR;
			sndTHR = r_THR(R4008, R400c, R4010, R7004, R700c);
			rcvTHR = r_THR(R4108, R410c, R4110, R7004, R700c);
			
			memset(tlevel_avg,0,5);
			memset(msg_AD, 0, 1024);	
			if(flag1) //status
			{
				//读取电平速率
				avg_sum = 0;
				for(i = 0; i < 4; i++)
				{
					tlevel_avg[i] = tlevel_avg[i+1];
				}
				fft1024_power = spi_fpga_rcv_fft1024_power(buf);
				if(fft1024_power == -1)
				{
					memset(msg_AD, 0, 1024);
					sprintf( msg_AD, "电平速率获取失败，spi状态无法就绪。ret = %d", fft1024_power);
					send( sockfd, msg_AD, 1024, 0);
				}
				else{
					tlevel_avg[4] = fft1024_power;
					for(i = 0; i < 5; i++)
					{
						avg_sum += tlevel_avg[i];
					}
					fft1024_power = avg_sum/5;
					
					memset(msg_AD, 0, 1024);
					sprintf( msg_AD, "serverip:%s,%s,version=%d.%d_1.01.02,%s,%s;snd:TLevel=0.0 dBm,NBWidth=%.1f MHz,MType=%s, Symbol_rate=%.2f Mbd, Data_rate=%.2f Mbp/s, Ilv_depth=%d, Code_rate=%d/%d;rev:TLevel=%.2f dBm,NBWidth=%.1f MHz,MType=%s, Symbol_rate=%.2f Mbd, NSpeed=%.2f Mbp/s, Ilv_depth=%d, Code_rate=%d/%d, Distor_AMAM=%d, Distor_AMAP=%d, %s, Data_source=%d, DA_data=%d, AD_data=%d, bert_uncoded=%d, bert_coded=%d %d, mse_avg=%d, WB_data=%d;", 
						netbuf, timebuf, r_ver_major(R0), r_ver_minor(R0), stonmsg, datebuf, tx_symrate(R4008, R4010), r_mod_indx( R4008, R7004, R700c), Symbol_rate( R4008, R4010), sndTHR, r_ilv_depth(R4008), r_fec_cw_len(R400c), r_fec_pl_len(R400c), fft1024_power, rx_symrate(R4108, R4110), r_mod_indx( R4108, R7004, R700c), Symbol_rate( R4108, R4110), rcvTHR, r_ilv_depth(R4108), r_fec_pl_len(R400c), r_fec_cw_len(R400c), r_Distortion_AMAM(R4138), r_Distortion_AMAP(R4138), Digital_LoopbackM(R4148), rReg("tx_dbg_bert_ena"), da_data, ad_data, R414c, R4150, R4164, R413c, wb_data);

					if((ret = send( sockfd, msg_AD, 1024, 0)) <= 0)
					{
						close(fdFpga);
						return;
					}
					//printf("%s\n",msg_AD);
					printf("***send status msg_AD success!\n");
				}
			}
			
			if(flag2) //网卡
			{
				sleep(1);
				//ethn网络
				//subsystem
				//ethn_version=0.0, rx_buffer_size=65536, tx_buffer_size=16384, local_loopback_enable=0, loop_data_enable_override=0, xon_threshold=8000
				printf("ethn_version=%d.%d, rx_buffer_size=%d, tx_buffer_size=%d, local_loopback_enable=%d, loop_data_enable_override=%d, xon_threshold=%d\n",
					rReg("tdm_ver_major"), rReg("tdm_ver_minor"), rReg("eth_rx_fifo_len"), rReg("eth_tx_fifo_len"), rReg("eth_eth_local_loopback"), rReg("eth_eth_lb_ena_override"), rReg("eth_xon_thres"));
				
				//xoff_threshold=22000, xoff_rerequeset_timer=20, pause_quanta=32768, rx_packets_detected=0, rx_packets_dropped=0, tx_packets_detected=0, tx_packets_dropped=0
				printf("xoff_threshold=%d, xoff_rerequeset_timer=%d, pause_quanta=%d, rx_packets_detected=%d, rx_packets_dropped=%d, tx_packets_detected=%d, tx_packets_dropped=%d\n",
					rReg("eth_xoff_thres"), rReg("eth_xoff_timeout"), rReg("eth_pause_quanta"), rReg("eth_rx_detected"), rReg("eth_rx_dropped"), rReg("eth_tx_detected"), rReg("eth_tx_dropped"));
				
				//mac
				//mac_version=3.0, jumbo_frame_enable=0/0, vlan_enbale=0/0
				printf("mac_version=%d.%d, jumbo_frame_enable=%d/%d, vlan_enbale=%d/%d\n",
					rReg("eth_ver_major"), rReg("eth_ver_minor"), rReg("tme_conf_rx_jumbo_enable"), rReg("tme_conf_tx_jumbo_enable"), rReg("tme_conf_rx_vlan_enable"), rReg("tme_conf_tx_vlan_enable"));
				//rx_flow_control_enable=1, tx_flow_control_enable=1, max_frame_enable=0/0, max_frame_size=2000/2000
				printf("rx_flow_control_enable=%d, tx_flow_control_enable=%d, max_frame_enable=%d/%d, max_frame_size=%d/%d\n",
					rReg("tme_conf_rx_flow_cntrl_ena"), rReg("tme_conf_tx_flow_cntrl_ena"), rReg("tme_conf_rx_max_frame_ena"), rReg("tme_conf_tx_max_frame_ena"), rReg("tme_conf_rx_max_frame"), rReg("tme_conf_tx_max_frame"));
				//rx_bytes=0, rx_good_frames=0, rx_crc_errors=0, rx_length_errors=0, rx_pause_frames=0	
				printf("rx_bytes=%d, rx_good_frames=%d, rx_crc_errors=%d, rx_length_errors=%d, rx_pause_frames=%d\n",
					rReg("tme_stat_rx_bytes"), rReg("tme_stat_rx_good_frames"), rReg("tme_stat_rx_crc_errors"), rReg("tme_stat_rx_len_errors"), rReg("tme_stat_rx_pause_frames"));	
				//tx_bytes=0, tx_good_frames=0, tx_crc_errors=-1, tx_length_errors=-1, tx_pause_frames=-1	
				printf("tx_bytes=%d, tx_good_frames=%d, tx_crc_errors=%d, tx_length_errors=%d, tx_pause_frames=%d\n",
					rReg("tme_stat_tx_bytes"), rReg("tme_stat_tx_good_frames"), rReg("tme_stat_tx_crc_errors"), rReg("tme_stat_tx_len_errors"), rReg("tme_stat_tx_pause_frames"));
				
				memset(msg_AD, 0, 1024);
				sprintf( msg_AD, "ethn_version=%d.%d, rx_buffer_size=%d, tx_buffer_size=%d, local_loopback_enable=%d, loop_data_enable_override=%d, xon_threshold=%d, xoff_threshold=%d, xoff_rerequeset_timer=%d, pause_quanta=%d, rx_packets_detected=%d, rx_packets_dropped=%d, tx_packets_detected=%d, tx_packets_dropped=%d, mac_version=%d.%d, jumbo_frame_enable=%d/%d, vlan_enbale=%d/%d, rx_flow_control_enable=%d, tx_flow_control_enable=%d, max_frame_enable=%d/%d, max_frame_size=%d/%d, rx_bytes=%d, rx_good_frames=%d, rx_crc_errors=%d, rx_length_errors=%d, rx_pause_frames=%d, tx_bytes=%d, tx_good_frames=%d, tx_urun_errors =%d, tx_pause_frames=%d;", 
					rReg("tdm_ver_major"), rReg("tdm_ver_minor"), rReg("eth_rx_fifo_len"), rReg("eth_tx_fifo_len"), rReg("eth_eth_local_loopback"), rReg("eth_eth_lb_ena_override"), rReg("eth_xon_thres"), rReg("eth_xoff_thres"), rReg("eth_xoff_timeout"), rReg("eth_pause_quanta"), rReg("eth_rx_detected"), rReg("eth_rx_dropped"), rReg("eth_tx_detected"), rReg("eth_tx_dropped"), rReg("eth_ver_major"), rReg("eth_ver_minor"), rReg("tme_conf_rx_jumbo_enable"), rReg("tme_conf_tx_jumbo_enable"), rReg("tme_conf_rx_vlan_enable"), rReg("tme_conf_tx_vlan_enable"), rReg("tme_conf_rx_flow_cntrl_ena"), rReg("tme_conf_tx_flow_cntrl_ena"), rReg("tme_conf_rx_max_frame_ena"), rReg("tme_conf_tx_max_frame_ena"), rReg("tme_conf_rx_max_frame"), rReg("tme_conf_tx_max_frame"), rReg("tme_stat_rx_bytes"), rReg("tme_stat_rx_good_frames"), rReg("tme_stat_rx_crc_errors"), rReg("tme_stat_rx_len_errors"), rReg("tme_stat_rx_pause_frames"), rReg("tme_stat_tx_bytes"), rReg("tme_stat_tx_good_frames"), rReg("tme_stat_tx_urun_errors"), rReg("tme_stat_tx_pause_frames"));
#if DEBUG
				printf("%s\n",msg_AD);
				printf("========sockfd = %d======\n", sockfd);
#endif
				if((ret = send( sockfd, msg_AD, 1024, 0)) <= 0)
				{
					close(fdFpga);
					return;
				}
				
				printf("***send network msg_AD success!\n");
				
			}
			
			
			if(flag3)
			{
				//AD频谱采样
				ret = fpga_read_scope( 328, buf);
				if(ret < 0)
				{
					memset(msg, 0, MSGSIZE);
					sprintf( msg, "AD频谱采样获取失败，spi状态无法就绪。ret = %d", ret);
					send( sockfd, msg, MSGSIZE, 0);
				}
				else{
					sprintf( TLevelbuf, "0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x",	
						buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9],
						buf[10],buf[11],buf[12],buf[13],buf[14],buf[15],buf[16],buf[17],buf[18],buf[19],buf[20],buf[21],buf[22],buf[23],buf[24],buf[25],buf[26],buf[27],buf[28],buf[29],buf[30],buf[31],buf[32],buf[33],buf[34],buf[35],buf[36],buf[37],buf[38],buf[39],buf[40],buf[41],buf[42],buf[43],buf[44],buf[45],buf[46],buf[47],buf[48],buf[49],buf[50],buf[51],buf[52],buf[53],buf[54],buf[55],buf[56],buf[57],buf[58],buf[59],buf[60],buf[61],buf[62],buf[63],buf[64],buf[65],buf[66],buf[67],buf[68],buf[69],buf[70],buf[71],buf[72],buf[73],buf[74],buf[75],buf[76],buf[77],buf[78],buf[79],buf[80],buf[81],buf[82],buf[83],buf[84],buf[85],buf[86],buf[87],buf[88],buf[89],buf[90],buf[91],buf[92],buf[93],buf[94],buf[95],buf[96],buf[97],buf[98],buf[99],
						buf[100],buf[101],buf[102],buf[103],buf[104],buf[105],buf[106],buf[107],buf[108],buf[109],buf[110],buf[111],buf[112],buf[113],buf[114],buf[115],buf[116],buf[117],buf[118],buf[119],buf[120],buf[121],buf[122],buf[123],buf[124],buf[125],buf[126],buf[127],buf[128],buf[129],buf[130],buf[131],buf[132],buf[133],buf[134],buf[135],buf[136],buf[137],buf[138],buf[139],buf[140],buf[141],buf[142],buf[143],buf[144],buf[145],buf[146],buf[147],buf[148],buf[149],buf[150],buf[151],buf[152],buf[153],buf[154],buf[155],buf[156],buf[157],buf[158],buf[159],buf[160],buf[161],buf[162],buf[163],buf[164],buf[165],buf[166],buf[167],buf[168],buf[169],buf[170],buf[171],buf[172],buf[173],buf[174],buf[175],buf[176],buf[177],buf[178],buf[179],buf[180],buf[181],buf[182],buf[183],buf[184],buf[185],buf[186],buf[187],buf[188],buf[189],buf[190],buf[191],buf[192],buf[193],buf[194],buf[195],buf[196],buf[197],buf[198],buf[199],
						buf[200],buf[201],buf[202],buf[203],buf[204],buf[205],buf[206],buf[207],buf[208],buf[209],buf[210],buf[211],buf[212],buf[213],buf[214],buf[215],buf[216],buf[217],buf[218],buf[219],buf[220],buf[221],buf[222],buf[223],buf[224],buf[225],buf[226],buf[227],buf[228],buf[229],buf[230],buf[231],buf[232],buf[233],buf[234],buf[235],buf[236],buf[237],buf[238],buf[239],buf[240],buf[241],buf[242],buf[243],buf[244],buf[245],buf[246],buf[247],buf[248],buf[249],buf[250],buf[251],buf[252],buf[253],buf[254],buf[255],buf[256],buf[257],buf[258],buf[259],buf[260],buf[261],buf[262],buf[263],buf[264],buf[265],buf[266],buf[267],buf[268],buf[269],buf[270],buf[271],buf[272],buf[273],buf[274],buf[275],buf[276],buf[277],buf[278],buf[279],buf[280],buf[281],buf[282],buf[283],buf[284],buf[285],buf[286],buf[287],buf[288],buf[289],buf[290],buf[291],buf[292],buf[293],buf[294],buf[295],buf[296],buf[297],buf[298],buf[299],
						buf[300],buf[301],buf[302],buf[303],buf[304],buf[305],buf[306],buf[307],buf[308],buf[309],buf[310],buf[311],buf[312],buf[313],buf[314],buf[315],buf[316],buf[317],buf[318],buf[319],buf[320],buf[321],buf[322],buf[323],buf[324],buf[325],buf[326],buf[327],buf[328],buf[329],buf[330],buf[331],buf[332],buf[333],buf[334],buf[335],buf[336],buf[337],buf[338],buf[339],buf[340],buf[341],buf[342],buf[343],buf[344],buf[345],buf[346],buf[347],buf[348],buf[349],buf[350],buf[351],buf[352],buf[353],buf[354],buf[355],buf[356],buf[357],buf[358],buf[359],buf[360],buf[361],buf[362],buf[363],buf[364],buf[365],buf[366],buf[367],buf[368],buf[369],buf[370],buf[371],buf[372],buf[373],buf[374],buf[375],buf[376],buf[377],buf[378],buf[379],buf[380],buf[381],buf[382],buf[383],buf[384],buf[385],buf[386],buf[387],buf[388],buf[389],buf[390],buf[391],buf[392],buf[393],buf[394],buf[395],buf[396],buf[397],buf[398],buf[399],
						buf[400],buf[401],buf[402],buf[403],buf[404],buf[405],buf[406],buf[407],buf[408],buf[409],buf[410],buf[411],buf[412],buf[413],buf[414],buf[415],buf[416],buf[417],buf[418],buf[419],buf[420],buf[421],buf[422],buf[423],buf[424],buf[425],buf[426],buf[427],buf[428],buf[429],buf[430],buf[431],buf[432],buf[433],buf[434],buf[435],buf[436],buf[437],buf[438],buf[439],buf[440],buf[441],buf[442],buf[443],buf[444],buf[445],buf[446],buf[447],buf[448],buf[449],buf[450],buf[451],buf[452],buf[453],buf[454],buf[455],buf[456],buf[457],buf[458],buf[459],buf[460],buf[461],buf[462],buf[463],buf[464],buf[465],buf[466],buf[467],buf[468],buf[469],buf[470],buf[471],buf[472],buf[473],buf[474],buf[475],buf[476],buf[477],buf[478],buf[479],buf[480],buf[481],buf[482],buf[483],buf[484],buf[485],buf[486],buf[487],buf[488],buf[489],buf[490],buf[491],buf[492],buf[493],buf[494],buf[495],buf[496],buf[497],buf[498],buf[499],
						buf[500],buf[501],buf[502],buf[503],buf[504],buf[505],buf[506],buf[507],buf[508],buf[509],buf[510],buf[511],buf[512],buf[513],buf[514],buf[515],buf[516],buf[517],buf[518],buf[519],buf[520],buf[521],buf[522],buf[523],buf[524],buf[525],buf[526],buf[527],buf[528],buf[529],buf[530],buf[531],buf[532],buf[533],buf[534],buf[535],buf[536],buf[537],buf[538],buf[539],buf[540],buf[541],buf[542],buf[543],buf[544],buf[545],buf[546],buf[547],buf[548],buf[549],buf[550],buf[551],buf[552],buf[553],buf[554],buf[555],buf[556],buf[557],buf[558],buf[559],buf[560],buf[561],buf[562],buf[563],buf[564],buf[565],buf[566],buf[567],buf[568],buf[569],buf[570],buf[571],buf[572],buf[573],buf[574],buf[575],buf[576],buf[577],buf[578],buf[579],buf[580],buf[581],buf[582],buf[583],buf[584],buf[585],buf[586],buf[587],buf[588],buf[589],buf[590],buf[591],buf[592],buf[593],buf[594],buf[595],buf[596],buf[597],buf[598],buf[599],
						buf[600],buf[601],buf[602],buf[603],buf[604],buf[605],buf[606],buf[607],buf[608],buf[609],buf[610],buf[611],buf[612],buf[613],buf[614],buf[615],buf[616],buf[617],buf[618],buf[619],buf[620],buf[621],buf[622],buf[623],buf[624],buf[625],buf[626],buf[627],buf[628],buf[629],buf[630],buf[631],buf[632],buf[633],buf[634],buf[635],buf[636],buf[637],buf[638],buf[639],buf[640],buf[641],buf[642],buf[643],buf[644],buf[645],buf[646],buf[647],buf[648],buf[649],buf[650],buf[651],buf[652],buf[653],buf[654],buf[655],buf[656],buf[657],buf[658],buf[659],buf[660],buf[661],buf[662],buf[663],buf[664],buf[665],buf[666],buf[667],buf[668],buf[669],buf[670],buf[671],buf[672],buf[673],buf[674],buf[675],buf[676],buf[677],buf[678],buf[679],buf[680],buf[681],buf[682],buf[683],buf[684],buf[685],buf[686],buf[687],buf[688],buf[689],buf[690],buf[691],buf[692],buf[693],buf[694],buf[695],buf[696],buf[697],buf[698],buf[699],
						buf[700],buf[701],buf[702],buf[703],buf[704],buf[705],buf[706],buf[707],buf[708],buf[709],buf[710],buf[711],buf[712],buf[713],buf[714],buf[715],buf[716],buf[717],buf[718],buf[719],buf[720],buf[721],buf[722],buf[723],buf[724],buf[725],buf[726],buf[727],buf[728],buf[729],buf[730],buf[731],buf[732],buf[733],buf[734],buf[735],buf[736],buf[737],buf[738],buf[739],buf[740],buf[741],buf[742],buf[743],buf[744],buf[745],buf[746],buf[747],buf[748],buf[749],buf[750],buf[751],buf[752],buf[753],buf[754],buf[755],buf[756],buf[757],buf[758],buf[759],buf[760],buf[761],buf[762],buf[763],buf[764],buf[765],buf[766],buf[767],buf[768],buf[769],buf[770],buf[771],buf[772],buf[773],buf[774],buf[775],buf[776],buf[777],buf[778],buf[779],buf[780],buf[781],buf[782],buf[783],buf[784],buf[785],buf[786],buf[787],buf[788],buf[789],buf[790],buf[791],buf[792],buf[793],buf[794],buf[795],buf[796],buf[797],buf[798],buf[799],
						buf[800],buf[801],buf[802],buf[803],buf[804],buf[805],buf[806],buf[807],buf[808],buf[809],buf[810],buf[811],buf[812],buf[813],buf[814],buf[815],buf[816],buf[817],buf[818],buf[819],buf[820],buf[821],buf[822],buf[823],buf[824],buf[825],buf[826],buf[827],buf[828],buf[829],buf[830],buf[831],buf[832],buf[833],buf[834],buf[835],buf[836],buf[837],buf[838],buf[839],buf[840],buf[841],buf[842],buf[843],buf[844],buf[845],buf[846],buf[847],buf[848],buf[849],buf[850],buf[851],buf[852],buf[853],buf[854],buf[855],buf[856],buf[857],buf[858],buf[859],buf[860],buf[861],buf[862],buf[863],buf[864],buf[865],buf[866],buf[867],buf[868],buf[869],buf[870],buf[871],buf[872],buf[873],buf[874],buf[875],buf[876],buf[877],buf[878],buf[879],buf[880],buf[881],buf[882],buf[883],buf[884],buf[885],buf[886],buf[887],buf[888],buf[889],buf[890],buf[891],buf[892],buf[893],buf[894],buf[895],buf[896],buf[897],buf[898],buf[899],
						buf[900],buf[901],buf[902],buf[903],buf[904],buf[905],buf[906],buf[907],buf[908],buf[909],buf[910],buf[911],buf[912],buf[913],buf[914],buf[915],buf[916],buf[917],buf[918],buf[919],buf[920],buf[921],buf[922],buf[923],buf[924],buf[925],buf[926],buf[927],buf[928],buf[929],buf[930],buf[931],buf[932],buf[933],buf[934],buf[935],buf[936],buf[937],buf[938],buf[939],buf[940],buf[941],buf[942],buf[943],buf[944],buf[945],buf[946],buf[947],buf[948],buf[949],buf[950],buf[951],buf[952],buf[953],buf[954],buf[955],buf[956],buf[957],buf[958],buf[959],buf[960],buf[961],buf[962],buf[963],buf[964],buf[965],buf[966],buf[967],buf[968],buf[969],buf[970],buf[971],buf[972],buf[973],buf[974],buf[975],buf[976],buf[977],buf[978],buf[979],buf[980],buf[981],buf[982],buf[983],buf[984],buf[985],buf[986],buf[987],buf[988],buf[989],buf[990],buf[991],buf[992],buf[993],buf[994],buf[995],buf[996],buf[997],buf[998],buf[999],
						buf[1000],buf[1001],buf[1002],buf[1003],buf[1004],buf[1005],buf[1006],buf[1007],buf[1008],buf[1009],buf[1010],buf[1011],buf[1012],buf[1013],buf[1014],buf[1015],buf[1016],buf[1017],buf[1018],buf[1019],buf[1020],buf[1021],buf[1022],buf[1023]
						);
				
					fft1024_power = 0;
					memset(msg, 0, MSGSIZE);
					sprintf( msg, "%s;serverip:%s,%s,version=%d.%d_1.01.02;snd:TLevel=0.0 dBm,NBWidth=%.1f MHz,MType=%s, Symbol_rate=%.2f Mbd, Data_rate=%.2f Mbp/s, Ilv_depth=%d, Code_rate=%d/%d;rev:TLevel=%.2f dBm,NBWidth=%.1f MHz,MType=%s, Symbol_rate=%.2f Mbd, NSpeed=%.2f Mbp/s, Ilv_depth=%d, Code_rate=%d/%d, Distor_AMAM=%d, Distor_AMAP=%d, %s, Data_source=%d, DA_data=%d, AD_data=%d, bert_uncoded=%d, bert_coded=%d %d, mse_avg=%d, WB_data=%d;", 
						TLevelbuf, netbuf, timebuf, r_ver_major(R0), r_ver_minor(R0), tx_symrate(R4008, R4010), r_mod_indx( R4008, R7004, R700c), Symbol_rate( R4008, R4010), sndTHR, r_ilv_depth(R4008), r_fec_cw_len(R400c), r_fec_pl_len(R400c), fft1024_power, rx_symrate(R4108, R4110), r_mod_indx( R4108, R7004, R700c), Symbol_rate( R4108, R4110), rcvTHR, r_ilv_depth(R4108), r_fec_pl_len(R400c), r_fec_cw_len(R400c), r_Distortion_AMAM(R4138), r_Distortion_AMAP(R4138), Digital_LoopbackM(R4148), rReg("tx_dbg_bert_ena"), da_data, ad_data, R414c, R4150, R4164, R413c, wb_data);

					if((ret = send( sockfd, msg, MSGSIZE, 0)) <= 0)
					{
						close(fdFpga);
						return;
					}
					printf("***send AD msg success!\n");
				}
			}
			
			if(flag4)
			{
				//星座图采样
				ret = fpga_read_scope( 328, buf);
				if(ret < 0)
				{	
					memset(msg, 0, MSGSIZE);
					sprintf( msg, "星座图采样获取失败，spi状态无法就绪。ret = %d", ret);
					send( sockfd, msg, MSGSIZE, 0);
				}
				else{
					sprintf( TLevelbuf, "0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x0x%08x",		
						buf[0],buf[1],buf[2],buf[3],buf[4],buf[5],buf[6],buf[7],buf[8],buf[9],
						buf[10],buf[11],buf[12],buf[13],buf[14],buf[15],buf[16],buf[17],buf[18],buf[19],buf[20],buf[21],buf[22],buf[23],buf[24],buf[25],buf[26],buf[27],buf[28],buf[29],buf[30],buf[31],buf[32],buf[33],buf[34],buf[35],buf[36],buf[37],buf[38],buf[39],buf[40],buf[41],buf[42],buf[43],buf[44],buf[45],buf[46],buf[47],buf[48],buf[49],buf[50],buf[51],buf[52],buf[53],buf[54],buf[55],buf[56],buf[57],buf[58],buf[59],buf[60],buf[61],buf[62],buf[63],buf[64],buf[65],buf[66],buf[67],buf[68],buf[69],buf[70],buf[71],buf[72],buf[73],buf[74],buf[75],buf[76],buf[77],buf[78],buf[79],buf[80],buf[81],buf[82],buf[83],buf[84],buf[85],buf[86],buf[87],buf[88],buf[89],buf[90],buf[91],buf[92],buf[93],buf[94],buf[95],buf[96],buf[97],buf[98],buf[99],
						buf[100],buf[101],buf[102],buf[103],buf[104],buf[105],buf[106],buf[107],buf[108],buf[109],buf[110],buf[111],buf[112],buf[113],buf[114],buf[115],buf[116],buf[117],buf[118],buf[119],buf[120],buf[121],buf[122],buf[123],buf[124],buf[125],buf[126],buf[127],buf[128],buf[129],buf[130],buf[131],buf[132],buf[133],buf[134],buf[135],buf[136],buf[137],buf[138],buf[139],buf[140],buf[141],buf[142],buf[143],buf[144],buf[145],buf[146],buf[147],buf[148],buf[149],buf[150],buf[151],buf[152],buf[153],buf[154],buf[155],buf[156],buf[157],buf[158],buf[159],buf[160],buf[161],buf[162],buf[163],buf[164],buf[165],buf[166],buf[167],buf[168],buf[169],buf[170],buf[171],buf[172],buf[173],buf[174],buf[175],buf[176],buf[177],buf[178],buf[179],buf[180],buf[181],buf[182],buf[183],buf[184],buf[185],buf[186],buf[187],buf[188],buf[189],buf[190],buf[191],buf[192],buf[193],buf[194],buf[195],buf[196],buf[197],buf[198],buf[199],
						buf[200],buf[201],buf[202],buf[203],buf[204],buf[205],buf[206],buf[207],buf[208],buf[209],buf[210],buf[211],buf[212],buf[213],buf[214],buf[215],buf[216],buf[217],buf[218],buf[219],buf[220],buf[221],buf[222],buf[223],buf[224],buf[225],buf[226],buf[227],buf[228],buf[229],buf[230],buf[231],buf[232],buf[233],buf[234],buf[235],buf[236],buf[237],buf[238],buf[239],buf[240],buf[241],buf[242],buf[243],buf[244],buf[245],buf[246],buf[247],buf[248],buf[249],buf[250],buf[251],buf[252],buf[253],buf[254],buf[255],buf[256],buf[257],buf[258],buf[259],buf[260],buf[261],buf[262],buf[263],buf[264],buf[265],buf[266],buf[267],buf[268],buf[269],buf[270],buf[271],buf[272],buf[273],buf[274],buf[275],buf[276],buf[277],buf[278],buf[279],buf[280],buf[281],buf[282],buf[283],buf[284],buf[285],buf[286],buf[287],buf[288],buf[289],buf[290],buf[291],buf[292],buf[293],buf[294],buf[295],buf[296],buf[297],buf[298],buf[299],
						buf[300],buf[301],buf[302],buf[303],buf[304],buf[305],buf[306],buf[307],buf[308],buf[309],buf[310],buf[311],buf[312],buf[313],buf[314],buf[315],buf[316],buf[317],buf[318],buf[319],buf[320],buf[321],buf[322],buf[323],buf[324],buf[325],buf[326],buf[327],buf[328],buf[329],buf[330],buf[331],buf[332],buf[333],buf[334],buf[335],buf[336],buf[337],buf[338],buf[339],buf[340],buf[341],buf[342],buf[343],buf[344],buf[345],buf[346],buf[347],buf[348],buf[349],buf[350],buf[351],buf[352],buf[353],buf[354],buf[355],buf[356],buf[357],buf[358],buf[359],buf[360],buf[361],buf[362],buf[363],buf[364],buf[365],buf[366],buf[367],buf[368],buf[369],buf[370],buf[371],buf[372],buf[373],buf[374],buf[375],buf[376],buf[377],buf[378],buf[379],buf[380],buf[381],buf[382],buf[383],buf[384],buf[385],buf[386],buf[387],buf[388],buf[389],buf[390],buf[391],buf[392],buf[393],buf[394],buf[395],buf[396],buf[397],buf[398],buf[399],
						buf[400],buf[401],buf[402],buf[403],buf[404],buf[405],buf[406],buf[407],buf[408],buf[409],buf[410],buf[411],buf[412],buf[413],buf[414],buf[415],buf[416],buf[417],buf[418],buf[419],buf[420],buf[421],buf[422],buf[423],buf[424],buf[425],buf[426],buf[427],buf[428],buf[429],buf[430],buf[431],buf[432],buf[433],buf[434],buf[435],buf[436],buf[437],buf[438],buf[439],buf[440],buf[441],buf[442],buf[443],buf[444],buf[445],buf[446],buf[447],buf[448],buf[449],buf[450],buf[451],buf[452],buf[453],buf[454],buf[455],buf[456],buf[457],buf[458],buf[459],buf[460],buf[461],buf[462],buf[463],buf[464],buf[465],buf[466],buf[467],buf[468],buf[469],buf[470],buf[471],buf[472],buf[473],buf[474],buf[475],buf[476],buf[477],buf[478],buf[479],buf[480],buf[481],buf[482],buf[483],buf[484],buf[485],buf[486],buf[487],buf[488],buf[489],buf[490],buf[491],buf[492],buf[493],buf[494],buf[495],buf[496],buf[497],buf[498],buf[499],
						buf[500],buf[501],buf[502],buf[503],buf[504],buf[505],buf[506],buf[507],buf[508],buf[509],buf[510],buf[511],buf[512],buf[513],buf[514],buf[515],buf[516],buf[517],buf[518],buf[519],buf[520],buf[521],buf[522],buf[523],buf[524],buf[525],buf[526],buf[527],buf[528],buf[529],buf[530],buf[531],buf[532],buf[533],buf[534],buf[535],buf[536],buf[537],buf[538],buf[539],buf[540],buf[541],buf[542],buf[543],buf[544],buf[545],buf[546],buf[547],buf[548],buf[549],buf[550],buf[551],buf[552],buf[553],buf[554],buf[555],buf[556],buf[557],buf[558],buf[559],buf[560],buf[561],buf[562],buf[563],buf[564],buf[565],buf[566],buf[567],buf[568],buf[569],buf[570],buf[571],buf[572],buf[573],buf[574],buf[575],buf[576],buf[577],buf[578],buf[579],buf[580],buf[581],buf[582],buf[583],buf[584],buf[585],buf[586],buf[587],buf[588],buf[589],buf[590],buf[591],buf[592],buf[593],buf[594],buf[595],buf[596],buf[597],buf[598],buf[599],
						buf[600],buf[601],buf[602],buf[603],buf[604],buf[605],buf[606],buf[607],buf[608],buf[609],buf[610],buf[611],buf[612],buf[613],buf[614],buf[615],buf[616],buf[617],buf[618],buf[619],buf[620],buf[621],buf[622],buf[623],buf[624],buf[625],buf[626],buf[627],buf[628],buf[629],buf[630],buf[631],buf[632],buf[633],buf[634],buf[635],buf[636],buf[637],buf[638],buf[639],buf[640],buf[641],buf[642],buf[643],buf[644],buf[645],buf[646],buf[647],buf[648],buf[649],buf[650],buf[651],buf[652],buf[653],buf[654],buf[655],buf[656],buf[657],buf[658],buf[659],buf[660],buf[661],buf[662],buf[663],buf[664],buf[665],buf[666],buf[667],buf[668],buf[669],buf[670],buf[671],buf[672],buf[673],buf[674],buf[675],buf[676],buf[677],buf[678],buf[679],buf[680],buf[681],buf[682],buf[683],buf[684],buf[685],buf[686],buf[687],buf[688],buf[689],buf[690],buf[691],buf[692],buf[693],buf[694],buf[695],buf[696],buf[697],buf[698],buf[699],
						buf[700],buf[701],buf[702],buf[703],buf[704],buf[705],buf[706],buf[707],buf[708],buf[709],buf[710],buf[711],buf[712],buf[713],buf[714],buf[715],buf[716],buf[717],buf[718],buf[719],buf[720],buf[721],buf[722],buf[723],buf[724],buf[725],buf[726],buf[727],buf[728],buf[729],buf[730],buf[731],buf[732],buf[733],buf[734],buf[735],buf[736],buf[737],buf[738],buf[739],buf[740],buf[741],buf[742],buf[743],buf[744],buf[745],buf[746],buf[747],buf[748],buf[749],buf[750],buf[751],buf[752],buf[753],buf[754],buf[755],buf[756],buf[757],buf[758],buf[759],buf[760],buf[761],buf[762],buf[763],buf[764],buf[765],buf[766],buf[767],buf[768],buf[769],buf[770],buf[771],buf[772],buf[773],buf[774],buf[775],buf[776],buf[777],buf[778],buf[779],buf[780],buf[781],buf[782],buf[783],buf[784],buf[785],buf[786],buf[787],buf[788],buf[789],buf[790],buf[791],buf[792],buf[793],buf[794],buf[795],buf[796],buf[797],buf[798],buf[799],
						buf[800],buf[801],buf[802],buf[803],buf[804],buf[805],buf[806],buf[807],buf[808],buf[809],buf[810],buf[811],buf[812],buf[813],buf[814],buf[815],buf[816],buf[817],buf[818],buf[819],buf[820],buf[821],buf[822],buf[823],buf[824],buf[825],buf[826],buf[827],buf[828],buf[829],buf[830],buf[831],buf[832],buf[833],buf[834],buf[835],buf[836],buf[837],buf[838],buf[839],buf[840],buf[841],buf[842],buf[843],buf[844],buf[845],buf[846],buf[847],buf[848],buf[849],buf[850],buf[851],buf[852],buf[853],buf[854],buf[855],buf[856],buf[857],buf[858],buf[859],buf[860],buf[861],buf[862],buf[863],buf[864],buf[865],buf[866],buf[867],buf[868],buf[869],buf[870],buf[871],buf[872],buf[873],buf[874],buf[875],buf[876],buf[877],buf[878],buf[879],buf[880],buf[881],buf[882],buf[883],buf[884],buf[885],buf[886],buf[887],buf[888],buf[889],buf[890],buf[891],buf[892],buf[893],buf[894],buf[895],buf[896],buf[897],buf[898],buf[899],
						buf[900],buf[901],buf[902],buf[903],buf[904],buf[905],buf[906],buf[907],buf[908],buf[909],buf[910],buf[911],buf[912],buf[913],buf[914],buf[915],buf[916],buf[917],buf[918],buf[919],buf[920],buf[921],buf[922],buf[923],buf[924],buf[925],buf[926],buf[927],buf[928],buf[929],buf[930],buf[931],buf[932],buf[933],buf[934],buf[935],buf[936],buf[937],buf[938],buf[939],buf[940],buf[941],buf[942],buf[943],buf[944],buf[945],buf[946],buf[947],buf[948],buf[949],buf[950],buf[951],buf[952],buf[953],buf[954],buf[955],buf[956],buf[957],buf[958],buf[959],buf[960],buf[961],buf[962],buf[963],buf[964],buf[965],buf[966],buf[967],buf[968],buf[969],buf[970],buf[971],buf[972],buf[973],buf[974],buf[975],buf[976],buf[977],buf[978],buf[979],buf[980],buf[981],buf[982],buf[983],buf[984],buf[985],buf[986],buf[987],buf[988],buf[989],buf[990],buf[991],buf[992],buf[993],buf[994],buf[995],buf[996],buf[997],buf[998],buf[999],
						buf[1000],buf[1001],buf[1002],buf[1003],buf[1004],buf[1005],buf[1006],buf[1007],buf[1008],buf[1009],buf[1010],buf[1011],buf[1012],buf[1013],buf[1014],buf[1015],buf[1016],buf[1017],buf[1018],buf[1019],buf[1020],buf[1021],buf[1022],buf[1023]
						);

					memset(msg, 0, MSGSIZE);
					sprintf( msg, "%s;serverip:%s,%s,version=%d.%d_1.01.02;snd:TLevel=0.0 dBm,NBWidth=%.1f MHz,MType=%s, Symbol_rate=%.2f Mbd, Data_rate=%.2f Mbp/s, Ilv_depth=%d, Code_rate=%d/%d;rev:TLevel=%.2f dBm,NBWidth=%.1f MHz,MType=%s, Symbol_rate=%.2f Mbd, NSpeed=%.2f Mbp/s, Ilv_depth=%d, Code_rate=%d/%d, Distor_AMAM=%d, Distor_AMAP=%d, %s, Data_source=%d, DA_data=%d, AD_data=%d, bert_uncoded=%d, bert_coded=%d %d, mse_avg=%d, WB_data=%d;", 
						TLevelbuf, netbuf, timebuf, r_ver_major(R0), r_ver_minor(R0), tx_symrate(R4008, R4010), r_mod_indx( R4008, R7004, R700c), Symbol_rate( R4008, R4010), sndTHR, r_ilv_depth(R4008), r_fec_cw_len(R400c), r_fec_pl_len(R400c), fft1024_power, rx_symrate(R4108, R4110), r_mod_indx( R4108, R7004, R700c), Symbol_rate( R4108, R4110), rcvTHR, r_ilv_depth(R4108), r_fec_pl_len(R400c), r_fec_cw_len(R400c), r_Distortion_AMAM(R4138), r_Distortion_AMAP(R4138), Digital_LoopbackM(R4148), rReg("tx_dbg_bert_ena"), da_data, ad_data, R414c, R4150, R4164, R413c, wb_data);
				
					//printf("%s\n",msg);
					if((ret = send( sockfd, msg, MSGSIZE, 0)) <= 0)
					{
						close(fdFpga);
						return;
					}
					printf("***send Constellation msg success!\n");
				}
			}
		}
	}
    close(fdFpga);
	return ;	
}
