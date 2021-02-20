#include <stdio.h>
#include <fcntl.h>

main() {

	int fd;
	int arg1;

	fd = open("testdata", O_WRONLY|O_CREAT,0644);
	write(fd, "hi there...\n", 15); //testdata를 오픈하고 작성
	lseek(fd, (off_t)0, SEEK_SET); //lseek로 초기로 옮긴다.
	fcntl(fd, F_SETFL, O_WRONLY|O_APPEND); //append시켜준다.
	write (fd, "students...\n", 15); //testdata뒤에 붙여진다.

	arg1 = fcntl(fd, F_GETFL); 
	switch (arg1 & O_ACCMODE) { //ACCMODE를 통해flag를 테스트한다.
		case O_WRONLY:
			printf("write-only\n");
			break;
		case O_RDWR:
			printf("read_write\n");
			break;
		case O_RDONLY:
			printf("read-only\n");
			break;
		default:
			printf("No such mode");
	}

	if (arg1 & O_APPEND)
		printf(" - append flag set\n"); //append가 있는경우 출력

	close (fd);
}

