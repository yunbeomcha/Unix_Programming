#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

struct mymsgbuf {
        long mtype;
        char mtext[80];
}; //메세지 큐의 타입

main() {

        key_t key; //키값
        int msgid; //id
        struct mymsgbuf mesg; //메세지 구조체

        key = ftok("keyfile1", 1); //키 값 생성(경로가 서로 달라야함)
        msgid = msgget(011011, IPC_CREAT|0644); //메세지 큐 생성
        if (msgid == -1) {
                perror("msgget");
                exit(1);
        }

        mesg.mtype = 1; //메세지 번호
        strcpy(mesg.mtext, "Message Q Test\n");//mtext부분에 메세지 copy

        if (msgsnd(msgid, (void *)&mesg, 80, IPC_NOWAIT) == -1) { //식별자, 버퍼, mtext의 길이, 메세지 큐가 꽉찬경우 오류를 출력
                perror("msgsnd");
                exit(1);
        }
}
