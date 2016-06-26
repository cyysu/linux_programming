#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

char * phrase = "Stuff this in your pipe and smoke it";

int main ()
{
    int fd1;

//    struct stat sts;
//
//    if ((stat ("mypipe", &sts)) == -1  && errno == ENOENT) {
//        printf ("The pipe %s doesn't exist, I'll create it.\n", "mypipe");
//
//    //    if ((mknod("mypipe", S_IFIFO | 0666, 0)) !=0 ) {
//        if ((mkfifo("mypipe", S_IRWXU)) != 0) {
//            perror("Unable to create a fifo file.");
//            exit(1);    /* Print error message and return */
//        }
//    }

    fd1 = open ( "mypipe", O_WRONLY );
    if ( fd1 < 0 ) {
        perror("open file fail for write.");
        exit (1);
    }
    write (fd1, phrase, strlen ( phrase) + 1 );
    close (fd1);
} 
