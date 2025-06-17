#include <stdio.h>
#include <stdbool.h>

_Bool isNegativeNumber(int number);
int calculateCommonDivisor(int firstNumber, int secondNumber);

//Greatest Common Divisor
void greatestCommonDivisor()
{
    int firstNumber = 0;
    int secondNumber = 0;
    
    printf("Enter your first number : ");
    scanf("%d", &firstNumber);
    printf("Enter your second number : ");
    scanf("%d", &secondNumber);
    
    if (isNegativeNumber(firstNumber) || isNegativeNumber(secondNumber))
    {
        printf("Invalid number! Cannot be negative\n");
        return;
    }
    
    int commonDivisor = 0;
    commonDivisor = calculateCommonDivisor(firstNumber, secondNumber);
    printf("The greatest common divisor is : %d\n", commonDivisor);
}

_Bool isNegativeNumber(int number)
{
    return number < 0;
}

int calculateCommonDivisor(int firstNumber, int secondNumber)
{
    while(firstNumber != secondNumber)
    {
        if (firstNumber > secondNumber)
        {
            firstNumber -= secondNumber;
            continue;
        }
        
        secondNumber -= firstNumber;
    }
    
    return firstNumber;
}