#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void){
	DIR *dp;
	struct dirent *dent;
	struct stat sbuf;
	char path[BUFSIZ];
	if((dp = opendir(".")) == NULL){
		perror("opendir:");
		exit(1);	
	}

	while ((dent = readdir(dp))){
		if(dent->d_name[0] == '.')
			continue;
		stat(dent->d_name, &sbuf);
		if((int)sbuf.st_nlink >= 2){
			printf("Name: %s\n", dent->d_name);
			printf("Link Count: %d\n\n", (int)sbuf.st_nlink);
		}
	}
	return 0;

}
