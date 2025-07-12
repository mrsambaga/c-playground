#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    char input[BUFFER_SIZE];
    
    while (1)
    {
        printf("$ ");
        fflush(stdout);
        
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        printf("You entered: %s\n", input);
        
        if (strcmp(input, "end") == 0){
            break;
        }
    }
    
	return 0;
}
