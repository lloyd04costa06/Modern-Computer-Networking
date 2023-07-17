#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_PORT 5566

int main() {
    int server_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;
    char buffer[MAX_BUFFER_SIZE];

    // Create UDP socket
    if ((server_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to server address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (1) {
        // Receive data from the client
        memset(buffer, 0, MAX_BUFFER_SIZE);
        client_addr_len = sizeof(client_addr);
        ssize_t num_bytes = recvfrom(server_sock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&client_addr, &client_addr_len);

        if (num_bytes < 0) {
            perror("Receive error");
            continue;
        }

        printf("Client: %s\n", buffer);

        // Process received data or perform necessary operations

        // Send response to the client
        if (sendto(server_sock, buffer, strlen(buffer), 0, (struct sockaddr *)&client_addr, client_addr_len) < 0) {
            perror("Send error");
            exit(EXIT_FAILURE);
        }

        if (strcmp("Bye", buffer) == 0)
            break;
    }

    // Close the server socket
    close(server_sock);

    return 0;
}
