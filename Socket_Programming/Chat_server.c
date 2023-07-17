#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
    char *ip = "127.0.0.1";
    int port = 5566;
    char buffer[1024];

    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t sock_addr_len;

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0)
    {
        perror("Socket Error\n");
        exit(1);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    int n = bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (n < 0)
    {
        perror("Binding Error\n");
        exit(1);
    }

    listen(server_sock, 5);
    printf("Server Listening...\n");

    sock_addr_len = sizeof(client_addr);
    client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &sock_addr_len);
    if (client_sock < 0)
    {
        perror("Accept Error\n");
        exit(1);
    }
    printf("Client Connected Successfully\n");

    while (1)
    {
        bzero(buffer, 1024);
        n = recv(client_sock, buffer, sizeof(buffer), 0);
        if (n < 0)
        {
            perror("Error\n");
            exit(1);
        }
        printf("Client: %s\n", buffer);

        bzero(buffer, 1024);
        printf("--> ");
        scanf("%s", buffer);
        send(client_sock, buffer, strlen(buffer), 0);
        if (strcmp("Bye", buffer) == 0)
            break;
    }

    close(server_sock);
    close(client_sock);

    return 0;
}
