#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int serve(void) {

        int mlen, r_qid;
        struct q_entry r_entry;

        if ((r_qid = init_queue()) == -1) //메세지 큐 생성
                return(-1);

        for (;;) {
                if ((mlen = msgrcv(r_qid, &r_entry, MAXOBN, (-1*MAXPRIOR), MSG_NOERROR)) == -1)  {
			//메세지를 받는다. 식별자, 메세지 버퍼, 사이즈, 최소값부터 차례대로 최대로 큰값까지
			//메세지의 사이즈가 초과하는 경우 잘라서 사용
                        perror("msgrcv failed");
                        return(-1);
                }
                else {
                        r_entry.mtext[mlen] = '\0';
                        proc_obj(&r_entry);
                }
        }
}

main() {

        pid_t pid;

        switch(pid = fork()) {

        case 0:
                serve();
                break;
        case -1:
                perror("fork to start server failed");
                break;

        default:
                printf("server process pid is %d\n", pid);
        }

        exit(pid != -1 ? 0 : 1);
}


