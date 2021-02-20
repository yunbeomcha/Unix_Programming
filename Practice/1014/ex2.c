#include <sys/types.h>
#include <sys/stat.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int match(char *, char*);

main(int argc, char *argv[]) {

        struct stat buf;
	char namebuf1[30], namebuf2[30];

	stat(argv[1], &buf);

	if (match(argv[1], ".ln")) {
        	printf("%s : Link Count = %d\n", argv[1], (int)buf.st_nlink);
        	printf("%s : Inode = %d\n", argv[1], (int)buf.st_ino);
	}
	else if (match(argv[1], ".sym")) {
		lstat(argv[1], &buf);
		readlink(argv[1], namebuf1, 30);
		realpath(argv[1], namebuf2);
        	printf("%s : Link Count = %d\n", argv[1], (int)buf.st_nlink);
        	printf("%s : Inode = %d\n", argv[1], (int)buf.st_ino);
		printf("READLINK = %s\n", namebuf1);
		printf("REALPATH = %s\n", namebuf2);
	}
	else {
		perror("name error");
	}

}

int match(char *s1, char *s2) {

	int diff = strlen(s1) - strlen(s2);

	return(strcmp(&s1[diff], s2) == 0);
}