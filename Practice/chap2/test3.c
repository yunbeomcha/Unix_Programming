#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int fd;
    mode_t mode;

    fd = open("unix.txt", O_RDWR, 0644);
    if (fd == -1) {
        perror("Excl");
        exit(1);
    }

    printf("unix.txt : fd = %d\n", fd);
    close(fd);
    return 0;
}

