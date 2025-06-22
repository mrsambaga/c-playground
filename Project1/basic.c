#include <stdio.h>
#include <stdbool.h>

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

//Challenge Time Conversion
void convertMinutesToDayAndYear()
{
    double day = 60 * 24;
    double year = day * 365;
    int minutesInput;
    
    printf("Enter minutes : ");
    scanf("%d", &minutesInput); 
    
    printf("Minutes in days : %e\n", minutesInput / day);
    printf("Minutes in year : %e\n", minutesInput / year);
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

void bitwiseOperation()
{
    unsigned int a = 13; //0000 1101
    int result = 0;
    
    result = a << 2; //0011 0100
    
    printf("result %d\n", result);
}

//Challenge Data Type Size
void dataTypeSize()
{
    printf("int byte size : %zd\n", sizeof(int));
    printf("char byte size : %zd\n", sizeof(char));
    printf("long byte size : %zd\n", sizeof(long));
    printf("double byte size : %zd\n", sizeof(double));
}