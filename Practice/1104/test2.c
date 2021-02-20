#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {
	char *argv[3];

	printf("--> Before exec function\n");

	argv[0] = "ls"; // 실행파일명
	argv[1] = "-a"; //인자
	argv[2] = NULL; //null
	if (execv("/bin/ls", argv) == -1) { //경로지정
		perror("execv");
		exit(1);
	}

	printf("--> After exec function\n");
}




