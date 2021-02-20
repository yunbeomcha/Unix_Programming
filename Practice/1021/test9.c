#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

extern char **environ;// 전역변수

int main(void) {

        char **env; //지역변수

        env = environ;

        while (*env) {
                printf("%s\n", *env);
                env++;
        }//모든 라인 출력
}

