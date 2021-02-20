#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

main() {
    DIR *dp;
    struct dirent *dent;
    struct stat buf;
    int kind;

    if((dp = opendir(".")) == NULL) {
        perror("opendir: current directory");
        exit(1);
    }

    while(dent = readdir(dp)) {
        stat(dent->d_name, &buf);
        printf("Name : %s  ", dent->d_name);
        if((buf.st_mode & S_IFMT) == S_IFDIR)
            printf("Type : Directory\n");
        else
            printf("Type : File\n");
    }
    closedir(dp);
}
