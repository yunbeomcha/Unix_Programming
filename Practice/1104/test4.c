#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main() {
        char *argv[3];
        char *envp[2];

        printf("--> Before exec function\n");

        argv[0] = "arg.out";
        argv[1] = "100";
        argv[2] = NULL;
	//argv의 인자
        envp[0] = "MYENV=hanbit"; //환경변수
        envp[1] = NULL;

        if (execve("./arg.out", argv, envp) == -1) {
                perror("execve");
                exit(1);
        }

        printf("--> After exec function\n");
}

