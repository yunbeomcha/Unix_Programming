#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        char *val;

        val = getenv("SHELL"); //환경변수의 이름
        if (val == NULL)
                printf("SHELL not defined\n");//null인경우 찾을 수 없다.
        else
                printf("SHELL = %s\n", val); //변수 이름이 있으면 출력
}

