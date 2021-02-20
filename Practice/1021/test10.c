#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp) {
	//명령행 인자

        char **env;

        env = envp;
        while (*env) {
                printf("%s\n", *env);
                env++;
        }
}

