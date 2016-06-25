/* Program that shows how fork system call works */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;

    printf("--- There is only one process now. ---\n");
    sleep(5);
    printf("--- I will going to call fork() ... ---\n");
    sleep(3);

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    }

    if (pid == 0) {
      /* Now we are in the childs process */
        printf("    This message is printed by the child process. >>>\n");
        sleep(1);
        printf("    This message is printed by the child process. >>>\n");
        sleep(1);
        printf("    This message is printed by the child process. >>>\n");
    } else {
      /* Now we are in the parent process */
        printf("<<< This is from PARENT PROCESS.\n");
        sleep(1);
        printf("<<< This is from PARENT PROCESS.\n");
        sleep(1);
        printf("<<< This is from PARENT PROCESS.\n");
    }
    sleep(8);
    printf("=== I will going to the end ...\n");
    sleep(4);
    printf("=== The End ===\n");
    return(0);
}

