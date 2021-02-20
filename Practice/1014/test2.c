#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>

main() {

        symlink("unix.txt", "unix.sym");

}

