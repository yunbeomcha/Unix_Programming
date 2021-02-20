#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int count;
void alrm_action(int);

main() {
        int p[2];
        int pipe_size;
        char c='x';
        static struct sigaction act;

        act.sa_handler = alrm_action;
        sigfillset(&(act.sa_mask));

        if (pipe(p) == -1) {
                perror("pipe call");
                exit(1);
        }

        pipe_size = fpathconf(p[0], _PC_PIPE_BUF);
        printf("Maximum size of write to pipe : %d bytes\n", pipe_size);

        sigaction(SIGALRM, &act, NULL);

        while (1) {
                alarm(2); //2초동안 기다린다.
                write(p[1], &c, 1);

                //alarm(0);
                if ((++count % 1024) == 0)
			printf("%d characters in pipe\n", count);
        }
}

void alrm_action(int signo) { //시그널이 발생되면 수행
        printf("write blocked after %d characters\n", count);
        exit(0);
}

