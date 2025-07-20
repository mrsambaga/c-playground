#include <stdio.h>
#include <netinet/in.h>

void networkCovertion()
{
    uint16_t port = 8080;
    uint16_t net_port = htons(port);
    
    printf("Original port number : %d\n", port);
    printf("Host to network byte convertion : %d\n", net_port);
    printf("Network byte to host convertion : %d\n", ntohs(net_port));
    return;
}

int main(int argc, char **argv)
{
	networkCovertion();
	return 0;
}
