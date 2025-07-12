#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    bool isDone = false;
    char input[BUFFER_SIZE];
    
    while (!isDone)
    {
        scanf("%s", input);
        
        if (strcmp(input, "end") == 0){
            isDone = true;
        }
    }
    
	return 0;
}
