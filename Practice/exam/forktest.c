#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/time.h>

#define WBUFSIZE 1024
#define RBUFSIZE 256

int main(void){
	pid_t pid[4], pid2;
	int process = 0;
	int status;
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
			#ifdef TIMES
			gettimeofday(&stime, NULL);
			#endif
			fd = open("testdata", O_RDWR, 0644);
 			lseek(fd, process * sizeof(rbuf), SEEK_SET);

			read(fd, rbuf, 4 * sizeof(rbuf));
			for(i = 0; i< 256; i++){
				printf("%d ", rbuf[i]);
			}
			printf("\nChild %d\n", (int)getpid());			
			#ifdef TIMES	
		        gettimeofday(&etime, NULL);
		        time_result = etime.tv_usec - stime.tv_usec; // 자식 프로세스가 읽은 시간
        		printf("Time : %d\n\n", time_result);
			#endif
			close(fd);
			sleep(1);
			exit(1);
		}
		printf("\n");
		process++;
	}
	return 0;

}
