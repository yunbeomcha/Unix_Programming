#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    switch (pid = fork()) {
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0 : /* child */
            close(fd[1]);
            if (fd[0] != 0) {
                dup2(fd[0], 0); //파일 입력을 위해 복사
                close(fd[0]); //읽기 디스크립터 닫기
            }
            execlp("grep", "grep", "telnet", (char *)NULL); // 파이프로부터 내용을 표준 읽기
            exit(1);
            break;
        default :
            close(fd[0]);
            if (fd[1] != 1) {
                dup2(fd[1], 1); //파이프의 쓰기를 표준출력으로 복사
                close(fd[1]);
            }
            execlp("psㅑ", "ps", "-ef", (char *)NULL); //파이프의 쓰기로 복사
            wait(NULL);
            break;
    }

    return 0;
}
