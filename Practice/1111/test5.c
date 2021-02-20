#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE		16

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

main() {

	char inbuf[MSGSIZE];
	int p[2], j;
	pid_t pid;

	if (pipe(p) == -1) {
		perror("pipe call");
		exit(1);
	}

	switch (pid = fork()) {
	
	case -1:
		perror("fork call");
		exit(2);
	case 0: //Child Process
		close(p[0]); //읽기 전용 파이프는 닫기
		write(p[1], msg1, MSGSIZE);
		write(p[1], msg2, MSGSIZE);
		write(p[1], msg3, MSGSIZE);
		break;
	default: //Parent Process
		close (p[1]); //쓰기 전용 파이프는 닫기
		for (j=0; j<3; j++) {
			read(p[0], inbuf, MSGSIZE);
			printf("%s\n", inbuf);
		}
		wait(NULL);
	}

	exit(0);
}

