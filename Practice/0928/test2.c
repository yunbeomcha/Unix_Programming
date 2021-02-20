#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define SIZE 1024

int main(int argc, char **argv) {

        ssize_t nread;
        char buf[SIZE];
        int fd, i;

        if (argc==1) {
                while ((nread = read(0, buf, SIZE)) > 0)//표준입력
                        write (1, buf, nread); //표준출력
                exit(0);
        };

        for (i=1; i<argc; i++) {

                fd = open(argv[i], O_RDWR, 0644);//각 명령행 인수가 가리키는 파일을 오픈한다.
                memset(buf, 0, SIZE);//버퍼를 초기화시킨다.
                while ((nread = read(fd, buf, SIZE)) > 0) {
                        write(1, buf, SIZE);
                }

                close (fd);
        }
}

