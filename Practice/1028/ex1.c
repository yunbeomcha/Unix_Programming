#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ftw.h>
#include <time.h>

char typeOfFile(mode_t);
char *permOfFile(mode_t);

main (int argc, char **argv) {

	char *filename;
	struct stat st;
	int outputStatInfo(const char *, const struct stat *, int );

	ftw(".", outputStatInfo, 1);

	exit(0);
}

int outputStatInfo(const char *filename, const struct stat *st, int type) {


        printf("%c%s ", typeOfFile(st->st_mode), permOfFile(st->st_mode));

        if (((st->st_mode & S_IFMT) != S_IFCHR) &&
                ((st->st_mode & S_IFMT) != S_IFBLK)) {
                printf("%9d ", st->st_size);
        }
        else {
                printf("%4d,%4d ", major(st->st_rdev), minor(st->st_rdev));
        }

        printf("%.12s ", ctime(&st->st_mtime)+4);
        printf("%s\n", filename);

	return 0;
}

char typeOfFile(mode_t mode) {

        switch(mode & S_IFMT) {

                case S_IFREG:
                        return('-');
                case S_IFDIR:
                        return('d');
                case S_IFCHR:
                        return('c');
                case S_IFBLK:
                        return('b');
                case S_IFLNK:
                        return('l');
                case S_IFIFO:
                        return('p');
                case S_IFSOCK:
                        return('s');
        };
        return('?');
}

char *permOfFile(mode_t mode) {

        int i;
        char *p;
        static char perms[9];

        p=perms;
        strcpy(perms, "---------");

        for (i=0; i<3; i++) {

                if (mode & (S_IREAD >> i*3))
                        *p = 'r';
                        p++;

                if (mode & (S_IWRITE >> i*3))
                        *p = 'w';
                        p++;

                if (mode & (S_IEXEC >> i*3))
                        *p = 'x';
                        p++;
        }


        if ((mode & S_ISUID) != 0)
                perms[2] = 's';

        if ((mode & S_ISGID) != 0)
                perms[5] = 's';


        if ((mode & S_ISVTX) != 0)
                perms[8] = 't';

        return (perms);

}



