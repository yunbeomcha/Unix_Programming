#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){
	struct stat buf;
	char buf2[BUFSIZ];
	int n;
	
	stat("unix.txt", &buf);
	link("unix.txt", "unix1.ln");
	link("unix.txt", "unix2.ln");

	symlink("unix.txt", "unix1.sym");
	symlink("unix.txt", "unix2.sym");
	
	stat("*.ln", &buf);
	printf("hard link Count: %d\n", (int)buf.st_nlink);
	printf("Inode = %d\n", (int)buf.st_ino);

	stat("*.sym", &buf);
	printf("sym link Count: %d\n", (int)buf.st_nlink);
	printf("Inode = %d\n", (int)buf.st_ino);
	
	realpath("*.sym", buf2);
	printf("*.sym: Realpath = %s\n", buf);

	return 0;
} 
