#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
extern int addnum(int a, int b);

main() {

        int sum;

        sum = addnum(1, 5);
        printf("Sum 1~5 = %d\n", sum);

        return(0);
}

