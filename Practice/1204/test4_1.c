#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {

	char ch, first, last;
	int pid;
	long i;

	if ((pid = fork()) > 0) {
	
		first = 'A';
		last = 'Z';
	}
	else if (pid == 0) {

		first = 'a';
		last = 'z';
	}
	else {
		perror(argv[0]);
		exit(1);
	}

	printf("\n");
	for (ch = first; ch <= last; ch++) {

		for (i=0; i<10; i++)
			write(1, &ch, 1);
	}
	printf("\n");
}	


