// Socket Programming : CLIENT
// Request service from server.
//
// https://www.geeksforgeeks.org/socket-programming-cc/
// Steps:
// 1. Socket Creation.
// 2. Connect to Server.
// 3. Data exchange.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for read.
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h> // for struct sockaddr_in
#include <arpa/inet.h>  // for inet_pton

#define PORT 8080

int main()
{
    // 1. Socket Creation.
    // -------------------
    // * Domain:
    //  AF_LOCAL -> C POSIX same host communcation. (IPC)
    //  AF_INET - IPV4 and AF_INET6 - IPV6
    // * Type: (Protocol)
    // https://www.lifesize.com/blog/tcp-vs-udp/#:~:text=TCP%20is%20a%20connection%2Doriented,is%20only%20possible%20with%20TCP.
    //  SOCK_STREAM -- TCP -> Transmission Control. Connection based. Secure.
    //  SOCK_DGRAM -- UDP -> User Datagram. Connectionless. Unsecure. Simple.
    // * Protocol: 0
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0)
    {
        perror("socket creation failed.");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    // convert IPv4 and IPv6 addresses from text to binary form.
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0)
    {
        perror("Address Invalid.");
        exit(EXIT_FAILURE);
    }
    server_address.sin_port = htons(PORT);

    int client_fd = connect(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    if(client_fd < 0)
    {
        perror("Connection failed.");
        exit(EXIT_FAILURE);
    }

    printf("Connection Established. \n");

    // 6. Data Exchange.
    // Important: Here old fd is used.

    char* send_msg = "sun raha hai na tu [are you listening]"; 
    if(send(socket_fd, send_msg, strlen(send_msg), 0) != strlen(send_msg))
    {
        perror("Send failed.");
        exit(EXIT_FAILURE);
    }
    printf("Client: Msg Sent\n");
    
    char receive_buffer[1024] = {0};
    read(socket_fd, receive_buffer, 1024);
    printf("Received: %s\n", receive_buffer);
    
    close(client_fd);
    close(socket_fd);

    exit(EXIT_SUCCESS);
}