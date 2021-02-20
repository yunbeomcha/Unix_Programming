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

    count = 0;
    while(dent = readdir(dp)) {
        count++;
/*
 *         printf("Name : %s  ", dent->d_name);
 *                 printf("Inode : %d\n", dent->d_ino);
 *                 */
    }
    closedir(dp);

    if(count == 2) {
        printf("Dir %s is empty.\n", argv[1]);
        rmdir(argv[1]);
        printf("Dir %s was removed.\n", argv[1]);
    }
}
