#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 64

char namebuf[NAMELENGTH];
int infile = -1;

int main(int argc, char **argv) {
	//방번호를 명령행 인자로 받는다.
	off_t offset;
	ssize_t nread;
	int i = 0;


        if (infile == -1 && (infile = open("residents", O_RDONLY)) == -1) {
		
                exit(1);
        }
	//residents파일을 오픈한다.
	offset = (atoi(argv[1])-1) * NAMELENGTH; //방번호를 입력받는다.
	//-1을 해주는 이유는 offset 0에서부터 64바이트까지 읽어야만 되기 때문
        if (lseek(infile, offset, SEEK_SET) == -1) {
            perror("Seek error");
            exit(1);
        }

        if ((nread = read(infile, namebuf, sizeof(namebuf))) <= 0) {
            perror("Read error");
            exit(1);
        }

        printf("room = %d, %s\n", atoi(argv[1]), namebuf);
	//방번호에 있는 투숙객의 이름과 번호 출력한다.
	close(infile);
}

