#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main(int argc, char **argv) {
	pid_t pid;

	switch (pid = fork()) {

	case -1:
		perror("fork failed");
		exit(1);
	case 0:
		execl("/bin/ls", "ls", "-l", (char *)0);
		perror("exec failed");
		exit(1);
	default:
		wait((int *)0);
		exit(0);
	}
}




