#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

main() {

        char buf1[BUFSIZ], buf2[BUFSIZ];
        int n;

        n = readlink("unix.sym", buf1, BUFSIZ);//원본 파일의 이름을 출력
        if (n == -1) {
                perror("readlink");
                exit(1);
        }

        buf1[n] = '\0';
        printf("unix.sym : READLINK = %s\n", buf1);

        realpath("unix.sym", buf2); //원본파일의 경로
	printf("unix.sym : REALPATH = %s\n", buf2);

}

