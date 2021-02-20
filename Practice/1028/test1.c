#include <sys/stat.h>
#include <ftw.h>
#include <stdlib.h>
#include <stdio.h>

int list(const char *name, const struct stat *status, int type)
{

	if (type == FTW_NS) //에러인 경우 종료 
		return 0;

	if (type == FTW_F)
		printf("% - 30s\t0%3o\n", name, status->st_mode&0777); //파일의 이름과 퍼미션 출력
	else
		printf("% - 30s*\t0%3o\n", name, status->st_mode&0777);

	return(0);

}

main(int argc, char **argv) {

	int list(const char *, const struct stat *, int);

	if (argc == 1)
		ftw(".", list, 1); //현재 디렉토리에서부터 list라는 유저 define한 수행된 작업을 수행
	else
		ftw(argv[1], list, 1); //혹은 argc가 1이 아니면 user가 적은 디렉토리에서 수행

	exit(0);
}
