#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main() {

        int fd;
        struct flock first_lock, second_lock;

        first_lock.l_type = F_WRLCK;
        first_lock.l_whence = SEEK_SET;
        first_lock.l_start = 0;
        first_lock.l_len = 10;

        second_lock.l_type = F_WRLCK;
        second_lock.l_whence = SEEK_SET;
        second_lock.l_start = 10;
        second_lock.l_len = 5;
	//deadlock을 걸 수 있는 시나리오
	
        fd = open("testdata", O_RDWR);

        if (fcntl(fd, F_SETLKW, &first_lock) == -1) {
                perror("A");
                exit(1);
        }

        printf("A: lock succedded (proc %d)\n", getpid());

        switch(fork()) {
                case -1 :
                                perror("error on fork");
                                exit(1);
                case 0 :
                                if (fcntl(fd, F_SETLKW, &second_lock) == -1) {
                                        perror("B");
                                        exit(1);
                                }
                                printf("B: lock succeeded (proc %d)\n", getpid());
                                if (fcntl(fd, F_SETLKW, &first_lock) == -1) {
                                        perror("C");
                                        exit(1);
                                }
                                printf("C: lock succeeded (proc %d)\n", getpid());
                                exit(0);
                default:
                                printf("parent sleeping\n");
                                sleep(5);
                                if (fcntl(fd, F_SETLKW, &second_lock) == -1) {
                                        perror("D");
                                        exit(1);
                                }
                                printf("D: lock succeeded (proc %d)\n", getpid());
        }
}

