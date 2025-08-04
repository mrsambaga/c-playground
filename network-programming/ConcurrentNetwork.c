#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

//Process Multiple Client With Fork
void concurrentServer()
{
    int sockfd, clientfd;
    struct sockaddr_in sa, client_sa;
    int opt = 1;
    
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
    
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        close(sockfd);
        return;
    }
    
    while(1) {
        socklen_t client_len = sizeof(client_sa);
        clientfd = accept(sockfd, (struct sockaddr *)&client_sa, &client_len);
        if (clientfd == -1) {
            perror("accept");
            close(sockfd);
            return;
        }
        
        printf("Server: got connection from: %s\n", inet_ntoa(client_sa.sin_addr));
        
        if(!fork()) {
            close(sockfd);
             
            char msg[1024] = "Hello World !";
            ssize_t sent_bytes = send(clientfd, msg, strlen(msg), 0);
            if (sent_bytes == -1) {
                perror("send");
            }
            
            close(clientfd);
            exit(0);
        }
        close(clientfd);
    }
    
    return;
}

//private *get_in_addr(struct sockaddr *sa){
//    if (sa.sa_family == AF_INET) {
//        return &(((struct sockaddr_in*)sa).sin_addr);
//    }
//    return return &(((struct sockaddr_in6*)sa).sin6_addr);
//}