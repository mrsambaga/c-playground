#include <stdio.h>
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
            if(send(new_fd, "Hello, World", 13, 0) == -1) {
                perror("send");
            }
            close(new_fd);
            exit(0);
        }
        close(new_fd);
    }
    
    return 0;
}

//private *get_in_addr(struct sockaddr *sa){
//    if (sa.sa_family == AF_INET) {
//        return &(((struct sockaddr_in*)sa).sin_addr);
//    }
//    return return &(((struct sockaddr_in6*)sa).sin6_addr);
//}