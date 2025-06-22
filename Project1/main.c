#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "basic.h"
#include "arrays.h"
#include "functions.h"
#include "tictactoe.h"
#include "loop.h"

//Challenge Weekly Pay
void calculateWeeklyPay() 
{
    int numberOfHours = 0;
    printf("How many hours do you works ? " );
    scanf("%d", &numberOfHours);

    int basicPayRate = 12;
    int overtime = basicPayRate * 1.5;
    float taxRateFirst300 = 0.15;
    float taxRateNext150 = 0.2;
    float taxRateTheRest = 0.25;
    
    float grossPay = 0;
    if (numberOfHours > 40) {
        grossPay = 40 * basicPayRate + (numberOfHours-40) * overtime;
    } else {
        grossPay = numberOfHours * basicPayRate;
    }
    
    float nettPay = grossPay;
    if (nettPay <= 300) {
        nettPay -= grossPay * taxRateFirst300;
    }
    if (nettPay > 300 && grossPay <= 450) {
        nettPay -= 300 * taxRateFirst300;
        nettPay -= (grossPay-300) * taxRateNext150;
    }
    if (nettPay > 450) {
        nettPay -= 300 * taxRateFirst300;
        nettPay -= 150 * taxRateNext150;
        nettPay -= (grossPay-450) * taxRateTheRest;
    }
    
    printf("Your gross salary is : %.2f\n", grossPay);
    printf("Your nett salary is : %.2f\n", nettPay);
}

void switchStatement()
{
    enum Weekday {Monday, Tuesday, Wednesday, Thursday, Friday};
    enum Weekday today = Monday;
    
    switch (today)
    {
        case Monday:
            printf("Today is monday");
            break;
        case Tuesday:
            printf("Today is tuesday");
            break;
        default:
            printf("Today is not a weekday");
    }
}

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
    dataTypes();

    return 0;
}