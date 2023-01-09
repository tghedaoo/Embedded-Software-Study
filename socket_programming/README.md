# SOCKET PROGRAMMING

Inter host communication on a network in a client/server fashion. <br />
Inter Process Communication in the case of same host. AF_INET (Address Family) & "127.0.0.1". <br />
```
#include <sys/socket.h>
#include <netinet/in.h> // for struct sockaddr_in
#include <arpa/inet.h>  // for inet_pton
```
See notes in code [socket_programming folder]
Links:<br />
https://www.geeksforgeeks.org/socket-programming-cc/ <br />
https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/ <br />
*TCP vs UDP*
https://www.lifesize.com/blog/tcp-vs-udp/#:~:text=TCP%20is%20a%20connection%2Doriented,is%20only%20possible%20with%20TCP.