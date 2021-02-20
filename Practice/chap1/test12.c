#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int addnum(int a, int b) {

        int sum = 0;

        for (; a<=b; a++) sum += a;

        return sum;
}

int main(int argc, char *argv[]) {
	int n;
        int sum, startno, endno;
	printf("argc = %d\n", argc);
	for(n = 0; n < argc; n++){
	printf("argv[%d] = %s\n", n, argv[n]);
	}
        startno = atoi(argv[1]);
        endno = atoi(argv[2]);

        sum = addnum(startno, endno);
        printf("Sum %d~%d = %d\n", startno, endno, sum);

        return(0);
}

