#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/errno.h>
int main(int argc, char *argv[]) {
    int pd, n;
    char msg[80];
	
    printf("Client === \n");
    if(mkfifo("./HAN-FIFO", 0666)== -1){
	if(errno != EEXIST){
		perror("mkfifo");
		exit(1);
}
    }
    if ((pd = open("./HAN-FIFO", O_WRONLY)) == -1) {
        perror("open");
        exit(1);
    }
    printf("To Server : %s\n", argv[1]);
    n = write(pd, argv[1], strlen(argv[1]) + 1);

    if (n == -1) {
        perror("write");
        exit(1);
    }

    close(pd);

    return 0;
}

