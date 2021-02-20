#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 6

int parent(int *);
int child (int *);

char *msg1 = "hello";
char *msg2 = "bye!!";

main() {

        int pfd[2];

        if (pipe(pfd) == -1) perror ("pipe call");

        if (fcntl(pfd[0], F_SETFL, O_NONBLOCK) == -1)
		perror ("fcntl call");

        switch (fork()) {
                case -1 : perror("fork call");
                case 0  : child(pfd);
                default : parent(pfd);
        }
}

int parent(int p[2]) {
	//읽기 위한 프로세스
        int nread;
        char buf[MSGSIZE];

        close (p[1]); //쓰기 디스크립터 닫기

        for (;;) {
                switch (nread = read(p[0], buf, MSGSIZE)) {
                        case -1: //즉각 리턴
                                if (errno == EAGAIN) {
                                        printf("(pipe empty)\n");
                                        sleep(1);
                                        break;
                                }
                        case 0:
                                printf("End of conversation\n");
                                exit(0);
                        default:
                                printf("MSG = %s\n", buf);
                }
        }
}

int child(int p[2]) {
 	//파이프에 데이터를 작성
        int count;

        close(p[0]);

        for (count = 0; count < 3; count++) {

                write(p[1], msg1, MSGSIZE);
                sleep(3); //3초동안 읽기위한 프로세스가 없는것이다.
        }

        write(p[1], msg2, MSGSIZE);
        exit(0);
}

