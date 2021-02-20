#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    char *cwd;
    char wd[BUFSIZ];

    if(argc != 2) {
        printf("Usage: exc4-4.out dirname\n");
        exit(1);
    }

    cwd = getcwd(NULL, BUFSIZ);
    printf("1.Current Directory : %s\n", cwd);

    chdir(argv[1]);

    cwd = getcwd(NULL, BUFSIZ);
    printf("2.Current Directory : %s\n", cwd);
}
