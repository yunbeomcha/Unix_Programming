#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main() {

	int fd[2];
	pid_t pid;
	char buf[257];
	int len, status;

	if (pipe(fd) == -1) {
		perror("pipe call");
		exit(1);
	} //파이프 함수 호출

	switch (pid = fork()) {
	
	case -1:
		perror("fork call");
		exit(1);
		break;
	case 0: 
		close(fd[1]); //읽기 위해 쓰기 디스크립터를 닫는다.
		write(1, "Child Process: ", 15);
		len = read(fd[0], buf, 256); // 읽은 다음
		write(1, buf, len); //출력
		break;
	default:
		close (fd[0]); // 쓰기위해 읽는 디스크립터를 닫는다.
		buf[0] = '\0'; //마지막은 null
		write(fd[1], "Test Message\n", 14); //파이프에 메세지를 쓴다/
		close(fd[1]); //다 쓴다음 닫는다.
		waitpid(pid, &status, 0); //자식이 끝날때까지 기다린다.
		break;
	}

}

