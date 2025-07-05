#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void dynamicMemoryAllocation()
{
    char *str = NULL;
    
    str = (char *) malloc(15);
    strcpy(str, "Hello");
    printf("String: %s, Address: %p\n", str, str);
    
    str = (char *) realloc(str, 25);
    strcpy(str, "Hello World");
    printf("String: %s, Address: %p\n", str, str);
        
    free(str);
}

void malocChallenge()
{
    int size;
    char *text = NULL;
    printf("Please enter a memory size: ");
    scanf("%d", &size);
    
    text = (char *)malloc(size * sizeof(char));
    
    printf("Please enter a text: ");
    scanf("%s", text);
    
    printf("Your text: %s\n", text);
    
    free(text);
}