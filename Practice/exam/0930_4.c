#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define BUFSIZE 1024

int main(int argc, char*argv[]) {
    	FILE *fp = fopen("testdata", "r");
	int n,i,j, input = 0, tmp;
	int size;
	long cur;
	off_t start, c_start;
	char buf[BUFSIZE];
	
	if ((fp = fopen("testdata", "r")) == NULL) {
        perror("fopen: testdata");
        exit(1);
	}

	fseek(fp, 0, SEEK_END);
        size = ftell(fp);

	printf("current offset\t: ");
	fseek(fp, 0, SEEK_SET);
	for(i = 0; i <= (size-2) / atoi(argv[1]); i++){
	cur = ftell(fp);
	fseek(fp, atoi(argv[1]), SEEK_CUR);
	printf("%d ", (int)cur);
	}
	printf("\n");
	printf("current data\t: ");
	start = fseek(fp, 0, SEEK_SET);
	for(i = 0; i <= (size-2) / atoi(argv[1]); i++){
	fseek(fp, i * atoi(argv[1]), SEEK_SET);
	n = fread(buf, sizeof(char), 1, fp);
	buf[n] = '\0';
	printf("%s ",buf); 
	
	}
	printf("\n");
    fclose(fp);

    return 0;
}

