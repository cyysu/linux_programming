/* Program that shows how fork system call works */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;

    printf("There is only one process now.\n");

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    }

    if (pid == 0) {
      /* 
       *  Now we are in the childs process 
       */
        printf("This message is printed by the child process.\n");
        execl("/bin/date", "date", (char *) 0);
        perror("execl() failure!\n\n");

    } else {
      /* 
       * Now we are in the parent process
       */
            printf("PARENT PROCESS.\n");
            wait (0);
        }
    printf("=== The End ===\n");
    return(0);
}


