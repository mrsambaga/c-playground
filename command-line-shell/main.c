#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    char input[BUFFER_SIZE];
    
    while (1)
    {
        scanf("%s", input);
        
        if (strcmp(input, "end") == 0){
            break;
        }
    }
    
	return 0;
}
