#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WBUFSIZE 1024 
#define RBUFSIZE 64 


int main(void) {
        int fd, i, n;
        int wbuf[WBUFSIZE], rbuf[RBUFSIZE];

	for (i=0; i<WBUFSIZE; i++) {
		wbuf[i] = i;
	}

        fd = open("testdata", O_CREAT|O_TRUNC|O_RDWR, 0644);
        if(fd == -1) {
                perror("Open testdata");
                exit(1);
        }

	write(fd, wbuf, sizeof(wbuf));
	close(fd);

	fd = open("testdata", O_RDWR, 0644);
	bzero(rbuf, sizeof(rbuf));

	while ((n=read(fd, rbuf, sizeof(rbuf))) > 0) {
		for (i=0; i<RBUFSIZE; i++) {
			printf("%d ", rbuf[i]);
		}
		bzero(rbuf, sizeof(rbuf));
		printf("***********************\n");
	} 	

	close(fd);
}

