#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(void){
	FILE *fp;
	long cur;
	fpos_t fcur;
	char buf[BUFSIZ];
	int n;
	int fd, flag;
	fd = open("testdata", O_RDWR);
	if(fd == -1){
		perror("open");
		exit(1);
	}
	cur = ftell(fp);
	n = fread(buf, sizeof(char), 3, fp);
	buf[n] = '\0';
	
}
