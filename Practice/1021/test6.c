#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
        time_t t;

        time(&t);
        printf("Time(sec) : %d\n", (int)t); //초
        printf("Time(date) : %s\n", ctime(&t));//초를 컨버젼ㅈ

}

