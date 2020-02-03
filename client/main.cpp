#include <stdio.h>

#include <winsock2.h>

#pragma comment (lib,"ws2_32.lib")

int main (int argc , char *argv[])
{
    //initialize windows socket
    WSADATA  wsa;
    SOCKET s;
    struct sockaddr_in server ;
    printf ("\nInitialising winsock ...");
    if (WSAStartup(MAKEWORD(2,2),&wsa) !=0)
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return 1;
    }
    printf ("Initialised.\n");

    //CREATE SOCKET
    if ((s =socket(AF_INET , SOCK_STREAM , 0 ))==INVALID_SOCKET)
    {
        printf("Could not create socket : %d ", WSAGetLastError());
    }
    printf("Socket created.\n");

    server.sin_family = AF_INET ; //ADDR IPV4
    server.sin_port = htons(1000);
    server.sin_addr.s_addr = inet_addr("192.168.3.15");


    //send
   while (1)
   {
       connect(s,(struct sockaddr *)&server ,sizeof(server));
Sleep(100);

    char message [50] = "GET\n" ;
    send (s,message ,strlen (message),0);
    printf("connect");
    //char recv_buf[2000]="";
    //recv (s,recv_buf,2000,0);

    //puts(recv_buf);

    closesocket(s);
    Sleep(1000);

   }

}
