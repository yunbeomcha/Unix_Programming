#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

main() {

        struct stat buf;
        int kind;

        stat("unix.txt", &buf);

        printf("Mode = %o ( %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);

        if ((buf.st_mode & S_IREAD) == 0)
                printf("unix.txt : user has no read permission\n");

        if ((buf.st_mode & S_IWRITE) != 0);
                printf("unix.txt : user has a write permission\n");

        if ((buf.st_mode & (S_IREAD >> 3)) != 0)
                printf("unix.txt : group has a read permission\n");

        if ((buf.st_mode & (S_IWRITE >> 3)) != 0)
                printf("unix.txt : group has a write permission\n");

        if ((buf.st_mode & (S_IREAD >> 6)) != 0)
                printf("unix.txt : other have a read permission\n");

        if ((buf.st_mode & (S_IWRITE >> 6)) != 0)
                printf("unix.txt : other have a write permission\n");

        if ((buf.st_mode & S_IROTH) != 0)
                printf("unix.txt : other have a read permission\n");

}

