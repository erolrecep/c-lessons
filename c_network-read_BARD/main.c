#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(1);
  }

  // Bind the socket to a port
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  addr.sin_addr.s_addr = INADDR_ANY;
  if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    perror("bind");
    exit(1);
  }

  // Listen for connections
  listen(sockfd, 5);

  // Accept a connection
  int clientfd = accept(sockfd, NULL, NULL);
  if (clientfd < 0) {
    perror("accept");
    exit(1);
  }

  // Read in a network packet
  char buf[1024];
  int nread = read(clientfd, buf, sizeof(buf));
  if (nread < 0) {
    perror("read");
    exit(1);
  }

  // Print the contents of the network packet
  printf("Received: %s\n", buf);

  // Close the socket
  close(sockfd);
  close(clientfd);

  return 0;
}
