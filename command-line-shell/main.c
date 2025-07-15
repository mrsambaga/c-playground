#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> 
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define ARG_SIZE 64

void tokenizeInput(int *argCount, char input[], char *args[]) {
    char *token = strtok(input, " ");
    while (token != NULL) {
        args[(*argCount)++] = token;
        token = strtok(NULL, " ");
    }
    args[*argCount] = NULL;
} 

void printCommandAndArgument(int argCount, char *args[]) {
    if (argCount > 0) {
        printf("Command: %s\n", args[0]);
        for (int argIndex = 1; argIndex < argCount; argIndex++) {
            printf("Arg %d: %s\n", argIndex, args[argIndex]);
        }
    }
}

void executeCommand(char *args[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return;
    }
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("exec failed");
            exit(EXIT_FAILURE);
        }
        return;
    }
    
    int status;
    waitpid(pid, &status, 0);
}

int main(int argc, char **argv)
{
    char input[BUFFER_SIZE];
    
    while (1)
    {
        char *args[ARG_SIZE];
        int i = 0;
    
        printf("$ ");
        fflush(stdout);
        
        if (fgets(input, BUFFER_SIZE, stdin) == NULL) {
            printf("\n");
            break;
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        printf("You entered: %s\n", input);
        
        if (strcmp(input, "end") == 0){
            break;
        }
        
        tokenizeInput(&i, input, args);
        printCommandAndArgument(i, args);
        executeCommand(args);
    }
    
	return EXIT_SUCCESS;
}
