#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 64

char namebuf[NAMELENGTH];
int infile = -1;

int main(int argc, char **argv) {

	off_t offset, offset2 , temp,start, end;
	ssize_t nread;
	int fd, i = 0, j = 0;
	char wbuf[64];
	fd = open("residents", O_RDWR);
        if (infile == -1 && (infile = open("residents", O_RDWR, 0644)) == -1) {
                exit(1);
        }
	read(infile, namebuf, sizeof(namebuf));
	printf("room 1 = %s\n", namebuf);
	for(i = 0; i<10; i++){
	offset = (i+1) * NAMELENGTH;
	//offset = (atoi(argv[1])-1) * NAMELENGTH;
	start = lseek(fd, *argv[1], SEEK_SET);
	end = lseek(fd, *argv[2], SEEK_SET);
        if (lseek(infile, offset, SEEK_SET) == -1) {
            perror("Seek error");
            exit(1);
        }
	temp = start;	
	start = end;
	end = temp;
	for( j = 0; j< 10; j++){
		write(infile, argv[1], 64);
	}
        if ((nread = read(infile, namebuf, sizeof(namebuf))) <= 0) {
            perror("Read error");
            exit(1);
        }

        printf("room = %d, %s\n", i+2, namebuf);

	}
	close(infile);
}

