#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#include "basicSocket.h"
#include "concurrentNetwork.h"


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

int main(int argc, char **argv)
{
	concurrentServer();
	return 0;
}
