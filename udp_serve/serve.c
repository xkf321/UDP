#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char** argv) /*　传入服务端的ip和端口　*/
{

    int CltAddr_len;
    char message[256];

    int socket_descriptor;
    struct sockaddr_in SerAddr,CltAddr;
	
	/*确认有参数*/
	if(argc!=3) 
	{ 
		printf("parameter error"); /*　argv[1] 是目的ip argv[2]是目的端口　*/
		exit(1); 
	}	
	
    printf("Waiting for data form sender \n");

    bzero(&SerAddr,sizeof(SerAddr)); /*将SerAddr清零*/
    SerAddr.sin_family=AF_INET; /*Address family一般来说AF_INET（地址族）PF_INET（协议族）*/
    SerAddr.sin_addr.s_addr=htonl(INADDR_ANY);/*任意地址0.0.0.0 泛指本机ip htonl的功能将主机的无符号长整形数转换成网络字节顺序。*/
    SerAddr.sin_port=htons((unsigned short)atoi(argv[2]));/*端口   htons的功能：将一个无符号短整型的主机数值转换为网络字节顺序，即大尾顺序*/ 
    CltAddr_len=sizeof(CltAddr);

    socket_descriptor=socket(AF_INET,SOCK_DGRAM,0);//创建一个套接字
    bind(socket_descriptor,(struct sockaddr *)&SerAddr,sizeof(SerAddr));//bind函数可以将一组固定的地址绑定到sockfd套接字上。

    while(1)
    {
        recvfrom(socket_descriptor,message,sizeof(message),0,(struct sockaddr *)&CltAddr,&CltAddr_len);
        printf("Response from server:%s\n",message);
        if(strncmp(message,"stop",4) == 0)//接受到的消息为 “stop”
        {

            printf("Sender has told me to end the connection\n");
            break;
        }
    }

    close(socket_descriptor);
    exit(0);

    return (EXIT_SUCCESS);
}