#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>


/* Once you run this code with ./main
    to be able to read the network connection, start a telnet server on the same port
    which 8080 --> $telnet localhost 8080
    after this start, write a message and the message will be read from the ./main app. */

#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd;
    socklen_t clilen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(8080);

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(1);
    }

    // Listen for incoming connections
    listen(sockfd, 5);
    printf("Waiting for incoming connections...\n");

    // Accept a client connection
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        perror("Error on accept");
        exit(1);
    }
    printf("Connection established with %s\n", inet_ntoa(cli_addr.sin_addr));

    // Read data from the client
    memset(buffer, 0, BUFFER_SIZE);
    int n = read(newsockfd, buffer, BUFFER_SIZE - 1);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("Received message: %s\n", buffer);

    // Send data to the client
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Close the connection
    close(newsockfd);
    close(sockfd);
    printf("Connection closed.\n");

    return 0;
}
