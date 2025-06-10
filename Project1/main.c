#include <stdio.h>
#include <stdbool.h>

void printName(const char *name)
{
    printf("Hello my name is %s\n", name);
}

void printAndInputNumber() 
{
    int myFavoriteNumber = 0;
    printf("Please enter your favorite number\n");
	scanf("%d", &myFavoriteNumber);
    printf("You entered number : %d\n", myFavoriteNumber);
}

void dataTypes()
{
    int integerData = 1;
    float floatData = 5.33;
    bool boolData = true;
    long longData = 100000000000000;
    double doubleData = 5.333333333333333333;
}

int main(int argc, char **argv)
{
    printName("Sam");
    printAndInputNumber();
        
    return 0;
}