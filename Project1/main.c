#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "basic.h"
#include "arrays.h"
#include "functions.h"
#include "tictactoe.h"
#include "loop.h"
#include "conditionalStatement.h"

void pointers()
{
    int count = 10, x;
    int *int_pointer;
    
    int_pointer = &count;
    x = *int_pointer;
    
    printf("count = %i, x=%i\n", count, x); //print value
    printf("count = %p, x=%p\n", &count, &x); //print address
    printf("int_pointer = %d\n", *int_pointer); //dereference pointer
    printf("int_pointer = %p\n", &int_pointer); //pointer address
    printf("int_pointer = %p\n", int_pointer); //pointer value (address of count)
}

void pointerChallenge()
{
    int count = 100;
    int *pCount = NULL;
    
    pCount = &count;
    
    printf("Count address = %p\n", &count); 
    printf("Count value = %d\n", count);
    
    printf("pCount address = %p\n", &pCount); 
    printf("pCount value = %p\n", pCount);
    printf("pCount dereference = %d\n", *pCount);
}

void swapPointer(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    
    return;
}

void swapValue(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    
    return;
}

void swap()
{
    int a = 100;
    int b = 200;
    
    printf("Value a before swap : %d\n", a);
    printf("Value b before swap : %d\n", b);
    
    swapValue(a, b);
    
    printf("Value a after swap : %d\n", a);
    printf("Value b after swap : %d\n", b);
}

int main(int argc, char **argv)
{
    swap();
    return 0;
}