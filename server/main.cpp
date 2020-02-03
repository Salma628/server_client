#include <stdio.h>
#include <winsock2.h>  //socket ap's

#pragma comment (lib,"ws2_32.lib")
int main ()
{
    WSADATA wsa;
    SOCKET s,n;  //socket desc
   struct sockaddr_in server,clientaddr;
   printf("\n INitialising Winsock....");
   if (WSAStartup(MAKEWORD(2,2),&wsa)  != 0)
   {
       printf("faild error code :%d",WSAGetLastError());
       return 1;
   }
   printf("initilazing.\n");
//creat a socket
   if((s=socket(AF_INET ,SOCK_STREAM,0))== INVALID_SOCKET)
   {
       printf("could not creat socket :%d",WSAGetLastError());
   }
   printf("Socket created \n ");
   server.sin_family=AF_INET;  //ADDRESS FAMILY IPv4
   server.sin_port=htons(1000);
   server.sin_addr.s_addr=INADDR_ANY;//inet_addr("192.168.3.14");


  if(bind(s ,(struct sockaddr *)&server,sizeof(server) ) <0)
 {printf("faild to  bind error code :%d",WSAGetLastError());
  return 1;
  }
  if (listen(s,3)<0 )
  {
      printf("faild error code :%d",WSAGetLastError());
  return 1;
  }
   char message[50]="data\n";
   //gets(message);
while(1){
  int size ;
 // printf("accept");
 n =  accept(s,(struct sockaddr *)&clientaddr,&size);
//Sleep(100);
//int message;



   char recv_buf[200]="";

  // send(s,message,strlen(message),0);
    recv(n,recv_buf,10,0);
    printf("data=%s",recv_buf);
 puts(recv_buf);
  // closesocket(n);
  // Sleep(1000);

}

return 0;

}
