#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "basic.h"
#include "arrays.h"
#include "functions.h"
#include "tictactoe.h"
#include "loop.h"
#include "conditionalStatement.h"

void strings()
{
    char myString[] = "Hello World !";
    char temp[50];
    
    printf("String : %s has length : %ld\n", myString, strlen(myString));
    
    strncpy(temp, myString, sizeof(temp)-1);
    printf("The copied string : %s\n", temp);
    
    printf("strcmp(myString, temp) is %d\n", strcmp(myString, temp)); 
}

int main(int argc, char **argv)
{
    calculateWeeklyPay();

    return 0;
}