#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

struct mymsgbuf {
        long mtype;
        char mtext[80];
};

main() {
        key_t key;
        int msgid, len;
        struct  mymsgbuf inmsg;

       // key = ftok("e1", 1);
        if ((msgid = msgget(011011, 0)) < 0) { //메세지 큐 식별자, 생성한 키를 0으로 받는다.
                perror("msgget");
                exit(1);
        }

        len = msgrcv(msgid, &inmsg, 80, 0); //식별자, 메세지 버퍼주소,메세지 길이, 블록모드
        //메세지 수신
	printf("Received Msg=%s, len=%d\n", inmsg.mtext, len);
}

