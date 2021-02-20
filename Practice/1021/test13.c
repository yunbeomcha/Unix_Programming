#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
        char *val;

        val = getenv("SHELL");
        if (val == NULL)
                printf("SHELL not defined\n");
        else
                printf("1. SHELL = %s\n", val);

        setenv("SHELL", "/usr/bin/csh", 0);//환경변수값을 변경 0이면 overwrite시키지 않는다.
        val = getenv("SHELL");
        printf("2. SHELL = %s\n", val);

        setenv("SHELL", "/usr/bin/csh", 1);//overwrite시킨다.
        val = getenv("SHELL");
        printf("3. SHELL = %s\n", val);
}

