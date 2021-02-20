#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main() {

        char *cwd;
        char wd[BUFSIZ];

        cwd = getcwd(NULL, BUFSIZ); //현재 디렉토리 위치
        printf("1. Current Directory : %s\n", cwd);

        chdir ("hanbit"); //디렉토리 이동

        getcwd(wd, BUFSIZ);
        printf("2. Current Directory : %s\n", wd);

}

