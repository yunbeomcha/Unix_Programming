#include <stdlib.h>
#include <unistd.h>

#define SIZE 512

int main() {

        ssize_t nread;
        char buf[SIZE];

        while ((nread = read(0, buf, SIZE)) > 0)//화면으로부터 데이터를 읽는다.
		//표준입력
                write (1, buf, nread);//읽은 데이터를 화면에 출력(표준출력)

        exit(0);
}

