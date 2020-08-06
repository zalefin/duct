#include <stdio.h>
#include <stdlib.h>
/* #include <unistd.h> */
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>

#define MAXLINE 1024
#define PORT 8080

int main(int argc, char **argv) {
    int sock_fd;
    char buffer[MAXLINE];
    char *res = "hello";
    struct sockaddr_in servaddr, cliaddr;
    
    // 1. create UDP socket
    if((sock_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
	perror("socket creation failed");
	exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET; // IPV4
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    // 2. bind the socket to server address
    if(bind(sock_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
	perror("bind failed");
	exit(EXIT_FAILURE);
    }

    while(1) {
	unsigned len, n;
	len = sizeof(cliaddr);
	n = recvfrom(sock_fd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&cliaddr, &len);

	buffer[n] = '\0';
	printf("%s\n", buffer);
	sendto(sock_fd, (const char *)res, strlen(res), MSG_CONFIRM, (const struct sockaddr *)&cliaddr, len);
    }
    // 3. wait until datagram packet arrives from client
    // 4. process the datagram and send reply to client
    // 5. go back to step 3

    return 0;
}
