/*********************************************
*********main()
*********client 主函数
*********网络初始化 建立客户端连接
*********************************************/
#include "protocol.h"


int main(int argc, const char *argv[])
{
	int fd,ret;
	struct sockaddr_in myaddr;
	char buf[1024];
	char buf_scop[1024*10];	
	char cmd;
	
	fd = socket(AF_INET,SOCK_STREAM,0);
	myaddr.sin_family=AF_INET;
	myaddr.sin_port=htons(32000);
	myaddr.sin_addr.s_addr = inet_addr("192.168.1.39");
	
	
	if((connect(fd,(struct sockaddr *)&myaddr,sizeof(myaddr))) < 0)
	{
		perror("network fail!\n");
		exit(-1);
	}
	printf("---------------------------------------\n");
	printf("network init sockfd : %d\n",fd);
	printf("Welcome to the test client\n");
	sockfd = fd;
	
	while(1)
	{
		ret = login();
		if(ret == 0)
		{
			printf("login fail\n");
		}
		if(ret == 1)
		{
			printf("login success\n");
			break;
		}
	}
	
	while(1)
	{
		printf("input you chose\n");
		scanf("%c", &cmd);
		
		if(cmd == 'a')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("a send error\n");
				return;
			}
			
			memset(buf, 0, 1024);
			if((ret = recv( sockfd, buf, 1024, 0)) == 0)
			{
				printf("a recv error\n");
				return;
			}
			printf("a recv buf = %s\n",buf);
		}
		if(cmd == 'b')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("b send error\n");
				return;
			}
			
			memset(buf, 0, 1024);
			if((ret = recv( sockfd, buf, 1024, 0)) == 0)
			{
				printf("b recv error\n");
				return;
			}
			printf("b recv buf = %s\n",buf);
		}
		if(cmd == 'c')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("c send error\n");
				return;
			}
			
			memset(buf_scop, 0, 1024*10);
			if((ret = recv( sockfd, buf_scop, 1024*10, 0)) == 0)
			{
				printf("c recv error\n");
				return;
			}
			printf("b recv buf = %s\n",buf_scop);
		}
		if(cmd == 'd')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("d send error\n");
				return;
			}
			
			memset(buf_scop, 0, 1024*10);
			if((ret = recv( sockfd, buf_scop, 1024*10, 0)) == 0)
			{
				printf("d recv error\n");
				return;
			}
			printf("b recv buf = %s\n",buf_scop);
		}
		
		
		if(cmd == 'A')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("A send error\n");
				return;
			}
		}
		if(cmd == 'B')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("B send error\n");
				return;
			}
		}
		if(cmd == 'C')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("C send error\n");
				return;
			}
		}
		if(cmd == 'D')
		{
			buf[0] = cmd;
			if((ret = send( sockfd, buf[0], 1, 0)) == 0)
			{
				printf("D send error\n");
				return;
			}
		}
	}

	printf("client quit\n");
	close(sockfd);
	return 0;
}
