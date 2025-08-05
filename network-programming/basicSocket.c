#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// Demonstrates conversion of port numbers between host and network byte order
// Uses htons() for host-to-network and ntohs() for network-to-host conversion
void networkCovertion()
{
    uint16_t port = 8080;
    uint16_t net_port = htons(port);
    
    printf("Original port number : %u\n", port);
    printf("Host to network byte convertion : 0x%04X\n", net_port);
    printf("Network byte to host convertion : %u\n", ntohs(net_port));
    return;
}

// Converts IP addresses between string and binary formats
// Uses inet_addr() for string-to-binary and inet_ntoa() for binary-to-string
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

// Initializes and displays a socket address structure for IPv4
// Configures sockaddr_in with family, port, and IP address
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