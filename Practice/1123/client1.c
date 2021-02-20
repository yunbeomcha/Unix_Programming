#include <stdio.h>
#include <stdlib.h>
#include "q.h"

int enter(char *objname, int priority) {

        int len, s_qid;
        struct q_entry s_entry;

        if ((len = strlen(objname)) > MAXOBN) { //메세지 길이를 넘어가지 않도록
                perror("name too long");
                return(-1);
        }

        if (priority > MAXPRIOR || priority < 0) { //메세지 번호 10보다 작은 값으로

                perror("invalid priority level");
                return(-1);
        }

        if ((s_qid = init_queue()) == -1)
                return(-1);
	//메세지 큐 생성
	
        s_entry.mtype = (long)priority; //메세지 순번작성
        strncpy(s_entry.mtext, objname, MAXOBN);
	//명령행 인자로 받게 한다.
	
        if (msgsnd(s_qid, &s_entry, len, 0) == -1) { //데이터를 보낸다.
                perror("msgsnd failed");
                return(-1);
        }
        else
                return(0);
}

main(int argc, char **argv) {

        int priority;

        if (argc != 3) {
                fprintf(stderr, "Usuage: %s objname priority\n", argv[0]);
                exit(1);
        }
        if ((priority = atoi(argv[2])) <= 0 || priority > MAXPRIOR) {
                perror("invalid priority");
                exit(2);
        }

        if (enter(argv[1], priority) < 0) {
                perror("enter failure");
                exit(3);
        }

        exit(0);
}

