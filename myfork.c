#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {

pid_t cpid_a, cpid_b;

cpid_a = fork();
if(cpid_a < 0) {
    std::cout << "Fork failed." << '\n';
    return 1;
}
else if(cpid_a == 0) { // code for child process A
    execlp("/bin/ls", "ls", NULL);

    cpid_b = fork();
    if(cpid_b < 0) {
        std::cout << "Fork failed." << '\n';
        return 1;
    }
    else if(cpid_a == 0) { // code for child process A
    execlp("/bin/ls", "ls", NULL);
    exit(1);
  } else {
    cpid_b = fork();

  // The rest of the code.
return 0;
}

