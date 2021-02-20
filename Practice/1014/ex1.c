#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    struct stat buf;
    int x;

    if(argc != 3) {
        printf("Usage : mychmod perm file");
        exit(1);
    }

    stat(argv[2], &buf);

    switch(argv[1][0]) {
        case 'u':
            switch(argv[1][2]) {
                case 'r': x = S_IRUSR; break;
                case 'w': x = S_IWUSR; break;
                case 'x': x = S_IXUSR; break;
                default :
                    printf("Permission mode error\n");
                    exit(1);
            }
            break;
        case 'g':
            switch(argv[1][2]) {
                case 'r': x = S_IRGRP; break;
                case 'w': x = S_IWGRP; break;
                case 'x': x = S_IXGRP; break;
                default :
                    printf("Permission mode error\n");
                    exit(1);
            }
            break;
        case 'o':
            switch(argv[1][2]) {
                case 'r': x = S_IROTH; break;
                case 'w': x = S_IWOTH; break;
                case 'x': x = S_IXOTH; break;
                default :
                    printf("Permission mode error\n");
                    exit(1);
            }
            break;
        default :
            printf("Permission mode error\n");
            exit(1);
    }
    if(argv[1][1] == '+') buf.st_mode |= x;
    else if(argv[1][1] == '-') buf.st_mode &= ~(x);

    chmod(argv[2], buf.st_mode);
}
