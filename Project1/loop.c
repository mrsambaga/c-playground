#include <time.h>
#include <stdio.h>

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