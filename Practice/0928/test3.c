#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd, flags;

    //fd = open("unix.txt", O_RDWR);
    //fd = open("unix.txt", O_RDONLY);//append가 붙지를 못한다. 매치가 될수있는 flag의 값만 바꿀수있다.
    fd = open("unix.txt", O_WRONLY);//둘다 write이고 파일의 속성이 붙여진다.
    if (fd == -1) {
        perror("open");
        exit(1);
    } //텍스트 오픈

    if ((flags = fcntl(fd, F_GETFL)) == -1) {
        perror("fcntl");
        exit(1);
    } //GETFL로 체크한다.

    flags |= O_APPEND; //flag에 append추가한다.

    if (fcntl(fd, F_SETFL, flags) == -1) {
        perror("fcntl");
        exit(1);
    } //파일디스크립터 속성 변경

    if (write(fd, "Hanbit Media", 12) != 12) perror("write");//append가 되어진다.
    close(fd); 

    return 0;
}

