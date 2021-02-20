#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    int n,i,j, input = 0, tmp;
    long cur;
    fpos_t fcur;
    char buf[BUFSIZ];

    if ((fp = fopen("testdata", "r")) == NULL) {
        perror("fopen: testdata");
        exit(1);
    }
	while((n = fread(buf, sizeof(char), 3, fp))>0){
	printf("Which string (0 to quit)? ");
        scanf("%d", &input);
	if(input != 1){
		input *= 3;
	}	
	fseek(fp, input-1, SEEK_CUR);
    	buf[n] = '\0';
    	printf("%s\n", buf);
	cur = ftell(fp);
	printf("Offset cur = %d\n", (int)cur);
	input -= 3;
	}
    fclose(fp);

    return 0;
}

