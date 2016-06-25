#include<stdio.h>
#include<string.h>
#include <fcntl.h>
#include<sys/socket.h>
#include<arpa/inet.h> //inet_addr

int main(int argc , char *argv[])
{
    int socket_desc, fd;
    struct sockaddr_in server;
    char message[1024];
    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);

    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    server.sin_addr.s_addr = inet_addr(argv[1]);
    server.sin_family = AF_INET;
    server.sin_port = htons( 8765 );

    //Connect to remote server
    if (connect(socket_desc ,(struct sockaddr *)&server,sizeof(server)) < 0)
    {
        puts("connect error");
        return 1;
    }
    puts("Connected\n");

    //Read data from mice and send them to server from socket
    if ( (fd = open("/dev/input/mice",O_WRONLY)) == -1 )
    {
        perror("cannot open /dev/input/mice");
        return 1;
    }

    while ( read(fd, message, 1024) > 0 )
    {
        if( send(socket_desc , message , strlen(message) , 0) < 0)
        {
            puts("Send failed");
            return 1;
        }
    }
    return 0;
}
