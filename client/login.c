/*********************************************
********* login()
********* client ��¼��������
********* ��������ֵ��
********* 0:��¼ʧ�� 1����¼�û�ģʽ 2����¼������ģʽ
*********************************************/
#include "protocol.h"

int login()
{
	int ret;
	char buf[1024];
	Msg.cmd_type = '1';
	printf("============================\n");
	printf("input your name:\n");
	scanf("%s",Msg.name);
	printf("your passwd:\n");
	scanf("%s",Msg.passwd);
	
	printf("type=%d, name=%s, passwd=%s\n",Msg.cmd_type,Msg.name,Msg.passwd);
	write( sockfd, &Msg, 1024);
	
	if((ret = read( sockfd, buf, 1024)) <= 1)
	{
		printf("read error\n");
	}
	printf("buf = %s\n",buf);
	switch(Msg.cmd_type)
	{
	case '0':
		return 0;
	case '1':
		return 1;
	}
}
