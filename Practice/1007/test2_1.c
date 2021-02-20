#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#define MFILE 10

void cmp(const char *, size_t *);
struct stat sb;

filedata(int argc, char **argv) {

        int j;
        time_t last_time[MFILE+1];
	size_t size[MFILE+1];
        if (argc < 2) {
                fprintf(stderr, "Usage: lookout filename ...\n");
                exit(1);
        }

        if (--argc > MFILE) {
                fprintf(stderr, "lookout: too many filenames\n");
                exit(1);
        }

        for (j=1;j<=argc;j++) {
                if (stat(argv[j], &sb) == -1) {
                        fprintf(stderr, "lookout: couldn't stat %s\n", argv[j]);
                        exit(1);
                }
                size[j] = sb.st_size;
        }

        for (;;) {
                for (j=1; j<=argc; j++) {
                        printf("%d %d %s filesize:%d\n", argc, j, argv[j], size[j]);
                        cmp(argv[j], &size[j]);
                        sleep(1);
                }
        }
}

void cmp(const char *name, size_t *last) {
	
        if (stat(name, &sb) == -1 || sb.st_size != *last) {
                fprintf(stderr, "lookout: %s file size has been changed to %d\n", name, sb.st_size);
                *last = sb.st_size;
#if 0
                exit(0);
#endif
        }
}

