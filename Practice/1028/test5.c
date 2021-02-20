#include <stdlib.h>
#include <stdio.h>

main() {

        pid_t pid;

        switch (pid = fork()) {

                case -1 :
                        perror("fork");
                        exit(1);
                case 0 : /* child process */
                        printf("Child Process - My PID: %d, My Parent's PID:%d\n",
                                (int)getpid(), (int)getppid());
                        break;
                default : /* parent process */
                        printf("Parent process - My PID:%d, My Parent's PID:%d, "
                                "My CHild's PID:%d\n", (int)getpid(), (int)getppid(), (int)pid);
                        break;
        }

        printf("End of fork\n");

}

