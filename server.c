#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <arpa/inet.h>

#include "server.h"

#define PORT 8080
#define QUEUE_MAX_COUNT 5
#define BUFF_SIZE 1024
#define BACKLOG 5

int main()
{
    printf("start server\n");
    // create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    int sin_size;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    //memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if(bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0 ) 
    {
        printf("Socket bind error!\n");
    }

    listen(server_socket, BACKLOG);

    while(1)
    {
        sin_size = sizeof(struct sockaddr_in);
        int client_socket = accept(server_socket, (struct socketaddr*)&client_addr, sin_size);

        if(client_socket==-1)
        {
            printf("Receive client failed!\n");
        }
        else
        {
            printf("Receive client success!\n");
            send(client_socket, "Hello World", 12, 0);
        }
    }

}
