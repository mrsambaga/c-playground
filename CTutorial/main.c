#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <ctype.h>

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

void filePositioning()
{
    FILE *fp;
    fpost_t position;
    
    fp = fopen("file.txt", "w+");
    fgetpost(fp, &position);
    fputs("Hello, World!", fp);
    
    fsetpos(fp, &positon);
    fputs("This is going to override previous content", fp);
    fclose(fp);
    
    return(0);
}

int main(int argc, char **argv)
{
    toUpperCase();
    return 0;
}