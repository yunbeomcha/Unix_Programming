#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

main() {

	int fd;
	struct flock my_lock;
	struct flock b_lock;

	my_lock.l_type = F_WRLCK;
	my_lock.l_whence = SEEK_SET;
	my_lock.l_start = 0;
	my_lock.l_len = 10;

	fd = open("testdata", O_RDWR);

	if (fcntl(fd, F_SETLKW, &my_lock) == -1) {
		perror("parent : locking");
		exit(1);
	}

	printf("parent : locked record %d\n", (int)getpid());

	switch(fork()) {
		case -1 :
			perror("fork");
			exit(1);
		case 0 :
			my_lock.l_len = 5;
			if (fcntl(fd, F_SETLK, &my_lock) == -1) {
				if (errno == EACCES || errno == EAGAIN) {
					fcntl(fd, F_GETLK, &b_lock); //어떤 프로세스가 lock을 걸었는지
					printf("record locked by %d\n", (int)b_lock.l_pid);//해당 프로세스 출력
				}
				else {
					perror("unexpected lock error");
					exit(1);
				}
			}
			printf("child: exiting\n");
			exit(0);
	}
	
	sleep(2);

	printf("parent: unlocking\n");

	my_lock.l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, &my_lock) == -1) {
		printf("parent : unlocking");
		exit(1);
	}

	exit(0);
}




