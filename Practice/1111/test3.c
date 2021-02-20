#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define MSGSIZE		16

char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

main() {

	char inbuf[MSGSIZE];
	int p[2], j; //p[0]는 읽기, p[1]는 쓰기용 파일 디스크립터

	if (pipe(p) == -1) {
		perror("pipe call");
		exit(1);
	}

	write(p[1], msg1, MSGSIZE);
	write(p[1], msg2, MSGSIZE);
	write(p[1], msg3, MSGSIZE);
	//쓰기
	for (j=0; j<3; j++) {
		read(p[0], inbuf, MSGSIZE); //p[0]로 파이프로부터 읽어서
		printf("%s\n", inbuf); //화면에 출력
	}

	exit(0);
}

