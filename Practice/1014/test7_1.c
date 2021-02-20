#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
int main(){
	struct stat buf;
	symlink("test.dat", "test.sym");
	
	stat("test.dat", &buf);
	printf("mode = %o\n", (int)buf.st_mode);

	stat("test.sym", &buf);
	printf("mode = %o\n", (int)buf.st_mode);
	return 0;	

}
