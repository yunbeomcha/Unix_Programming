#include <stdio.h>
#include <stdlib.h>

main(){
        pid_t pid1, pid2, pid1_1, pid2_1;

        switch(pid1 = fork()) {

        case -1 :
                perror("fork");
                exit(1);
        case 0 :
                printf("Chile Process - pid1 MyPID : %d %d\n", (int)getpid(), (int)getppid());
                if((pid1_1 = fork()) == 0){
                        printf("Chile Process - pid1_1 MyPID: %d %d\n", (int)getpid(), (int)getppid());
                }
                break;
        default :
                printf("Parent process - pid1 MyPID : %d %d\n", (int)getpid(), (int)getppid());
                break;
        }
	printf("*************************\n");
        switch(pid2 = fork()) {

        case -1 :
                perror("fork");
                exit(1);
        case 0 :
                printf("Chile Process - pid2 MyPID : %d %d\n", (int)getpid(),  (int)getppid());
                if((pid2_1 = fork()) == 0){
                        printf("Chile Process - pid2_1 MyPID: %d %d\n", (int)getpid(),(int)getppid());
                }
                break;
        default :
                printf("Parent process - pid2 MyPID : %d %d\n", (int)getpid(), (int)getppid());
                break;
        }

}
