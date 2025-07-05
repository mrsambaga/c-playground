#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strings()
{
    char myString[] = "Hello World !";
    char temp[50];
    
    printf("String : %s has length : %ld\n", myString, strlen(myString));
    
    strncpy(temp, myString, sizeof(temp)-1);
    printf("The copied string : %s\n", temp);
    
    printf("strcmp(myString, temp) is %d\n", strcmp(myString, temp)); 
}
