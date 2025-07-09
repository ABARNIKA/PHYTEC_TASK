// Required for standard I/O functions like printf, scanf, fgets, etc.
#include <stdio.h>

// Required for dynamic memory allocation and exit()
#include <stdlib.h>

// Required for string operations like memset(), strlen(), strcpy(), strcmp(), etc.
#include <string.h>

// Required for close() function used to close socket
#include <unistd.h>

// Provides definitions for internet operations — like sockaddr_in, htons(), inet_addr()
#include <arpa/inet.h>

#define BUFFER_SIZE 1024  // Maximum size for the send/receive message buffer

int main(int argc, char *argv[]) {
    // Check if user passed correct number of arguments (program, IP, Port)
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Extract server IP and port from arguments
    const char *SERVER_IP = argv[1];
    int SERVER_PORT = atoi(argv[2]);  // Convert string port to integer

    int sockfd;                         // Socket file descriptor
    char buffer[BUFFER_SIZE];          // Buffer for sending and receiving messages
    struct sockaddr_in servaddr;       // Structure to hold server address
    socklen_t len = sizeof(servaddr);  // Length of the server address struct

    // Create UDP socket using IPv4 (AF_INET), Datagram (SOCK_DGRAM)
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");  // If socket creation fails
        exit(EXIT_FAILURE);
    }

    // Set all bytes of server address structure to 0
    memset(&servaddr, 0, sizeof(servaddr));

    // Set server address family, port and IP
    servaddr.sin_family = AF_INET;                     // Use IPv4
    servaddr.sin_port = htons(SERVER_PORT);            // Convert port to network byte order
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);   // Convert IP string to binary form

    // Print connection message
    printf("Connected to server %s:%d\n", SERVER_IP, SERVER_PORT);
    printf("Start chatting... (Ctrl+C to quit)\n");

    // Loop for continuous send/receive
    while (1) {
        printf(" You: ");
        fgets(buffer, BUFFER_SIZE, stdin);  // Read message from user input

        // Send message to server
        sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr *)&servaddr, len);

        // Clear buffer before receiving reply
        memset(buffer, 0, BUFFER_SIZE);

        // Receive message from server
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                         (struct sockaddr *)&servaddr, &len);
        if (n < 0) {
            perror("recvfrom failed");  // If receive fails
            continue;
        }

        buffer[n] = '\0';  // Add null character at the end
        printf("Server: %s", buffer);  // Display server's response
    }

    // Close the socket (will not be reached in infinite loop)
    close(sockfd);
    return 0;
}

