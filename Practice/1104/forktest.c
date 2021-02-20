#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/time.h>

#define WBUFSIZE 1024
#define RBUFSIZE 64

int main(void){
	pid_t pid[4], pid2;
	off_t start, cur;
	int process = 0;
	int j, i = 0, num = 0;
	int fd;
	int wbuf[WBUFSIZE];
	int rbuf[RBUFSIZE];
	int n;

	struct timeval stime, etime;
	int time_result;
	

	printf("Parent: %d\n", (int)getpid());
	
	for(i = 0; i<WBUFSIZE; i++){
		wbuf[i] = i;
	}
	fd = open("testdata", O_CREAT | O_RDWR | O_TRUNC, 0644);
        if(fd == -1){
                perror("Open testdata");
                exit(1);
        }
	write(fd, wbuf, sizeof(wbuf));

	close(fd);

	while(process < 4){
		pid[process] = fork();
		
		if(pid[process] < 0){
			return -1;
		}
		else if(pid[process] == 0){ //child Process
				
			fd = open("testdata", O_RDWR, 0644);
 			lseek(fd, process * sizeof(int) * sizeof(rbuf), SEEK_SET);

			read(fd, rbuf, 4 * sizeof(rbuf));
			for(i = 0; i< 256; i++){
				printf("%d ", rbuf[i]);
			}
			printf("\nChild %d\n", (int)getpid());			
			printf("\n");
			
			
			close(fd);
			exit(0);
		}
		printf("\n");
		process++;
	}
	return 0;

}
