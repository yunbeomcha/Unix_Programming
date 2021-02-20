#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        char buf[256];
        int len, ns;

        ns = atoi(argv[1]);

        strcpy(buf, "Welcome to Server, from Bit");
        if ((send(ns, buf, sizeof(buf), 0)) == -1) {
                perror("send");
                exit(1);
        }

        if ((len = recv(ns, buf, sizeof(buf), 0)) == -1) {
                perror("recv");
                exit(1);
        }

        printf("** [Test2] From Client: %s\n", buf);
        close(ns);
}

