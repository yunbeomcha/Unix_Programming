#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *usage = "Usage : Directory Suffix\n";


int my_double_ls(const char *, char *);
int match(const char *, const char *);

main(int argc, char **argv) {

        if (argc != 3 ) {
                fprintf(stderr, usage);
                exit(1);
        }

        my_double_ls(argv[1],argv[2]);

        exit(0);
}

int my_double_ls (const char *name, char *suffix) {

        struct dirent *d;
        DIR *dp;

        if ((dp=opendir(name)) == NULL)
                return (-1);

        while (d=readdir(dp)) {
                if (d->d_ino != 0)
                        printf("%s\n", d->d_name);
                if (match(d->d_name, suffix))
                        printf("***Matched %s\n", d->d_name);
        }
        closedir(dp);
        return(0);
}

int match(const char *s1, const char *s2) {

        int diff = strlen(s1) - strlen(s2);

        if (strlen(s1) > strlen(s2))
                return (strcmp(&s1[diff], s2) == 0);
        else
                return (0);

}

