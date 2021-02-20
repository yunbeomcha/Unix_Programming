#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

int main(int argc, char*argv[]) {
    	int n,i,j, input = 0, tmp;
	int fd, size;
	int cur;
	off_t start, c_start;
	char buf[BUFSIZE];
	
	fd = open("testdata", O_RDONLY);
	if(fd == -1){
		perror("Open testdata");
		exit(1);
	}

	//파일 사이즈는 27(널 포함)
	printf("current offset\t: ");
	start = lseek(fd, 0, SEEK_CUR);
	printf("%d ", (int)start);
	for(i = 0; i < 25 / atoi(argv[1]); i++){
	start = lseek(fd, atoi(argv[1]), SEEK_CUR);
	printf("%d ", (int)start);
	}
	printf("\n");
	printf("current data\t: ");
	start = lseek(fd, 0, SEEK_SET);
	for(i = 0; i <= 26 / atoi(argv[1]); i++){
	lseek(fd, i * atoi(argv[1]), SEEK_SET);
	n = read(fd, buf, 1);
	buf[n] = '\0';
	printf("%s ",buf); 
	
	}
	printf("\n");
    close(fd);

    return 0;
}

