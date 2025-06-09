#include <stdio.h>

void printName(const char *name)
{
    printf("Hello my name is %s\n", name);
}


int main(int argc, char **argv)
{
    printName("Sam");
    
	int myFavoriteNumber = 0;
    
    printf("Please enter your favorite number\n");
	scanf("%d", &myFavoriteNumber);
    printf("You entered number : %d\n", myFavoriteNumber);
    
    return 0;
}