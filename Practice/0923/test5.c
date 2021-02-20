#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;

    fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC, 0644);//파일을 생성하고
	//파일 디스크립터 저장	
    if (fd == -1) {
        perror("Create tmp.bbb");
        exit(1);
    }

    dup2(fd, 1); //표준출력(1) 파일디스크립터를 지정하여 복사한다.
	
    printf("DUP2 : Standard Output Redirection\n");
    close(fd);

    return 0;
}

