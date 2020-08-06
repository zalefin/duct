#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <string.h>

#define MAXLINE 1024
#define PORT 8080

int main(int argc, char **argv) {
    int sock_fd;
    char buffer[MAXLINE];

    int port = atoi(argv[1]);

    // 1. create UDP socket
    socket(AF_INET, SOCK_DGRAM, 0);
    // 2. bind the socket to server address
    // 3. wait until datagram packet arrives from client
    // 4. process the datagram and send reply to client
    // 5. go back to step 3

    return 0;
}
