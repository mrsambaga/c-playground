#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

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

//Guess The Number Game Challenge
void guessNumber()
{
    time_t t;
    srand((unsigned) time(&t));
    int selectedNumber = rand() % 21;
    int maxTries = 5;
    int guessedNumber = 0;
    
    printf("This is a guessing game.\n");
    printf("I have chosen a number between 0 and 20 which you must guess\n");
    
    while (0 < maxTries)
    {
        printf("You have %d tries left\n", maxTries);
        printf("Enter a guess : ");
        scanf("%d", &guessedNumber);
        
        if (guessedNumber > 20 || guessedNumber < 0)
        {
            printf("Invalid number, please enter number between 0 and 20\n");
            continue;
        }
        if (guessedNumber == selectedNumber)
        {
            printf("Congratulations. You guessed it!\n");
            break;
        }
        if (guessedNumber < selectedNumber)
        {
            printf("Sorry, %d is wrong. My number is higher than that\n", guessedNumber);
        }
        if (guessedNumber > selectedNumber)
        {
            printf("Sorry, %d is wrong. My number is less than that\n", guessedNumber);
        }
        
        maxTries--;
        
        if (maxTries == 0)
        {
            printf("Sorry, you lost\n");
        }
    }
}

void arrays()
{
    int grades[10];
    int count = 10;
    long sum = 0;
    
    printf("Enter the 10 grades:\n");
    
    for(int i=0; i<count; i++)
    {
        printf("%2u> :", i+1);
        scanf("%d", &grades[i]);
        sum += grades[i];
    }
    
    printf("Your average grade is : %.2f\n", (float) sum/count);
    
    //initialized array
    int gradesInitialized[10] = {80,70,90,40,50,30,50,100,100,70};
    printf("Grades initialized : %d", gradesInitialized[0]);
}

//Find prime numbers challenge
void findPrimeNumbers()
{
    printf("The prime numbers between 3-100 is : \n");
    int primeNumbers[100] = {2,3};
    int arrayLength = 2;
    
    for (int i = 4; i <= 100; i++)
    {
        printf("Hello %d\n", i);
        for (int y = 0; y < arrayLength; y++)
        {
            if (i % primeNumbers[y] == 0)
            {
                break;
            }
            
            if (y == arrayLength-1)
            {
                primeNumbers[y+1] = i;
                arrayLength++;
            }
        }
    }
        
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d\n", primeNumbers[i]);
    }
}

//Calculate Average Rainfall Challenge
void calculateRainfall()
{
    int years[5] = {2010, 2011, 2012, 2013, 2014};
    float rainfalls[5][12] = {
        {2.1, 4.3, 1.1, 3.4, 0.8, 2.7, 4.9, 1.5, 3.8, 0.2, 2.5, 4.6},
        {0.9, 3.1, 4.8, 2.2, 1.7, 0.6, 3.9, 4.2, 1.3, 2.8, 0.7, 3.5},
        {4.4, 1.9, 0.3, 3.6, 2.0, 4.1, 1.2, 3.3, 0.5, 4.7, 2.4, 1.0},
        {3.2, 0.1, 2.6, 4.0, 1.4, 3.0, 2.3, 0.0, 4.5, 1.8, 3.7, 2.9},
        {1.6, 4.2, 3.5, 0.7, 2.9, 1.2, 4.6, 2.1, 0.4, 3.3, 1.9, 4.8}
    };
    float totalYearlyRainfalls[5] = {0};
    float sumRainfalls = 0.0;
    
    printf("YEAR RAINFALL\n");
            
    for (int i = 0; i < 5; i++) {
        for (int l = 0; l < 12; l++) {
            totalYearlyRainfalls[i] += rainfalls[i][l];
        }
        
        sumRainfalls += totalYearlyRainfalls[i];
        printf("%d %.1f\n", years[i], totalYearlyRainfalls[i]);
    }
        
    printf("The yearly average is %.1f inches.\n", sumRainfalls / 5);
    
    
    float totalMonthlyRainfalls[12] = {0};

    printf("MONTHLY AVERAGES: \n");
    printf("Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec\n");
    
    for (int i = 0; i < 12; i++) {
        for (int l = 0; l < 5; l++) {
            totalMonthlyRainfalls[i] += rainfalls[l][i];
        }
        
        printf("%.1f ", totalMonthlyRainfalls[i] / 5);
    }
    
    printf("\n");
}

int main(int argc, char **argv)
{
//    printName("Sam");
//    printAndInputNumber();
//    dataTypes();
//    printRectangle();
//    operators();
//    convertMinutesToDayAndYear();
//    bitwiseOperation();
//    dataTypeSize();
//    calculateWeeklyPay();
//    switchStatement();
//    guessNumber();
//    arrays();
//    findPrimeNumbers();
    calculateRainfall();
        
    return 0;
}