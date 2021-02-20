#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main() {

	FILE *fp;
	char buf[256];

	fp = popen("date", "r"); //고수준의 읽기 파이프
	if (fp == NULL) {
		fprintf(stderr, "popen failed\n");
		exit(1);
	}

	if (fgets(buf, sizeof(buf), fp) == NULL) { //데이터를 읽기
		fprintf(stderr, "NO data from pipe!\n");
		exit(1);
	}

	printf("line : %s\n", buf); //date의 결과값의 내용 읽어서 출력
	pclose(fp);

}

