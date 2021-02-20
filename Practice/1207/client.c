#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>

#define SOCK_PATH "hbsocket"

int main(void)
{
        int sd, len;
        char buf[256];
        struct sockaddr_un ser;

        if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
                perror("socket");
                exit(1);
        }

        memset((char *)&ser, '\0', sizeof(ser));
        ser.sun_family = AF_UNIX;
        strcpy(ser.sun_path, SOCK_PATH);
        len = strlen(ser.sun_path) + sizeof(ser.sun_family);
        if (connect(sd, (struct sockaddr *)&ser, len) == -1) {
                perror("connect");
                exit(1);
        }

        strcpy(buf, "Unix Domain Socket Test Message");
        if (send(sd, buf, strlen(buf), 0) == -1) {
            perror("send");
            exit(1);
        }

        close(sd);

}

