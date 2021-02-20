#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <errno.h>

#define MAX_SIZE 80

main() {

	char MSG[10] = "bye";
	int msqid, n;
	key_t msq_key;
	struct msgbuff {
		long mtype;
		char mtext[MAX_SIZE];
	} buff;

	msq_key = ftok("keyfile", 1);
        if ((msqid = msgget(011011, IPC_CREAT | 0644)) == -1) {
                perror("msgget failed");
		exit(1);
	}

	switch (fork()) {

		case -1:
			perror("error on fork");
		case  0:
	
			memset(buff.mtext, 0, MAX_SIZE);
			while ((n= read(0, buff.mtext, MAX_SIZE)) > 0) {

				if (!strncmp(buff.mtext, MSG, 3)) {
					buff.mtype = 2;
				}
				else	buff.mtype = 1;


				if (msgsnd(msqid, &buff, n, 0) < 0) {
					perror("msgsnd");
					exit(1);
				}
				if (buff.mtype == 2) exit(0);
				memset(buff.mtext, 0, MAX_SIZE);
			}

			buff.mtype = 2;
			memset(buff.mtext, 0, MAX_SIZE);
			if (msgsnd(msqid, &buff, MAX_SIZE, 0) < 0) {
				perror("msgsnd");
				exit(1);
			}

		default:

			while ((n=msgrcv(msqid, &buff, MAX_SIZE, 0, 0)) > 0) {
				switch(buff.mtype) {
					case 1:
						write(1, buff.mtext, n);
						break;
					case 2:
						goto out;
				}
			}
	}

	out:
		exit(0);
}

