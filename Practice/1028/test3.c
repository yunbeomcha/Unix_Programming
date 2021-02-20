#include <stdlib.h>
#include <stdio.h>

main(int argc, char *argv[]) {
    char *val;

    if(argc != 3) {
        printf("Usage: 5-9.out name value.\n");
        exit(1);
    }

    val = getenv(argv[1]);
    if(val == NULL)
        printf("%s not defined\n", argv[1]);
    else
        printf("Before %s = %s\n", argv[1], val);

    setenv(argv[1], argv[2], 1); //새로운 값으로 설정

    val = getenv(argv[1]); //바꼈는지 확인
    if(val == NULL)
        printf("%s not defined\n", argv[1]);
    else
        printf("After %s = %s\n", argv[1], val);
}

