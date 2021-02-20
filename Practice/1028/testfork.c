#include <stdio.h>
#include <stdlib.h>


int main(void) {
        pid_t pids[2], pid, pid1, pid2;
        int runProcess = 0;
        int state;
	printf("pid: %d\n", (int)getpid());
        while(runProcess < 2) {

		pids[runProcess] = fork();
		
                if(pids[runProcess] < 0) {
                        return -1;
                }
                else if(pids[runProcess] == 0) {
		
                        printf("pid: %d\n", (int)getpid());//child

                        pid1 = fork();
                        if(pid1 < 0){
                                return -1;
                        }
                        else if(pid1 == 0){
                                printf("pid: %d\n", (int)getpid());//child
                          	exit(0);     
                        }
			exit(0);
                }
                runProcess++;
        }
        return 0;
}

