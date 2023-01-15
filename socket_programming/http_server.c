#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define PORT 5001

bool is_num(char input)
{
    if (((input - '0') >= 0) && ((input - '0') <= 9))
        return true;
    return false;
}

int parse_value(char *input)
{
    int res = 0;

    int iter = 0;
    while (input[iter] != '\0')
    {
        res = 10 * res + (input[iter] - '0');
        ++iter;
    }

    return res;
}

int main()
{
    // Creating Socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        perror("socket creation");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    int addr = inet_pton(AF_INET, "127.0.0.1", &address.sin_addr.s_addr);
    if (addr <= 0)
    {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }
    // address.sin_addr.s_addr = INADDR_LOOPBACK; // Chekc this
    address.sin_port = htons(PORT);

    // Bind
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Listen
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Accept
    int sizeof_address = sizeof(address);
    int connection_socket_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&sizeof_address);
    if (connection_socket_fd < 0)
    {
        perror("connection");
        exit(EXIT_FAILURE);
    }

    // Data Exchange
    printf("Connection Established.\n");

    char *msg = "HTTP/1.0 200 OK\n";
    send(connection_socket_fd, msg, strlen(msg), 0);

    while (1)
    {
        char receive_buffer[50] = {0};
        // Read request get inputs.
        if (read(connection_socket_fd, receive_buffer, 50) < 0)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }

        // Parse request.
        int a = 0;
        char a_num[10]; // 10 digits.

        int b = 0;
        char b_num[10]; // 10 digits.
        for (int iter = 0; receive_buffer[iter] != '\0'; iter++)
        {
            // parses out a.
            if (receive_buffer[iter] == 'a')
            {
                // TODO : put this in a function.
                iter = iter + 2;
                int num_iter = 0;
                while (is_num(receive_buffer[iter]))
                {
                    a_num[num_iter] = receive_buffer[iter];
                    ++iter;
                    ++num_iter;
                }
                a_num[num_iter] = '\0';
                a = parse_value(a_num);
            }

            if (receive_buffer[iter] == 'b')
            {
                // TODO : put this in a function.
                iter = iter + 2;
                int num_iter = 0;
                while (is_num(receive_buffer[iter]))
                {
                    b_num[num_iter] = receive_buffer[iter];
                    ++iter;
                    ++num_iter;
                }
                b_num[num_iter] = '\0';
                b = parse_value(b_num);
            }
        }

        printf("a = %d\n", a);
        printf("b = %d\n", b);
        int sum = (a + b);
        printf("sum = %d\n", sum);

        // Write output
        char send_buffer[10] = {0};
        int iter_sb = 0;
        while (sum > 0)
        {
            int digit = sum % 10;
            send_buffer[iter_sb] = digit + '0';
            sum /= 10;
            ++iter_sb;
        }
        send_buffer[iter_sb] = '\n';
        send_buffer[iter_sb + 1] = '\0';
        // convert here to network byte order
        send(connection_socket_fd, send_buffer, strlen(send_buffer), 0);
    }

    return 0;
}