#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main(int argc, char **argv) {

	key_t mkey;
	int msq_id;
	struct msqid_ds msq_status;

	mkey = ftok("keyfile", 1);
        if ((msq_id = msgget(mkey, IPC_CREAT | 0644)) == -1) {
                perror("msgget failed");
                exit(1);
        }

	printf("Before IPC_RMID\n");
	system("ipcs -q | grep s18013189");
	if (msgctl(msq_id, IPC_RMID, &msq_status) == -1) {

		perror("msgctl failed");
		exit(3);
	}
	printf("After IPC_RMID\n");
	system("ipcs -q | grep s18013189");
}

