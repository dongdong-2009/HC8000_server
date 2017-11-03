/****************************************************************
	-> file name : protocol.h
	-> author : fluency
	-> Created time : 2017-08-01 15:05
	-> function : all header file and function declaration
****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h> 
#include <pthread.h> 

#include <sys/stat.h>
#include <fcntl.h>
#include <sys/socket.h>

#include <stdint.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/types.h>

#include <math.h>
#include <time.h>


#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define debug_pos() printf("%s-%d\n", __FUNCTION__, __LINE__);
#define PI 3.1415926535897932384626433832795028841971

#define RX_BUF_SIZE_DIV4 1024
#define RX_BUF_SIZE_DIV2 (RX_BUF_SIZE_DIV4 *2)
#define RX_BUF_SIZE_DIV8 512



#define PORT 32000
#define SIZEBUF 1024
#define DATALEN 10
#define UMSGLEN sizeof(Msg)
int sockfd;

int login();
char buf[SIZEBUF];

struct XProtocol 
{  
    char cmd_type;
	unsigned char name[DATALEN];
	unsigned char passwd[DATALEN];
}Msg;
