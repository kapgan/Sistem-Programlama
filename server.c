
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

int main(int argc, char const *argv[]){
int sock=socket(AF_INET,SOCK_STREAM,0);
if(sock<0)
perror("Creat ERROR");
struct sockaddr_in serveraddr,clientaddr;

serveraddr.sin_addr.s_addr=INADDR_ANY;
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(5015);
    
char buff[1024];

socklen_t clientlen=sizeof(clientaddr);

int b=bind(sock,(struct sockaddr*)&serveraddr,sizeof(serveraddr));

if(b<0)
perror("Bind ERROR");

listen(sock,5);

while(1){
int client=accept(sock,(struct sockaddr*) &clientaddr,&clientlen); //Hata çıktısı vermese de burada sorun olduğu sonucuna vardım.

if(client<0)
perror("Client ERROR");
int r=read(client,buff,1024);
if(r<0)
perror("R ERROR");

printf("%s\n",buff);
close(client);
}
return 0;

}
