#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); 

    if (pid < 0) {
   
        printf("Fork Failed\n");
        return 1;
    } else if (pid == 0) {
        
        if (execlp("ls", "ls", "-lt", (char *)NULL) == -1) {
            // execlp failed
            printf("Failed to execute ls -lt\n");
            return 1;
        }
    } else {
        
        wait(NULL);
        printf("Child process is done\n");
    }

    return 0;
}

