#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
        time_t tt;

        time(&tt);
        printf("Time(sec) : %d\n", (int)tt);
}

