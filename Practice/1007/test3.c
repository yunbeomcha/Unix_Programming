#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

main() {

        struct stat buf;
        int kind;

        stat("FIFO", &buf);

        printf("Mode = %o ( %x) %d\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode,(unsigned int)buf.st_mode);

        kind = buf.st_mode & S_IFMT;
        printf("kind = %x\n", kind);

        switch (kind) {

                case S_IFIFO:
                        printf("unix.txt : FIFO\n");
                        break;
                case S_IFDIR:
                        printf("unix.txt : Directory\n");
                        break;
                case S_IFREG:
                        printf("unix.txt : Regular File\n");
                        break;
        }
}

