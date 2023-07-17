#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5566

int main() {
    int client_sock;
    struct sockaddr_in server_addr;
    socklen_t server_addr_len;
    char buffer[MAX_BUFFER_SIZE];

    // Create UDP socket
    if ((client_sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket error");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &(server_addr.sin_addr)) <= 0) {
        perror("Invalid server IP address");
        exit(EXIT_FAILURE);
    }

    printf("Connecting to server...\n");

    while (1) {
        // Prompt user for input
        printf("-->");
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        // Send data to the server
        if (sendto(client_sock, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("Send error");
            exit(EXIT_FAILURE);
        }

        // Receive response from the server
        memset(buffer, 0, MAX_BUFFER_SIZE);
        ssize_t num_bytes = recvfrom(client_sock, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &server_addr_len);

        if (num_bytes < 0) {
            perror("Receive error");
            exit(EXIT_FAILURE);
        }

        printf("Server: %s\n", buffer);

        if (strcmp("Bye", buffer) == 0)
            break;
    }

    // Close the client socket
    close(client_sock);

    return 0;
}
