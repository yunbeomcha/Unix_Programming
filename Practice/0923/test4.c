#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd, fd1;

    fd = open("tmp.aaa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	//파일 디스크립터를 얻는다.
    if (fd == -1) {
        perror("Create tmp.aaa");
        exit(1);
    }

    close(1);
	//표준 출력을 닫는다.
    fd1 = dup(fd);//dup을 사용하여 파일 디스크립터을 카피.
	
    printf("DUP FD=%d\n", fd1);
    printf("Standard Output Redirection\n");
    close(fd);
    return 0;
 }


