#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;
	pid = fork();
	if(pid > 0){
		pid = fork();
	}
	if(pid == 0){
		pid = fork();
	}
	printf("pid : %d %d\n", (int)getpid(),(int)getppid()); 
}
