#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int copyfile(int rf, int wf);
int main(int argc,char *argv[]){
   	int rfd, wfd, n;
        char buf[10];
	int copy;

	if(argc != 3){
		write(2, "Usage: append file1 file2\n", 26);
		exit(1);
	}
        rfd = open(argv[1], O_RDONLY);
	
        if(rfd == -1){
        perror(argv[1]);
        exit(1);
        }

        wfd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0644);

        if(wfd == -1){
        perror(argv[2]);
        exit(1);
        }
	
	copyfile(rfd, wfd);
	close(rfd);
        close(wfd);
        return 0;

}
int copyfile(int rf, int wf){
	char buf[10];
	int n;
	while ((n = read(rf, buf, sizeof(buf)) > 0)
        if (write(wf, buf, n) != n)
	perror("Write");
    	
	if (n == -1)
	perror("Read");
}
