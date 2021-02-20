#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORTNUM 9001

int main(void)
{
        char buf[256];
        struct sockaddr_in ser, cli;
        int sd, nsd, len, clen;

        if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
        }

        memset((char *)&ser, 0, sizeof(struct sockaddr_in));
        ser.sin_family = AF_INET;
        ser.sin_port = htons(PORTNUM);
        len = sizeof(ser);
        ser.sin_addr.s_addr = inet_addr("203.250.148.46");

        if (bind(sd, (struct sockaddr *)&ser, len) == -1) {
                perror("bind");
                exit(1);
        }

        if (listen(sd, 5) == -1) {
                perror("listen");
                exit(1);
        }

        printf("Waiting for a connection...\n");

        while (1) {

                clen = sizeof(cli);
                if ((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1) {
                        perror("accept");
                        exit(1);
                }

                printf("** Accept Client\n");

                switch(fork()) {

                        case 0:
                                printf("** Fork Client\n");
                                close(sd);
                                dup2(nsd, STDIN_FILENO);
                                dup2(nsd, STDOUT_FILENO);
                                close(nsd);
                                execl("./sample1", "sample1", (char *)0);
                }
                close(nsd);
        }
}
