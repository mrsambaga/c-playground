#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

//Creating client send & receive message to socket connection
void createClient()
{
    int sockfd;
    struct sockaddr_in sa;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("connect");
        close(sockfd);
        return;
    }
    
    const char msg_sent[1024] = "Hello, world!\n";    
    ssize_t sent_bytes = send(sockfd, msg_sent, strlen(msg_sent), 0);
    if (sent_bytes == -1) {
        perror("send");
        close(sockfd);
        return;
    }
    
    char msg_recv[1024];
    int receive_bytes = recv(sockfd, msg_recv, sizeof(msg_recv)-1, 0);
    if (receive_bytes == -1) {
        perror("send");
    }
    if (receive_bytes == 0) {
        printf("Connection closed by server\n");
    }
    if (receive_bytes > 0) {
        msg_recv[receive_bytes] = '\0';
        printf("Message Received : %s\n", msg_recv);
    }
    
    close(sockfd);
    return;
}

//Create server send and receive message from a client
void createServer()
{
    int sockfd, clientfd;
    struct sockaddr_in sa, client_sa;
    socklen_t client_len = sizeof(client_sa);
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("bind");
        close(sockfd);
        return;
    }
    
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        close(sockfd);
        return;
    }
    
    printf("Listening...\n");
    clientfd = accept(sockfd, (struct sockaddr *)&client_sa, &client_len);
    if (clientfd == -1) {
        perror("accept");
        close(sockfd);
        return;
    }
    
    printf("Client connected: %s:%d\n", inet_ntoa(client_sa.sin_addr), ntohs(client_sa.sin_port));
    
    char msg_recv[1024];
    int receive_bytes = recv(clientfd, msg_recv, sizeof(msg_recv)-1, 0);
    if (receive_bytes == -1) {
        perror("send");
        close(clientfd);
        close(sockfd);
        return;
    }
    if (receive_bytes == 0) {
        printf("Connection closed by server\n");
        close(clientfd);
        close(sockfd);
        return;
    }
    if (receive_bytes > 0) {
        msg_recv[receive_bytes] = '\0';
        printf("Message Received : %s\n", msg_recv);
        
        msg_recv[receive_bytes] = '\0';
        for (int i = 0; i < receive_bytes; i++) {
            msg_recv[i] = toupper(msg_recv[i]);
        }
    }

    ssize_t sent_bytes = send(clientfd, msg_recv, strlen(msg_recv), 0);
    if (sent_bytes == -1) {
        perror("send");
    }
    
    sleep(1);
    close(clientfd);
    close(sockfd);
    return;
}


//Bind a socket
void bindSocket()
{
    int sockfd;
    struct sockaddr_in sa;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("bind");
        close(sockfd);
        return;
    }
    
    printf("Bound successfully\n");

    close(sockfd);
    return;
}

//Port to byte order & byte to port convertion
void networkCovertion()
{
    uint16_t port = 8080;
    uint16_t net_port = htons(port);
    
    printf("Original port number : %u\n", port);
    printf("Host to network byte convertion : 0x%04X\n", net_port);
    printf("Network byte to host convertion : %u\n", ntohs(net_port));
    return;
}

//Ip address to byte order & byte to address convertion
void ipAddressConvertion()
{
    char ip_str[12];
    struct in_addr addr;
    
    printf("Enter ip address : ");
    scanf("%s", ip_str);
    
    addr.s_addr = inet_addr(ip_str);
    
    
    if (addr.s_addr == INADDR_NONE) {
        printf("Invalid IP: %s\n", ip_str);
    } else {
        printf("IP string: %s\n", ip_str);
        printf("Network-ordered binary (hex): 0x%08X\n", addr.s_addr);
        
        char *back_to_str = inet_ntoa(addr);
        printf("Back to IP string: %s\n", back_to_str);
    }
    
    return;
}

//Implementation of socket address struct for socket
void sockAddrStruct()
{
    struct sockaddr_in addr;
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    
    printf("Address family: %d (AF_INET=%d)\n", addr.sin_family, AF_INET);
    printf("Port (host order): %u\n", ntohs(addr.sin_port));
    printf("IP address: %s\n", inet_ntoa(addr.sin_addr));
    
    return;
}

int main(int argc, char **argv)
{
	createClient();
	return 0;
}
