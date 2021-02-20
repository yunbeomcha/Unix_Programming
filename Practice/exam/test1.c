#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
        int fd, n;
	off_t start, cur;
	char buf[256];

	fd = open("unix.txt", O_RDONLY);
	if (fd == -1) {
		perror("Open unix.txt");
		exit(1);
	}

	start = lseek(fd, 0, SEEK_CUR);//현재위치에서부터 256바이트만큼 읽어라
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);
	cur = lseek(fd, 0, SEEK_CUR); //n의 바이트만큼 cur의 값이 출력
	printf("Offset cur=%d\n", (int)cur);
	start = lseek(fd, 5, SEEK_SET);
	n = read(fd, buf, 255);
	buf[n] = '\0';
	printf("Offset start=%d , Read Str=%s\n", (int)start, buf);
	n = lseek(fd, 0, SEEK_END);	
	printf("File size=%d\n", n);

	close(fd);
	return 0;
}

