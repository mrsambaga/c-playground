#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

void square(int *x)
{
    *x = (*x) * (*x);
    return;
}

void squareNumber()
{
    int a = 10;
    
    printf("Value a before square : %d\n", a);
    
    square(&a);
    
    printf("Value a before square : %d\n", a);
}

void calculateLength(const char *ptr)
{
    int beginning = *ptr;
    int end = *ptr;
    while (*ptr)
        ++end,++ptr;
    
    printf("String length is %d\n", end - beginning);
    printf("Beginning address is %d\n", beginning);
    printf("End address is %d\n", end);
}

//void dynamicMemoryAllocation()
//{
//    char *str = NULL;
//    
//    str = (char *) malloc(15);
//    strcpy(str, "Hello");
//    printf("String: %s, Address: %p\n", str, str);
//    
//    str = (char *) realloc(str, 25);
//    strcpy(str, "Hello World");
//    printf("String: %s, Address: %p\n", str, str);
//        
//    free(str);
//}

//void malocChallenge()
//{
//    int size;
//    char *text = NULL;
//    printf("Please enter a memory size: ");
//    scanf("%d", &size);
//    
//    text = (char *)malloc(size * sizeof(char));
//    
//    printf("Please enter a text: ");
//    scanf("%s", text);
//    
//    printf("Your text: %s\n", text);
//    
//    free(text);
//}

struct employee{
    char name[30];
    char hireDate[15];
    float salary;
};

void structure()
{
    struct employee emp = {"Mikey", "7/16/2025", 1000000.0f};
    
    printf("Employee name %s\n", emp.name);
    printf("Employee name %s\n", emp.hireDate);
    printf("Employee name %.1f\n", emp.salary);
}

int main(int argc, char **argv)
{
    structure();
    return 0;
}