#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
        struct tm *tm;
        time_t t;

        time(&t);
        printf("Time(sec) : %d\n", (int)t); //현재를 초단위

        tm = gmtime(&t); //global time
        printf("GMTIME=Y:%d ", tm->tm_year); 
        printf("M:%d ", tm->tm_mon);
        printf("D:%d ", tm->tm_mday);
        printf("H:%d ", tm->tm_hour);
        printf("M:%d ", tm->tm_min);
        printf("S:%d ", tm->tm_sec);

        tm = localtime(&t);//local time
        printf("LOCALTIME=Y:%d ", tm->tm_year);
        printf("M:%d ", tm->tm_mon);
        printf("D:%d ", tm->tm_mday);
        printf("H:%d ", tm->tm_hour);
        printf("M:%d ", tm->tm_min);
        printf("S:%d\n", tm->tm_sec);

}

