/* Program that shows how execl system call works */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    printf("Here is the first line: ---> 1st <--- \n");

    execl("/bin/date", "date", (char *) 0);
    perror("execl() failure!\n\n");

    printf("I would say good bye to you !\n");
    printf("Here is the Last line: ---> LAST LINE <--- \n");

    return(0);
}

