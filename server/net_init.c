/****************************************************************
	-> file name : net_init.c
	-> author : fluency
	-> Created time : 2017-08-01 15:05
	-> function : Network initialization
****************************************************************/
#include "protocol.h"

int net_init()
{
	int listenfd;
	struct sockaddr_in addr;
	int addr_len = sizeof(struct sockaddr_in);
	
	//创建监听套接字socket
	if((listenfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
	{
		perror("socket error");
		exit(-1);
	}
	else
	{
		printf("socket success!\n");
		printf("socket id : %d\n",listenfd);
	}

	memset(&addr,0,addr_len);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	//绑定套接字
	if(bind(listenfd,(struct sockaddr *)&addr, addr_len) == -1)
	{
		perror("bind error");
		exit(-1);
	}
	else
	{
		printf("bind success!\n");
		printf("local port : %d\n",PORT);
	}
	
	//监听套接字socket，最多支持五个客户端连接
	if(listen(listenfd,5) == -1)
	{
		perror("listen error");
		exit(-1);
	}
	else
	{
		printf("listening...\n");
	}
	return listenfd;
}
