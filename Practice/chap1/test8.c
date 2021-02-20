#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int n;

    if(argc == 1) {
        printf("Usable Options : -a -u -h\n");
        exit(0);
    }

    if (!(strcmp(argv[1], "-a"))) {
        printf("Welcome Unix System Programming World!\n");
    }
    else if (!(strcmp(argv[1], "-u"))) {
        printf ("Nice to meet %s\n", argv[1]);
    }
    else {
        printf("Usable Options : -a -u -h\n");
    }
}

