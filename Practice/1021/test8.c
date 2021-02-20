#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
        printf("PID : %d\n", (int)getpid());// 프로세스 id
        printf("PGRP : %d\n", (int)getpgrp()); //그룹 id
        printf("PGID(0) : %d\n", (int)getpgid(0));//0인 경우에는 getpgid함를 호출한
	//프로세스가 속한 그룹의 pgid를 return
        printf("PGID : %d\n", (int)getpgid(getpid()));
	
}

