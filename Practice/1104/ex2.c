#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
	pid_t pid1, pid2;
	int fd, fd2;
	int n, status;
	char buf[BUFSIZ];	

	switch(pid1 = fork()){
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0:
		printf("Child Process\n");
		fd2 = open("unix.txt", O_RDONLY);
		if(fd2 == -1){
			perror("file open");
			exit(1);
		}
		while((n = read(fd2, buf, 10)) > 0){
			buf[10] = '\0';
			printf("n = %d, buf = %s\n", n, buf);
		}
		realpath("unix.txt", buf);
		printf("Child Process\nunix.txt: realpath = %s\n", buf);
		exit(0);
		break;
		
		default:
			printf("Parent Process\n");
			fd = open("unix.txt", O_RDONLY);

        		if(fd == -1){
                		perror("file open");
                		exit(1);
        		}
        		while((n = read(fd, buf, 10)) > 0){
                		buf[10] = '\0';
                		printf("n = %d, buf = %s\n", n, buf);
        		}
			wait((int*)0);
			realpath("unix.txt", buf);
			printf("Parent Process\nunix.txt : realPath = %s\n", buf);
			break;
	}
	
	close(fd);
	return 0;
}
