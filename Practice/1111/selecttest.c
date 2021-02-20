#include <sys/time.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE 256

char *msg1 = "hello";
char *msg2 = "bye!!";

void parent(int p[2][2]); //2개의 파이프로부터 파일 디스크립터로 읽거나 쓰기
int child(int[]);

main() {
	int process = 0;
        int pip[2][2];
        int i;
	for (i=0; i<2; i++) {
        	if (pipe(pip[i]) == -1)
		perror("pipe call");

  		switch(fork()) {
               	        case -1:
			perror("fork call");
                        case 0 :
			printf("%d %d\n", (int)getpid(), (int)getppid());
			child(pip[i]); //child 호출	
                }

        }
	
	parent(pip);
        exit(0);
}


void parent(int p[2][2]) {

        char buf[MSGSIZE], ch[MSGSIZE];
        fd_set set, master;
        int i;

        for (i=0; i<2; i++)  
		close(p[i][1]); //읽기 때문에 쓰기 위한 파이프를 닫는다.

        FD_ZERO(&master);
        FD_SET(0, &master);

        for (i=0; i<2; i++) 
		FD_SET(p[i][0], &master); //2개의 파이프에서 읽기 위한 데이터의 흥미가 있다.

        while (set = master, select(p[1][0]+1, &set, NULL, NULL, NULL) > 0) {

                if (FD_ISSET(0, &set)) {
			printf("\nParent ID: %d\n", (int)getpid());
                        printf("From standard input ... ");
                        read(0, &ch, 255);
                        printf("%s\n", ch); //입력받은 내용을 출력
                }

                for (i=0; i<2; i++) {
                        if (FD_ISSET(p[i][0], &set)) {
                                if (read(p[i][0], buf, MSGSIZE) > 0) {
                                        printf("Message from child %d\n", i);
                                        printf("MSG=%s\n", buf);
                                }
                        }
                }

                if (waitpid (-1, NULL, WNOHANG) == -1) //child process가 없다면 종료
			return;
        }
}
int child(int p[2]) {

        int count;

        close (p[0]); //2개의 child에 데이터를 쓴다. 그러니 읽기 디스크립터는 닫는다.

        for (count = 0; count < 2; count ++) {
                write(p[1], msg1, MSGSIZE);
                sleep(getpid() % 4);
        }
	
        write(p[1], msg2, MSGSIZE);
        exit(0);
}


