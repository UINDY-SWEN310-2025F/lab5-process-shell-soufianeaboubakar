#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAXARGS 20   /* cmdline args */
#define ARGLEN  100  /* token length */

int execute(char *arglist[]);
char *makestring(char *buf);

int main(int argc, char *argv[]) {
    char *arglist[MAXARGS + 1];  /* array of pointers to args */
    int numargs;                 /* index into array */
    char argbuf[ARGLEN];         /* buffer for reading input */

    /* --- Non-interactive test mode --- */
    if (argc > 1 && strcmp(argv[1], "--test") == 0) {
        char *test_args[] = {"ls", "-l", NULL};
        execute(test_args);
        exit(0);
    }

    numargs = 0;

    while (numargs < MAXARGS) {
        printf("Arg[%d]? ", numargs);
        fflush(stdout);

        if (fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n') {
            arglist[numargs++] = makestring(argbuf);
        } else {
            if (numargs > 0) {
                arglist[numargs] = NULL;   /* close list */
                execute(arglist);          /* run command */
                numargs = 0;               /* reset for next command */
            }
        }
    }
    return 0;
}

/* --- Create new process and execute command --- */
int execute(char *arglist[]) {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0) {
        execvp(arglist[0], arglist);
        perror("exec failed");
        exit(1);
    }
    else {
        waitpid(pid, NULL, 0);
    }

    return 0;
}

/* --- Trim newline and allocate memory for string --- */
char *makestring(char *buf) {
    buf[strcspn(buf, "\n")] = '\0';   /* trim newline safely */
    char *cp = malloc(strlen(buf) + 1);
    if (cp == NULL) {
        fprintf(stderr, "no memory\n");
        exit(1);
    }
    strcpy(cp, buf);
    return cp;
}

