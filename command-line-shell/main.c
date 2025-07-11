#include <stdio.h>
#include <stdbool.h>
#include <string.h> 

int main(int argc, char **argv)
{
    bool isDone = false;
    char input[20];
    
    while (!isDone)
    {
        scanf("%s", input);
        
        if (strcmp(input, "end") == 0){
            isDone = true;
        }
    }
    
	return 0;
}
