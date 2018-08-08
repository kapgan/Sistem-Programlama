#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdlib.h>
#include <wait.h>
#include <string.h>
#include <netdb.h>
#define PORT 8080
int main(int argc, char const *argv[]){printf("111");
int sock=socket(AF_INET, SOCK_STREAM,0);printf("112");
if(sock<0)
perror("Create error\n");
printf("113");
struct sockaddr_in serveraddr;
struct hostent *host;

serveraddr.sin_family=AF_INET;
host=gethostbyname("127.0.0.1");
serveraddr.sin_port=htons(5015);

int c=connect(sock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

if(c<0)
perror("Connect Error");

char message[1024];
printf("Mesahinizi yaziniz..\n");
fgets(message,1024,stdin);
printf("Mesajiniz = %s \n",message);

int s=send(sock,message,strlen(message),0);
if(s<0)
perror("SEND ERROR\n");
else
printf("Mesahiniz basarile gonderilmistir...\n");

close(sock);

return 0;
}
