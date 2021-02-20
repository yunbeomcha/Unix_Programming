#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main() {

	int status;
	pid_t pid;

	switch (pid = fork()) {
		case -1 : /*fork failed */
			perror("fork");
			exit(1);
		case 0 : /*child process */
			printf("--> Child Process\n");
			exit(4);
			break;
		default : /*Parent Process */
			while (wait(&status) != pid)
				continue;
			printf("--> Parent process = My PID:%d\n", (int)getpid());
			printf("Status : %d, %x\n", status, status);
			printf("Child process Exit Status:%d\n", status);
			break;
	}
}

