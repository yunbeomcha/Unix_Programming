#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

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

                sprintf(buf, "%s", inet_ntoa(cli.sin_addr));
                printf("*** Send a Message to Client(%s)\n", buf);

                strcpy(buf, "Welcome to Network Server!!!");
                if (send(nsd, buf, sizeof(buf), 0) == -1) {
                        perror("send");
                        exit(1);
                }

                if (recv(nsd, buf, sizeof(buf), 0) == -1) {
                        perror("recv");
                        exit(1);
                }
                printf("** From Client : %s\n", buf);
                close(nsd);
        }

        close(sd);

}

