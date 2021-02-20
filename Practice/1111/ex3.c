#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main() {

    int fd[2], a;
    pid_t pid;

    if(pipe(fd) == -1) {
        perror("pipe");
        exit(1);
    }

    switch(pid = fork()) {
        case -1 :
            perror("fork");
            exit(1);
            break;
        case 0 : /* child */
            close(fd[1]);
            if(fd[0] != 0) {
                dup2(fd[0], 0);
                close(fd[0]);
            }
            execlp("wc", "wc", "-l", (char *)NULL);
            break;
        default :
            close(fd[0]);
            if(fd[1] != 1) {
                dup2(fd[1], 1);
                close(fd[1]);
            }
            for(a=1; a<=100; a++)
                write(1, "test line\n", 11); 
            break;
    }
}
