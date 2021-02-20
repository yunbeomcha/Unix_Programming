#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
        DIR *dp;
        struct dirent *dent;
        struct stat sbuf;
        char path[BUFSIZ];

        if((dp == opendir("hanbit")) == NULL){
                perror("opendir : .");
                exit(1);
        }
        while ((dent = readdir(dp))){
                if(dent->d_name[0] == '.')
                        continue;

                stat(dent->d_name, &sbuf);
                if((int)sbuf.st_nlink >= 2){
                        printf("Name: %s\n", dent->d_name);
                }
        }
        return 0;

}

