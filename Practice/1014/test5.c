#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main() {

        if (mkdir("han", 0755) == -1) {
                perror ("han");
                exit(1);
        }

        if (mkdir("bit", 0755) == -1) {
                perror ("bit");
                exit(1);
        }
		//디렉토리권한0755로 생성
        if (rename("han", "hanbit") == -1) {
                perror("hanbit");
                exit(1);
        }
		//디렉토리 명을 바꿈
        if (rmdir("bit") == -1) {
                perror("bit");
                exit(1);
        }
		//bit이란 디렉토리 삭제 
}

