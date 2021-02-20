#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/sem.h>


typedef union semun {
	int val;
	struct semid_ds *buf;
	ushort *array;
}semun;

int initsem(key_t semkey) {
        semun semunarg;
        int status = 0, semid;

        semid = semget(semkey, 1, IPC_CREAT | IPC_EXCL | 0600);
        if (semid == -1) {
                if (errno == EEXIST)
                        semid = semget(semkey, 1, 0);
        }
        else {
                semunarg.val = 1;
                status = semctl(semid, 0, SETVAL, semunarg);
        }

        if (semid == -1 || status == -1) {
                perror("initsem");
                return(-1);
        }
        return semid;
}

int semlock(int semid) {
        struct sembuf buf;

        buf.sem_num = 0;
        buf.sem_op = -1;
        buf.sem_flg = SEM_UNDO;
        if (semop(semid, &buf, 1) == -1) {
                perror("semlock failed");
                exit(1);
        }
        return 0;
}

int semunlock(int semid) {
        struct sembuf buf;

        buf.sem_num = 0;
        buf.sem_op = 1;
        buf.sem_flg = SEM_UNDO;
        if (semop(semid, &buf, 1) == -1) {
                perror("semunlock failed");
                exit(1);
        }
        return 0;
}


void semhandle() {
        int semid, i;
	char first, last, ch;
        pid_t pid = getpid();

        if ((semid = initsem(1)) < 0)
		exit(1);

        semlock(semid);
	if ((pid = fork()) > 0) {
	
		first = 'A';
		last = 'Z';
	}
	else if (pid == 0) {

		first = 'a';
		last = 'z';
	}
	else {
		perror("fork");
		exit(1);
	}

	printf("\n");	
	for (ch = first; ch <= last; ch++) {

		for (i=0; i<10; i++)
			write(1, &ch, 1);
	}
	printf("\n"); 	       
        semunlock(semid);
        exit(0);
}

main(int argc, char *argv[]) {

	char ch, first, last;
	int pid;
	int i;
	long a;

	if(fork() == 0)
		semhandle();

	/*for (ch = first; ch <= last; ch++) {

		for (i=0; i<10; i++)
			write(1, &ch, 1);
	}*/
	printf("\n");
}	


