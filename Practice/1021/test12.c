#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        char *val;

        val = getenv("SHELL");//쉡 검색
        if (val == NULL)
                printf("SHELL not defined\n");
        else
                printf("SHELL = %s\n", val);

        putenv("SHELL=/usr/bin/csh"); //바꾸고 싶은 이름
	//단, 프로세스가 실행되는 동안만 바뀌고 종료되면 다시 원위치
        val = getenv("SHELL");
        printf("2. SHELL = %s\n", val); //변경이 되었는지 확인
}

