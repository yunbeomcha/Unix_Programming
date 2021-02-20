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
        printf("Name : %s \t", dent->d_name);
        if((buf.st_mode & S_IFMT) == S_IFDIR)
            printf("Type : Directory\n");
        else if((buf.st_mode & S_IFMT) == S_IFREG)
            printf("Type : File\n");
	else if((buf.st_mode & S_IFMT) == S_IFLNK)
	    printf("Type : Sym_link File\n");

	printf("\n");
    }
    closedir(dp);
}
