#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

extern int errno;

main() {

        struct stat buf;

        stat("unix.txt", &buf);
        printf("Before Link Count = %d\n", (int)buf.st_nlink); //원래 하드링크 수

        link("unix.txt", "unix.ln"); //하드 링크생성

        stat("unix.txt", &buf);
        printf("After Link Count = %d\n", (int)buf.st_nlink);

}
