#include <stdio.h>
#include <stdbool.h>
#include <string.h> 
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024
#define ARG_SIZE 64

void executeCommand(char *args[]) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        return;
    }
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("exec failed");
        }
        return;
    }
    
    int status;
    waitpid(pid, &status, 0);
}

int main(int argc, char **argv)
{
    char input[BUFFER_SIZE];
    char *args[ARG_SIZE];
    int i = 0;
    
    while (1)
    {
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
        
        char *token = strtok(input, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        
        if (i > 0) {
            printf("Command: %s\n", args[0]);
            for (int j = 1; j < i; j++) {
                printf("Arg %d: %s\n", j, args[j]);
            }
        }
        
        executeCommand(args);
    }
    
	return 0;
}
