#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{ 
    int fd1;
    char buf [100]; 
    fd1 = open ( "mypipe", O_RDONLY );
    if ( fd1 < 0 ) {
        perror("open file fail for read.");
        exit (1);
    }
    read ( fd1, buf, 100 );
    printf ( "%s\n", buf );
    close (fd1);
} 
