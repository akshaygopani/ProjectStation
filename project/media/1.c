#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 5432
#define MAX_PANDING 10
#define BUF_SIZE 2048

int main(){
        struct sockaddr_in sin;
        
        int s,new_s;
        char str[INET_ADDRSTRLEN];  //inet_ntop
        char buf[BUF_SIZE];
        
        sin.sin_family=AF_INET;
        sin.sin_addr.s_addr=INADDR_ANY;
        sin.sin_port=htons(SERVER_PORT);
        
        
        if(s=socket(AF_INET,SOCK_STREAM,0)<0){
                perror("can't done\n");
        }
                
       
        
        inet_ntop(AF_INET,&(sin.sin_addr),str,INET_ADDRSTRLEN);
        
        printf("Convert of ip in text is %s",str);
        
        if(bind(s,(struct sockaddr_sin *)&sin,sizeof(sin))<0){
                perror("binding not occure \n");
        }
        
        else
                printf("bind is done\n");
                
                
        listen(s,MAX_PANDING);
        
        while(1){
                strcpy(buf,"copy\n");
                if(new_s=accept(s,(struct sockaddr_in *)&sin),sizeof(sin)){
                        printf("Error\n");
                        exit(1);
                }
                send(new_s,buf,sizeof(buf),0);
                memset(buf,0,sizeof(buf));
                close(new_s);
        
        }
          
        return 0;
}
