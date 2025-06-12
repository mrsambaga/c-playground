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
    printf("%i\n", boolData);
}

void printRectangle()
{
    double width = 1.5;
    double height = 2.1;
    printf("width = %.2f\n", width);
    printf("height = %.2f\n", height);
    printf("perimeter = %.2f\n", 2.0 * (width + height));
    printf("area = %.2f\n", (width * height));
}

void operators()
{
    int a = 10;
    int b = 33;
    _Bool c = 1;
    _Bool d = 0;
    
    int addition = a + b;
    int remainder = b % a;
    int increment = a++;
    _Bool boolean = c && d;
    
    printf("addition : %d\n", addition);
    printf("remainder : %d\n", remainder);
    printf("increment : %d\n", increment);
    printf("boolean : %d\n", boolean);
    
}


int main(int argc, char **argv)
{
    printName("Sam");
    printAndInputNumber();
    dataTypes();
    printRectangle();
    operators();
        
    return 0;
}