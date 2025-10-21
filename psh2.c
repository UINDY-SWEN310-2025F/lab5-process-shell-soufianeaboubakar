
void execute(char *arglist[])
/*
 * use fork and execvp and wait to do it
 */
{
    int pid, exitstatus;  /* of child */

    pid = fork();  /* make new process */

    switch (pid) {
        case -1:
            perror("fork failed");
            exit(1);

        case 0:
            /* do it */
            execvp(arglist[0], arglist);
            perror("execvp failed");
            exit(1);

        default:
            /* Parent waits here */
            wait(&exitstatus);
            printf("child exited with status %d,%d\n",
                   exitstatus >> 8, exitstatus & 0377);
    }
}
