#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void networkCovertion()
{
    uint16_t port = 8080;
    uint16_t net_port = htons(port);
    
    printf("Original port number : %u\n", port);
    printf("Host to network byte convertion : 0x%04X\n", net_port);
    printf("Network byte to host convertion : %u\n", ntohs(net_port));
    return;
}

void ipAddressConvertion()
{
    const char *ip_str = "192.168.1.1";
    struct in_addr addr;
    
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

int main(int argc, char **argv)
{
	networkCovertion();
	return 0;
}
