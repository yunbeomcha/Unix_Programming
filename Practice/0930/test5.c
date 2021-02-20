#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fp;
    int n;
    long cur;
    fpos_t fcur;
    char buf[BUFSIZ];

    if ((fp = fopen("unix.txt", "r")) == NULL) {
        perror("fopen: unix.txt");
        exit(1);
    }

    cur = ftell(fp);//ftell로 현재 오프셋을 알 수 있다.
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 4, fp);
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    fseek(fp, 1, SEEK_CUR);//현재 포지션에서 하나를 이동한 다음

    cur = ftell(fp); //현재의 옾셋을 출력하고
    printf("Offset cur=%d\n", (int)cur);

    n = fread(buf, sizeof(char), 6, fp); //6바이트만큼 읽어라
    buf[n] = '\0';
    printf("-- Read Str=%s\n", buf);

    fclose(fp);

    return 0;
}


