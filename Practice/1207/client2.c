#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORTNUM 9001

int main(void)
{
        int sd, len;
        char buf[256];
        struct sockaddr_in ser;

        if ((sd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
        }

        memset((char *)&ser, '\0', sizeof(ser));
        ser.sin_family = AF_INET;
        ser.sin_port = htons(PORTNUM);
        //ser.sin_addr.s_addr = INADDR_ANY;
        ser.sin_addr.s_addr = inet_addr("203.250.148.46");

        if (connect(sd, (struct sockaddr *)&ser, sizeof(ser)) == -1) {
                perror("connect");
                exit(1);
        }

        if (recv(sd, buf, sizeof(buf), 0) == -1) {
            perror("recv");
            exit(1);
        }

        printf("From Server : %s\n", buf);

        strcpy(buf, "I want a HTTP Service.");
        if (send(sd, buf, sizeof(buf), 0) == -1) {
                perror("send");
                exit(1);
        }

        close(sd);

}

