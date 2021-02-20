#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/shm.h>

main() {

        int shmid, i;
        char *shmaddr, *shmaddr2;

        shmid = shmget(IPC_PRIVATE, 20, IPC_CREAT|0644);
        if (shmid == -1) {
                perror("shmget");
                exit(1);
        }

        switch(fork()) {
                case -1:
                        perror("fork");
                        exit(1);
                case 0: //child
                        shmaddr = (char *)shmat(shmid, (void *)NULL, 0); //권한은 0
                        printf("Child Process =====\n");
                        for (i=0; i<10; i++) shmaddr[i] = 'a' + i; //a에서 부터 10개를 쓴다.
                        shmdt((char *)shmaddr); //detach
                        exit(0);
                default:
                        wait(0);
                        shmaddr2 = (char *)shmat(shmid, (void *)NULL, 0);
                        printf("Parent Process =====\n");
                        for (i=0; i<10; i++) printf("%c ", shmaddr2[i]);
                        printf("\n");
                        sleep(5);
                        shmdt((char *)shmaddr2);
                        shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
                        break;
        }
}
