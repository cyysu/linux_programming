#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>

void scan_dir(char *dir, int depth)
{
   DIR *dp;
   struct dirent *entry;
   struct stat statbuf;
   if((dp = opendir(dir)) == NULL) {
      puts("Cannot open directioy");
      return;
   }
   chdir(dir);
   while((entry = readdir(dp)) != NULL) {
      lstat(entry->d_name, &statbuf);
      if(S_IFDIR & statbuf.st_mode) {
         if(strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0)
        continue;
         printf("%*s%s/\n",depth,"",entry->d_name);
         scan_dir(entry->d_name,depth+4);
      }
      else
         printf("%*s%s\n", depth, "", entry->d_name);
   }
   chdir("..");
   closedir(dp);
}

int main(int argc, char *argv[])
{
    puts("Scan the directory:");
    scan_dir(argv[1], 0);
    puts("Scanning ended.");
    return 0;
}
