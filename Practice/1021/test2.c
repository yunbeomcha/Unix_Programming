#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
        printf("LINK_MAX = %ld\n", pathconf(".", _PC_LINK_MAX));//링크의 최대 갯수
        printf("NAME_MAX = %ld\n", pathconf(".", _PC_NAME_MAX));//파일크기의 최대 갯수
        printf("PATH_MAX = %ld\n", pathconf(".", _PC_PATH_MAX));//경로의 길이
}

