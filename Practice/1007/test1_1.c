#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

main(int argc, char **argv) {

        if (argc < 2 ) {
                fprintf(stderr, "Usage: lookout filename ...\n");
                exit(1);
        }

        filedata(argc, argv);

        exit(0);
}

