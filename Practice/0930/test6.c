#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

int main(void) {
    FILE *fp;
    int n,i,j, input = 0, tmp;
    long cur;
    fpos_t fcur;
    char buf[BUFSIZE];

    if ((fp = fopen("testdata", "r")) == NULL) {
        perror("fopen: testdata");
        exit(1);
    }
	while(1){
	printf("Which string (0 to quit)? ");
        scanf("%d", &input);	
	
	fseek(fp, 3*(input -1), SEEK_SET);
	n = fread(buf, sizeof(char), 3, fp);
        buf[n] = '\0';
    	printf("%s\n", buf);
	}
    fclose(fp);

    return 0;
}

