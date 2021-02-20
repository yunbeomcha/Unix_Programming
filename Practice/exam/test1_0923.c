#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define WBUFSIZE 1024
#define RBUFSIZE 64
int main(int argc, char *argv[]) {
	int fd, i, n, num, length;
	int offset;
	off_t start, cur;
	int wbuf[WBUFSIZE], rbuf[RBUFSIZE];
	
	fd = open("testdata", O_RDWR | O_CREAT, 0644);
	for(i = 0; i< 1024; i++) wbuf[i] = i;
	write(fd, wbuf, sizeof(wbuf));
	close(fd);
	
	offset = atoi(argv[1]);
	offset *= sizeof(int);
	
	length = atoi(argv[2]);	
	

	fd = open("testdata", O_RDWR, 0644);
	bzero(rbuf, sizeof(rbuf));

	lseek(fd, (off_t)offset, SEEK_SET);
	read(fd, rbuf, length*sizeof(int));
	
	for(i = 0; i< length; i++){
		printf("%d ", rbuf[i]);
	}
	close(fd);	
}
