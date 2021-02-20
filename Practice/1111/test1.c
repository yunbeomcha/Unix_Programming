#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main() {

	FILE *fp;
	int a;

	fp = popen("wc -l", "w"); //고수준 파이프를 생성 wordcount로 w쓰기전용모드
	if (fp == NULL) {
		fprintf(stderr, "popen failed\n");
		exit(1);
	}

	for (a=0; a<100; a++) 
		fprintf(fp, "test line\n"); //문장을 100개 생성

	pclose(fp);

}

