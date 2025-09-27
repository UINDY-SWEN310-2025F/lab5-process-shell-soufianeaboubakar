#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXARGS 20   /* cmdline args */
#define ARGLEN  100  /* token length */

int execute(char *arglist[]);

int main() {
    char *arglist[MAXARGS + 1];  /* an array of ptrs */
    int numargs;                 /* index into array */
    char argbuf[ARGLEN];         /* read stuff here */
    char *makestring();          /* malloc etc */

    numargs = 0;

    while (numargs < MAXARGS) {
        printf("Arg[%d]? ", numargs);

        if (fgets(argbuf, ARGLEN, stdin) && *argbuf != '\n') {
            arglist[numargs++] = makestring(argbuf);
        } else {
            if (numargs > 0) {
                arglist[numargs] = NULL;   /* close list */
                execute(arglist);          /* do the task */
                numargs = 0;               /* and reset */
            }
        }
    }
    return 0;
}

/* NOTE: use execvp to do it */
int execute(char *arglist[]) {
    execvp(arglist[0], arglist);  /* do it */
    perror("execvp failed");
    exit(1);
}

/* trim off newline and create storage for the string */
char *makestring(char *buf) {
    char *cp;

    buf[strlen(buf) - 1] = '\0';   /* trim newline */
    cp = malloc(sizeof(char) * (strlen(buf) + 1));
    if (cp == NULL) {
        fprintf(stderr, "no memory\n");
        exit(1);
    }
    strcpy(cp, buf);   /* copy chars */
    return cp;
}

