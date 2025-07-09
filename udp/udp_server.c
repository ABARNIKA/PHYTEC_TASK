// Required for standard input/output functions: printf(), fprintf()
#include <stdio.h>

// Required for dynamic memory allocation and functions like exit()
#include <stdlib.h>

// Required for string manipulation functions: memset(), strlen(), etc.
#include <string.h>

// Required for close() system call to close the socket
#include <unistd.h>

// Required for socket-related functions and network structures
#include <arpa/inet.h>

#define BUFFER_SIZE 1024  // Maximum buffer size for sending/receiving messages

int main(int argc, char *argv[]) {
    // Check if port number is provided via command-line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Convert command-line port argument from string to integer
    int PORT = atoi(argv[1]);

    int sockfd;  // Socket file descriptor
    char buffer[BUFFER_SIZE];  // Buffer for message transfer
    struct sockaddr_in servaddr, cliaddr;  // Structures for server and client addresses
    socklen_t len = sizeof(cliaddr);  // Length of client address

    // Create a UDP socket: IPv4 + Datagram + Default protocol
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Clear the memory of server and client address structures
    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Fill in server address details
    servaddr.sin_family = AF_INET;         // Use IPv4
    servaddr.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP
    servaddr.sin_port = htons(PORT);       // Convert port to network byte order

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");  // If binding fails, print error and exit
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Inform user that server has started
    printf("UDP Chat Server started on port %d...\n", PORT);

    // Infinite loop to receive and respond to client messages
    while (1) {
        // Clear buffer before receiving message
        memset(buffer, 0, BUFFER_SIZE);

        // Receive message from client
        int n = recvfrom(sockfd, buffer, BUFFER_SIZE - 1, 0,
                         (struct sockaddr *)&cliaddr, &len);
        if (n < 0) {
            perror("recvfrom failed");
            continue;
        }

        buffer[n] = '\0';  // Null-terminate the received string
        printf(" Client: %s", buffer);  // Print client's message

        // Take input from server operator to send reply
        printf(" You: ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send reply to client using same socket and client address
        sendto(sockfd, buffer, strlen(buffer), 0,
               (struct sockaddr *)&cliaddr, len);
    }

    // Close the socket (will not reach here due to infinite loop)
    close(sockfd);
    return 0;
}

