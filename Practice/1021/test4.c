#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
        struct timeval tv;

        gettimeofday(&tv, NULL);
        printf("Time(sec) : %d\n", (int)tv.tv_sec);//세컨드
        printf("Time(micro-sec) : %d\n", (int)tv.tv_usec);//마이크로 세컨드
}

