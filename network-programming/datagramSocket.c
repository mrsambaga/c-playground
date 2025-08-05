#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

//Demonstrates UDP connection with datagram socket server
//Socket initialized with SOCK_DGRAM
//Server then received without using listen and accept
//Server receive message, upper case it, then send back to client
void datagramSocketServer()
{
    int sockfd;
    struct sockaddr_in sa, client_sa;
    char buffer[1024];
    int opt = 1;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return;
    }
    
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (bind(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("bind");
        close(sockfd);
        return;
    }
    
    while (1) {
        printf("Waiting for message....\n");
        
        memset(&client_sa, 0, sizeof(client_sa));
        socklen_t client_len = sizeof(client_sa);
        int received_bytes = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr *)&client_sa, &client_len);
        if (received_bytes == -1) {
            perror("recvfrom");
            close(sockfd);
            return;
        }
        if (received_bytes == 0) {
            printf("Connection closed by server\n");
            close(sockfd);
            return;
        }
        if (received_bytes > 0) {
            buffer[received_bytes] = '\0';
            printf("Received from %s:%d: %s\n", inet_ntoa(client_sa.sin_addr), ntohs(client_sa.sin_port), buffer);
            
            for (int i = 0; i < received_bytes; i++) {
                buffer[i] = toupper(buffer[i]);
            }
        }
        
        if (sendto(sockfd, buffer, received_bytes, 0, (struct sockaddr *)&client_sa, client_len) == -1) {
            perror("sendto");
        }
    }
    
    return;
}

//Demonstrates UDP connection with datagram socket client
//Socket initialized with SOCK_DGRAM
//Client send message, then receive back the same message in upper case
void datagramSocketClient()
{
    int sockfd;
    struct sockaddr_in sa, server_sa;
    char buffer[1024];
    const char *msg = "hello world\n";
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_port = htons(8080);
    sa.sin_addr.s_addr = inet_addr("127.0.0.1");
    
    if (sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror("sendto");
        close(sockfd);
        return;
    }
    
    socklen_t server_len = sizeof(server_sa);
    int received_bytes = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr *)&server_sa, &server_len);
    if (received_bytes == -1) {
        perror("recvfrom");
        close(sockfd);
        return;
    }
    
    buffer[received_bytes] = '\0';
    printf("Received from %s:%d: %s\n", inet_ntoa(server_sa.sin_addr), ntohs(server_sa.sin_port), buffer);

    close(sockfd);
    return;
}
