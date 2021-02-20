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

        if ((sd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
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

        while (1) {

                clen = sizeof(cli);
                if ((recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cli, &clen)) == -1) {
                        perror("recvfrom");
                        exit(1);
                }
                printf("** From Client %s\n", buf);
                strcpy(buf, "Hello Client");
                if ((sendto(sd, buf, sizeof(buf), 0, (struct sockaddr *)&cli, sizeof(cli))) == -1) {
                        perror("sendto");
                        exit(1);
                }
        }

}

