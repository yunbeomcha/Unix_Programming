#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char argv[]){
	int n;
	if(argc == 1){
	printf("Usable Option : -a -u -h\n");
	exit(0);
	}
	if(!(strcmp(argv[1], "-a"))){
		printf("Welcom Unix System Programming world!\n");
	}
	else if(!(strcmp(argv[1], "-u"))){
	printf("Nice to meet argv[%s]", argv[1]);
	}
	else{
	printf("Usable Options : -a -u -h\n");
	}
}
