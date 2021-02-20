#include <stdio.h>
#include <stdlib.h>

int main(void){
	pid_t pid;
	int n;
	int i;
	char ch = 'A';
	char ch2 = 'a';
	switch(pid = fork()){
		case -1:
		perror("fork");
		exit(1);
		break;
		
		case 0:
		printf("child: %d\n", (int)getpid());
		for(i = 0; i<26; i++){
			printf("%c ", ch2 + i);
		}
		printf("\n");
		break;

		default :
		printf("parent: %d\n", (int)getpid());
		for(i = 0; i<26; i++){
			printf("%c ", ch + i);
		}
		printf("\n");
		break;
	}
	return 0;	
}


