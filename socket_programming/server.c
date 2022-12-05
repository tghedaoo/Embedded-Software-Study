// Socket Programming : SERVER
// service provider, processes client requests.
// 
// https://www.geeksforgeeks.org/socket-programming-cc/
// Steps:
// 1. Socket Creation.
// 2. Modify Socket Parameters (setsocketopt) (optional)
// 3. Bind Socket. (Attach address and port to that socket)
// 4. Listen. (Passive Mode. Wait for client to contact, refuse if queue full)
// 5. Accept. (extracts first in queue client request. new fd if connection established)
// 6. Data exchange.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>

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
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket creation failed.");
        exit(EXIT_FAILURE);
    }
    
    // 2. Modify Socket Parameters (optional), Promotes reusability.
    // int opt = 1;
    // if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) 
    // {
    //     perror("setsockopt failed.");
    //     exit(EXIT_FAILURE);
    // }

    // in <netinet/in.h>
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT); // htons. [host byte order to network byte order]

    // 3. Bind Socket to our address and port.
    if(bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("bind failed.");
        exit(EXIT_FAILURE);
    }

    // 4. Listen for client.
    if (listen(server_fd, 3) < 0)
    {
        perror("listen failed.");
        exit(EXIT_FAILURE);       
    }

    printf("Listening ... \n");

    // 5. Accept the connection. If successful, connection established.
    int address_len = sizeof(address);
    int new_socket = accept(server_fd,(struct sockaddr *)&address, (socklen_t*)&address_len);
    if(new_socket < 0 )
    {
        perror("listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Connection Established. \n");

    // 6. Data Exchange.
    // Important: Here new fd is used.

    char receive_buffer[1024] = { 0 };
    read(new_socket, receive_buffer, 1024);
    printf("Received: %s %lu\n", receive_buffer, strlen(receive_buffer));

    char* send_msg = "haan [Yes]";
    if(send(new_socket, send_msg, strlen(send_msg), 0) != strlen(send_msg))
    {
        perror("Send failed.");
        exit(EXIT_FAILURE);
    }
    printf("Server: Sent Msg\n");
    
    close(new_socket);
    shutdown(server_fd, SHUT_RDWR);

    exit(EXIT_SUCCESS);
}