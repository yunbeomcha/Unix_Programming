#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

int main(void) {
    	int n,i,j, input = 0, tmp;
	int fd;    
	off_t start, end, cur;
	char buf[BUFSIZE];
	
	fd = open("testdata", O_RDONLY);
	if(fd == -1){
		perror("Open testdata");
		exit(1);
	}

	while(1){
	printf("Which string (0 to quit)? ");
        scanf("%d", &input);	
	
	lseek(fd, 3*(input -1), SEEK_SET);
	n = read(fd, buf, 3);
        buf[n] = '\0';
    	printf("%s\n", buf);
	}
    close(fd);

    return 0;
}

