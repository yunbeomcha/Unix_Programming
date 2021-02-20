#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

int main(void) {
    int pd, n;
    char msg[80];

    if ((pd = open("./HAN-FIFO", O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }
	printf("Server ==== \n");
    write(0, "From Client : ", 13);
	
	while((n = read(pd, msg, 80))>0)
		write(1,msg, n);

    if (n == -1) {
        perror("read");
        exit(1);
    }
	write(1, "\n", 1);
    close(pd);

    return 0;
}

