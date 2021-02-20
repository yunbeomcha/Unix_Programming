#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	if(execlp("ls", "ls", "-la", (char*)NULL) == -1){
		perror("execlp");
		exit(1);
	}
	return 0;

}
