/****************************************************************
	-> file name : main.c
	-> author : fluency
	-> Created time : 2017-08-01 15:05
	-> function : Main function program entry
****************************************************************/
#include "protocol.h"


int main(int argc, char *argv[])
{
	int sockfd,newsockfd,ret;
	struct sockaddr_in caddr;
	socklen_t caddr_len = sizeof(struct sockaddr_in);
	
	pthread_t spi_thread; 
	pthread_t read_thread;	
	
	sockfd = net_init();
	
	while(1)
	{
		
		pthread_mutex_init (&mutex, NULL);
		
		if((newsockfd = accept(sockfd,(struct sockaddr *)&caddr, &caddr_len)) == -1)
		{
			perror("accept error");
			exit(-1);
		}
		else
		{
			printf("accepted a new connection ..\n");
			printf("new socket id : %d\n",newsockfd);
			printf("connection from [%s:%d]\n",inet_ntoa(caddr.sin_addr),ntohs(caddr.sin_port));
		}
	
		//login登录函数
		if((ret = login((void *)&newsockfd)) == 1)
		{
			printf("login success\n");
		}
		if(ret == 0)
			continue;
		printf("******start**pthread_read**pthread_write******\n");

		//写线程
		if(pthread_create( &read_thread, NULL, pthread_spi, (void *)&newsockfd) < 0)  
		{  
			perror("fail to pthread_create");  
			//exit(-1);  
		}
		
		//读线程
		if(pthread_create( &spi_thread, NULL, pthread_read, (void *)&newsockfd) < 0)  
		{  
			perror("fail to pthread_create"); 
			//exit(-1);  
		}
		pthread_join(read_thread, NULL);
		printf("pthread_join\n");
		pthread_join(spi_thread, NULL);
		printf("pthread_join\n");
		pthread_mutex_destroy (&mutex);
		printf("clent quit!\n");
		close(newsockfd);
	}
	
	
	printf("close listen socket\n");
	close(sockfd);
	return 0;
}
