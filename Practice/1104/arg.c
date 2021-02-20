#include <stdio.h>
#include <stdlib.h>

main(int argc, char **argv, char **envp) {

        int n;
        char **env;

        printf("\n--> In Main\n");
        printf("argc = %d\n",argc);
        for (n=0; n<argc; n++)
                printf("argv[%d] = %s\n", n, argv[n]);

        env = envp;
        while (*env) {
                printf("%s\n", *env);
                env++;
        }
}

