#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

main(){
	int status;
	pid_t pid;
#ifdef TIMES
	struct timeval stime, etime;
	int time_result;
#endif
	if((pid = fork()) < 0){
		perror("fork"); exit(1);
	}
#ifdef TIMES
	gettimeofday(&stime, NULL);
#endif

	if(pid == 0){
		printf(" --> Child process\n");
		sleep(3);
		exit(3);
	}
#ifdef TIMES
	gettimeofday(&etime, NULL);
	time_result = etime.tv_usec - stime.tv_usec;
	printf("Time : %d\n", time_result);
#endif

	printf("-->Parent Process\n");
	while(waitpid(pid, &status, WNOHANG) == 0){
		printf("Parent still wait .. \n");
		sleep(1);
	}
	printf("Child Exit Status : %d\n", status >> 8);
	return 0;

}
