#include <stdio.h>
#include <stdlib.h>

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