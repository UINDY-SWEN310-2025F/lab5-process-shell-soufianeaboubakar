#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t cpid = fork();

    if (cpid < 0) {
    
        printf("Fork Failed\n");
        return 1;
    } 
    else if (cpid == 0) {
        
        execlp("/bin/ls", "ls", "-lt", NULL);
       
        printf("execlp failed\n");
        exit(1);
    } 
    else {
    
        waitpid(cpid, NULL, 0);
        printf("Child process is done\n");
    }

    return 0;
}
