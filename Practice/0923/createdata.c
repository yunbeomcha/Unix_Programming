#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *name[] = {
        "David Hutchison",
        "Takeo Kanade",
        "Josef Kittler",
        "John M. Kleinberg",
        "Friedemann Mattern",
        "John C. Mitchell",
        "Moni Naor",
        "Oscar Nierstrasz",
        "C. Pandu Rangan",
        "Bernhard Steffern",
        "Madhu Sudan",
        "Demetri Tygar",
        NULL
};

int
main() {

        int i, out;
        char wbuf[64];

        memset(wbuf, 0, sizeof(wbuf));
	//초기화 시켜주는 함수
        if ((out = open("residents", O_CREAT|O_RDWR, 0644)) < 0) {
                perror("no testdata");
                exit(1);
        }

        for (i=0; name[i]!=NULL; i++) {
                memcpy(wbuf, name[i], sizeof(wbuf));
                write(out, wbuf, sizeof(wbuf));//arr에 있는 값을 리턴해줘서 카피를 해준다.
		printf(" %s %d %s\n", wbuf, i+1, name[i]);
                memset(wbuf, 0, sizeof(wbuf)); //write버퍼를 다시 초기화해준다.
        }

        close (out);

}

