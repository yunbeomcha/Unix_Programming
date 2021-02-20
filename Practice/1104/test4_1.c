#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
	pid_t pid;
	switch (pid = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
			printf("Chile Process --->\n");
			if(execlp("ls", "ls", "-a", (char *)NULL) == -1){
				perror("execlp");
				exit(1);
			}
			exit(0);
			break;
		default:
			printf("\nParent Process---- My Pid: %d\n", (int)getpid());		
			break;

	}
	return 0;

}
