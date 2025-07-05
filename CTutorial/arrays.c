#include <stdio.h>

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