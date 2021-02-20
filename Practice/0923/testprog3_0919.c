#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 512

int main(void){
	ssize_t nread;
	char buf[SIZE];
	
	while (((nread = read(0, buf, SIZE))) > 0)
	//표준 입력으로부터 인자를 받는 방법
		write(1, buf, nread);
	//표준 출력을 할 경우
	return 0;
}
