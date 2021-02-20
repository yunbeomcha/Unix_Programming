#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

main() {

        DIR *dp;
        struct dirent *dent;

        if ((dp = opendir(".")) == NULL) { //현재 디렉토리 내용을 알고싶으면 .
        //if ((dp = opendir("hanbit")) == NULL) { //hanbit 디렉토리의 내용을 알고싶으면 디렉토리명 작성
                perror ("opendir : hanbit");
                exit(1);
        }

       /* while ((dent = readdir(dp))) { //return 값은 dent
                printf("Name : %s ", dent->d_name);
                printf("Inode : %d\n", (int)dent->d_ino);
        }
	rewinddir(dp);
	printf("\n");*/
	while ((dent = readdir(dp))) {
                printf("Name : %s ", dent->d_name);
                printf("Inode : %d\n", (int)dent->d_ino);
        }
        closedir(dp);//디렉토리를 닫는다.
}

