#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

main() {

        struct stat buf;
	int kind;

        stat("unix.txt", &buf);

        printf("Mode = %o ( %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
	
	kind = buf.st_mode & S_IFMT;
	printf("Kind = %x\n", kind);

        if (S_ISFIFO(buf.st_mode))
		printf("unix.txt : FIFO\n");
        if (S_ISDIR(buf.st_mode))
		printf("unix.txt : Directory\n");
        if (S_ISREG(buf.st_mode))
		printf("unix.txt : Regular File\n");
	
	switch(kind){
		case S_IFIFO:
			printf("unix.txt : FIFO\n");
			break;
		case S_IFDIR:
			printf("unix.txt : Directory\n");
			break;
		case S_IFREG:
			printf("unix.txt : Regular file\n");
			break;
	}
	return 0;
}

