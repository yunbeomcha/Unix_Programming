#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NAMELENGTH 64

char namebuf[NAMELENGTH];
int infile = -1;

main(void) {

        off_t offset;
        ssize_t nread;
        int i = 0;

        if (infile == -1 && (infile = open("residents", O_RDONLY)) == -1) {

                exit(1);
        }

        read(infile, namebuf, sizeof(namebuf));
        printf("room 1 = %s\n", namebuf);


        for (i=0; i<10; i++) {

                offset = (i+1) * NAMELENGTH;
		//+1을 해줘야 첫번째값을 읽는다. 64바이트부터 시작
                if (lseek(infile, offset, SEEK_SET) == -1) { //64바이트까지 읽으면
		//방2의 투숙객 이름을 출력
                        perror("Seek error");
                        exit(1);
                }

                if ((nread = read(infile, namebuf, sizeof(namebuf))) <= 0) {
                        perror("Read error");
                        exit(1);
                }

                printf("room = %d, %s\n", i+2, namebuf);
        }

}

