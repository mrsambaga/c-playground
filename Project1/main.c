#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

struct employee{
    char name[30];
    char hireDate[15];
    float salary;
};

struct item{
    char *name;
    int quantity;
    float price;
    float amount;
};

void structure()
{
    struct employee emp = {"Mikey", "7/16/2025", 1000000.0f};
    
    printf("Employee name %s\n", emp.name);
    printf("Employee name %s\n", emp.hireDate);
    printf("Employee name %.1f\n", emp.salary);
}

void printItem(struct item *inputItem)
{
    printf("Item name : %s\n", inputItem->name);
    printf("Item price : %.1f\n", inputItem->price);
    printf("Item quantity : %d\n", inputItem->quantity);
    printf("Item quantity : %.1f\n", inputItem->amount);
}

void readItem(struct item *inputItem)
{
    printf("Enter item name : ");
    scanf("%s", inputItem->name);
    printf("Enter item price : ");
    scanf("%f", &inputItem->price);
    printf("Enter item quantity : ");
    scanf("%d", &inputItem->quantity);
    
    inputItem->amount = (float) inputItem->quantity * inputItem->price;
}

void structureChallenge()
{
    struct item myItem;
    struct item *pItem;
    
    pItem = &myItem;
    pItem->name = (char *) malloc(30*sizeof(char));
    
    if(pItem == NULL)
        exit(-1);
    
    readItem(pItem);
    printItem(pItem);
    
    free(pItem->name);
}

void fileInputOutput()
{
    FILE *fp;
    int c;
    char str[11];
    
    fp = fopen("file.txt", "r");
    
    if (fp == NULL)
    {
        perror("File is null\n");
        return;
    }
    
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    
    rewind(fp);
    
    if ( fgets (str, 10, fp) != NULL) {
        printf("%s", str);
    }
    
    fclose(fp);
    fp = NULL;
    return;
}

void writeFile()
{
    FILE *fp;
    int c;
    
    fp = fopen("file.txt", "w+");
    
    if (fp == NULL)
    {
        perror("File is null\n");
        return;
    }
    
    fputs("Hello C\n", fp);
    fputs("Hello World", fp);
    rewind(fp);
    
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    
    fclose(fp);
    fp = NULL;
    return;
}

void countFileRow()
{
    FILE *fp;
    char c;
    int rowCount = 0;

    fp = fopen("rowCount.txt", "r");
    
    if (fp == NULL)
    {
        perror("File is null\n");
        return;
    }
    
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n'){
            rowCount++;
        }
    }
    
    printf("Total row : %d\n", ++rowCount);
    
    fclose(fp);
    fp = NULL;
    return;
}

void toUpperCase()
{
    FILE *fp;
    FILE *fp1;
    char c = ' ';

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("File is null\n");
        return;
    }
    
    fp1 = fopen("temp.txt", "w+");
    if (fp1 == NULL)
    {
        perror("File is null\n");
        return;
    }
    
    while ((c = fgetc(fp)) != EOF) {
        if (islower(c))
        {
            c = c-32;
        }
        fputc(c, fp1);
    }
    
    fclose(fp);
    fclose(fp1);
    
    remove("file.txt");
    rename("temp.txt", "file.txt");

    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("File is null\n");
        return;
    }
    
    while ((c = fgetc(fp)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    
    fclose(fp);
    return;
}

int main(int argc, char **argv)
{
    return 0;
}