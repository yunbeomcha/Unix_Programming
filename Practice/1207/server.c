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
	char buf[256];
	struct sockaddr_un ser, cli;
	int sd, nsd, len, clen;

    	if ((sd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        	perror("socket");
        	exit(1);
    	}

	memset((char *)&ser, 0, sizeof(struct sockaddr_un));
    	ser.sun_family = AF_UNIX;
    	strcpy(ser.sun_path, SOCK_PATH);
    	unlink(ser.sun_path);
    	len = strlen(ser.sun_path) + sizeof(ser.sun_family);
    	if (bind(sd, (struct sockaddr *)&ser, len) == -1) {
        	perror("bind");
        	exit(1);
    	}

    	if (listen(sd, 5) == -1) {
        	perror("listen");
        	exit(1);
    	}

        printf("Waiting for a connection...\n");
        clen = sizeof(cli);
        if ((nsd = accept(sd, (struct sockaddr *)&cli, &clen)) == -1) {
            perror("accept");
            exit(1);
        }


	if (recv(nsd, buf, sizeof(buf), 0) == -1) {
		perror("recv");
		exit(1);
	}

        printf("Received Message: %s.\n", buf);

	close(sd);
	close(nsd);

}

