#include<stdio.h> //printf
#include<string.h>    //strlen
#include<sys/socket.h>    //socket
#include<arpa/inet.h> //inet_addr
 


int main(int argc, char **argv)
{
    int sockfd;
    char buffer[1000];
    char server_reply[2000];
    ssize_t n;
   struct sockaddr_in servaddr; 
   sockfd = socket(AF_INET,SOCK_STREAM,0);
   if (sockfd == -1)
    {
        perror("Could not create socket");
    }
	printf("Created Socket \n");
   bzero(&servaddr,sizeof (servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_port = htons(8888);
   servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
   //inet_pton(AF_INET, argv[1],&servaddr.sin_addr);
   
   connect(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr));
   //while (recv_line(sockfd,buffer ) > 0)
   while (1)
   {
	   
    printf("Enter a Message: ");
    scanf("%s",buffer);

   }
    close(sockfd);
	return 0;
}