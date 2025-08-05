#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

void datasSocket()
{
    int sockfd;
    struct sockaddr_in sa, client_sa;
    socklen_t client_len;
    char buffer[1024];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return;
    }
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        close(sockfd);
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
    
    while (1) {
        printf("Waiting for message....\n");
        
        socklen_t client_len = sizeof(client_sa);
        int received_bytes = recvfrom(sockfd, buffer, sizeof(buffer)-1, 0, (struct sockaddr *)&client_sa, &client_len);
        if (received_bytes == -1) {
            perror("bind");
            close(sockfd);
            return;
        }
        if (received_bytes == 0) {
            printf("Connection closed by server\n");
            close(clientfd);
            close(sockfd);
            return;
        }
        if (received_bytes > 0) {
            buffer[received_bytes] = '\0';
            printf("Message Received : %s\n", buffer);
            
            buffer[received_bytes] = '\0';
            for (int i = 0; i < received_bytes; i++) {
                buffer[i] = toupper(buffer[i]);
            }
        }
    }
    
    close(sockfd);
    return;
}
