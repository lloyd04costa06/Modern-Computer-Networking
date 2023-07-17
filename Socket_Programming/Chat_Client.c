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

    int sock;
    struct sockaddr_in sock_addr;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        perror("Socket Error\n");
        exit(1);
    }

    memset(&sock_addr, '\0', sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(port);
    sock_addr.sin_addr.s_addr = inet_addr(ip);

    if (connect(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)
    {
        perror("Connect Error\n");
        exit(1);
    }
    printf("Connected to server...\n");

    while (1)
    {
        bzero(buffer, 1024);
        printf("--> ");
        scanf("%s", buffer);
        send(sock, buffer, strlen(buffer), 0);

        bzero(buffer, 1024);
        recv(sock, buffer, sizeof(buffer), 0);
        printf("Server: %s\n", buffer);

        if (strcmp("Bye", buffer) == 0)
            break;
    }

    close(sock);

    return 0;
}
