#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {
    FILE *fp1, *fp2;
    int a;
    char buf[256];

    if(argc != 2) {
        printf("Usage: a.out filename\n");
        exit(1);
    }

    fp1 = popen("more", "w");
    if(fp1 == NULL) {
        fprintf(stderr, "popen failed\n");
        exit(1);
    }

    fp2 = fopen(argv[1], "r");
    while(fgets(buf, 256, fp2) != NULL)
        fputs(buf, fp1); 

    pclose(fp1);
    fclose(fp2);
}
