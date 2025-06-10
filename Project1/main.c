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
    //Basic
    int integerData = 1;
    float floatData = 5.33;
    bool boolData = true;
    long longData = 100000000000000;
    double doubleData = 5.33e+10;
    
    //Enum
    enum gender {male, female};
    enum gender myGender = male;
        
    //Character
    char myCharacter = 'X';
    
    printf("%c\n", myCharacter);
    printf("%i\n", integerData);
    printf("%f\n", floatData);
    printf("%e\n", doubleData);
    printf("%ld\n", longData);
    printf("%d\n", myGender); 
    printf("%i", boolData);
}

int main(int argc, char **argv)
{
    printName("Sam");
    printAndInputNumber();
    dataTypes();
        
    return 0;
}