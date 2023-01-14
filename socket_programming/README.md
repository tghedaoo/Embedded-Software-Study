# SOCKET PROGRAMMING

## **Client - Server Setup**
Inter host communication on a network in a client/server fashion. <br />
[Server Code](server.c) <br />
**Steps:**
1. Socket Creation.
2. Modify Socket Parameters (setsocketopt) (optional)
3. Bind Socket. (Attach address and port to that socket)
4. Listen. (Passive Mode. Wait for client to contact, refuse if queue full)
5. Accept. (extracts first in queue client request. new fd if connection established)
6. Data exchange. 

[Client Code](client.c) <br />
**Steps:**
1. Socket Creation.
2. Connect to Server.
3. Data exchange.

Inter Process Communication in the case of same host. AF_INET (Address Family) & "127.0.0.1". <br />
```
#include <sys/socket.h>
#include <netinet/in.h> // for struct sockaddr_in
#include <arpa/inet.h>  // for inet_pton
```

**Links:**<br />
https://www.geeksforgeeks.org/socket-programming-cc/ <br />
https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/ <br />

## **TCP vs UDP**
These protocols can be chosen during socket creation.
[Sources](https://www.lifesize.com/blog/tcp-vs-udp/#:~:text=TCP%20is%20a%20connection%2Doriented,is%20only%20possible%20with%20TCP)
### Transmission Control Protocol (TCP)
* Reliable and connection-oriented. Transmission after connection. (connect, maintain, terminate)
* Built-in system to check for errors and guarantees data delivery. But slow.
* Cons: Large overhead due to feedback.
* For web, data, images which require precision.
* http, https, ftp, smtp etc.
### User Datagram Protocol (UDP)
* Send data continuously irrespective of connection and reliability. 
* No guarantee. No retransmission. But fast.
* No overhead, error-checking (need checksum) and recovery.
* real-time comms ok. streaming, video/audio transmission etc.

