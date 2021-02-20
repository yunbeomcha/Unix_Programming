#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <sys/shm.h>

main(int argc, char **argv) {

        key_t key;
        int shmid;
        void *shmaddr;
        char buf[1024];

        key = ftok("shmfile", 1);
        shmid = shmget(011011, 1024, 0);

        shmaddr = (char *)shmat(shmid, NULL, 0);
        strcpy(shmaddr, "Hello, I'm talker\n");

        kill(atoi(argv[1]), SIGUSR1); //server측에 id를 줘야해서 pid, signal을 보낸다.
        sleep(2);
        strcpy(buf, shmaddr);

        printf("Listener said : %s\n", buf);
        shmdt(shmaddr);
        shmctl(shmid, IPC_RMID, NULL);
}

