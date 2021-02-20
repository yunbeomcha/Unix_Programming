#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mqstat_print(key_t, int, struct msqid_ds *);

main(int argc, char **argv) {

	key_t mkey;
	int msq_id;
	struct msqid_ds msq_status;

        mkey = ftok("keyfile", 1);
        if ((msq_id = msgget(mkey, IPC_CREAT | 0644)) == -1) {
                perror("msgget failed");
                exit(1);
        }

	if (msgctl(msq_id, IPC_STAT, &msq_status) == -1) {

		perror("msgctl failed");
		exit(3);
	}

	mqstat_print(mkey, msq_id, &msq_status);
	exit(0);
}

void mqstat_print(key_t mkey, int mqid, struct msqid_ds *mstat) {

	printf("\nKey %d, msg_qid %d\n", mkey, mqid);

	printf("%d message(s) on queue\n\n", mstat->msg_qnum);

	printf("Last send by proc %d at %s\n", mstat->msg_lspid, ctime(&(mstat->msg_stime)));

	printf("Last recv by proc %d at %s\n", mstat->msg_lrpid, ctime(&(mstat->msg_rtime)));
}


