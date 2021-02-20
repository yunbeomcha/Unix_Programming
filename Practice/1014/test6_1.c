#include <unistd.h>
#include <stdio.h>

int main(){
	char *cwd;
	cwd = getcwd(NULL, BUFSIZ);
	printf("Current Directory: %s\n", cwd);
	return 0;

}
