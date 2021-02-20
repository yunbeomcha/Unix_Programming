#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main() {

	printf("--> Before exec function\n");

	if (execlp("ls", "ls", "-la", (char *)NULL) == -1) { //함수명, argument0, 인자, null
		perror("execlp");
		exit(1);
	}
	
	printf("--> After exec function\n");
}




