#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>

main() {

        DIR *dp;
        struct dirent *dent;
        struct stat sbuf;
        char path[BUFSIZ];

        if ((dp = opendir(".")) == NULL) {
                perror ("opendir : .");
                exit(1);
        }

        while ((dent = readdir(dp))) {
                if (dent->d_name[0] == '.')
			continue;
		
        	stat(dent->d_name, &sbuf);//현재 디렉토리내용에 대한 속성을 출력하기 위해

        	printf("Name : %s\n", dent->d_name);
        	printf("Inode(dirent) : %d\n", (int)dent->d_ino);//디렉토리 inode
        	printf("Inode(stat) : %d\n", (int)sbuf.st_ino);
        	printf("Mode : %o\n", (unsigned int)sbuf.st_mode);//디렉토리모드
        	printf("Uid : %d\n", (int)sbuf.st_uid);
		printf("Link Count: %d\n", (int)sbuf.st_nlink);
		printf("\n");
	}

        closedir(dp);

}
