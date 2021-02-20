#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dent;
    int count;

    if(argc != 2) {
        printf("Usage: exc4-4.out dirname\n");
        exit(1);
    }

    if((dp = opendir(argv[1])) == NULL) {
        perror("opendir: hanbit");
        exit(1);
    }

    while(dent = readdir(dp)) {
        if(dent->d_name[0] != '.')
            printf("Name : %s\n", dent->d_name);
    }
    closedir(dp);
}
