#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>   

#define MAXARGS 20   
#define ARGLEN  100  

int execute(char *arglist[]);
char *makestring(char *buf);

int main(void) {
    char *arglist[MAXARGS + 1];  
    int numargs = 0;            
    char argbuf[ARGLEN];         

    while (numargs < MAXARGS) {
        printf("Arg[%d]? ", numargs);
        fflush(stdout);

        if (fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n') {
            arglist[numargs++] = makestring(argbuf);
        } else {
            if (numargs > 0) {
                arglist[numargs] = NULL;   
                execute(arglist);          
                numargs = 0;               
            }
        }
    }
    return 0;
}

int execute(char *arglist[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child process
        if (execvp(arglist[0], arglist) == -1) {
            perror("execvp failed");
            exit(1);
        }
    } 
    else {
        // Parent process waits
        waitpid(pid, NULL, 0);
    }

    return 0;
}

char *makestring(char *buf) {
    
    buf[strcspn(buf, "\n")] = '\0';  

    char *cp = malloc(strlen(buf) + 1);
    if (cp == NULL) {
        fprintf(stderr, "no memory\n");
        exit(1);
    }
    strcpy(cp, buf);
    return cp;
}
