#include <stdlib.h>
#include <stdio.h>

main() {
    char *val;

    val = getenv("HBENV");
    if(val == NULL)
        printf("HBENV not defined\n");
    else
        printf("Before HBENV = %s\n", val);

    putenv("HBENV=hbooks"); //환경변수 설정

    val = getenv("HBENV"); //제대로 설정됐는지 확인
    printf("After HBENV = %s\n", val);
}

