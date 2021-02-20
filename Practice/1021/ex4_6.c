#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void){
	uid_t uid, euid;
	char *name, *cname;

	uid = getuid();
	euid = geteuid();

	name = getlogin();
	
	printf("Login Nmae = %s UID = %d, EUID = %d\n", name, (int)uid, (int)euid);

	return 0;
}
