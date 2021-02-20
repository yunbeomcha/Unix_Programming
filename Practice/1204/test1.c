#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main() {

        key_t key;
        int shmid;

        //key = ftok("shmfile", 1); //키 값 생성
        shmid = shmget(011011, 1024, IPC_CREAT|0644); //1k byte, 공유메모리, 접근권한
        if (shmid == -1) {
                perror("shmget");
                exit(1);
        }
}

