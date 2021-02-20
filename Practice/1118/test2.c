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
	my_lock.l_start = 0; // 시작은 0
	my_lock.l_len = 10;

	fd = open("testdata", O_RDWR);

	if (fcntl(fd, F_SETLKW, &my_lock) == -1) { //locking
		perror("parent : locking");
		exit(1);
	}

	printf("parent : locked record\n");

	switch(fork()) {
		case -1 :
			perror("fork");
			exit(1);
		case 0 : //child
			my_lock.l_len = 5;
			if (fcntl(fd, F_SETLKW, &my_lock) == -1) { //부모와 자식은 별도
				perror("child : locking");
				exit(1);
			}
			printf("child: locked\n");
			printf("child: exiting\n");
			exit(0);
	}
	
	sleep(2);

	printf("parent: unlocking\n");


	my_lock.l_type = F_UNLCK;
	if (fcntl(fd, F_SETLK, &my_lock) == -1) {
		printf("parent : unlocking");
		exit(1);
	} //lock을 풀어준다.

	exit(0);
}

