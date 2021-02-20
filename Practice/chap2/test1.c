#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;
    mode_t mode;

    fd = open("unix.txt", O_CREAT|O_TRUNC, 0644);
    if (fd == -1) {
        perror("Creat");
        exit(1);
    }
    close(fd);
    return 0;
}

