#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(void){
	pid_t pid[4];
	int i;
	int fd, n;
	int buf[BUFSIZ];
	for(i = 0; i<4; i++){
		pid[i] = fork();
		switch(pid[i]){
			case -1:
				perror("fork");
				exit(1);
				break;
			case: 0: //child process
				printf("Child Process\n");
			fd = open("unix.txt", O_RDONLY);
			if(fd == -1){
				perror("open unix.txt"); exit(1);
			}
			while((n = read(fd, buf, sizeof(int)*256)) > 0){
			
			}
			
		//integer file position (0~255 read(fd,buf, sizeof(int)*256);
		//write(0~255);
				
			break;
			default : // parent process
				
			//256~511 read
		}
		
	}

}
