#include <netdb.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

main() {
	in_addr_t addr;
	struct hostent *hp;
	struct in_addr in;

	//if ((addr = inet_addr("127.0.0.1")) == (in_addr_t)-1) {
	if ((addr = inet_addr("203.250.148.46")) == (in_addr_t)-1) {
		printf("error : inet addr");
		exit(1);
	}

	hp = gethostbyaddr((char *)&addr, 4, AF_INET);
	if (hp == NULL) {
		printf("host information not found\n");
		exit(2);
	}

	printf("Name = %s\n", hp->h_name);
	memcpy(&in.s_addr, *hp->h_addr_list, sizeof(in.s_addr));
	printf("IP = %s\n", inet_ntoa(in));

}

