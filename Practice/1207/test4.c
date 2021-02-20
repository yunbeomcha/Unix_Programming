#include <netdb.h>
#include <stdio.h>

main() {
	struct servent *port;

	port = getservbyname("telnet", "tcp");
	printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));

	port = getservbyport(htons(21), "tcp");
	printf("Name=%s, Port=%d\n", port->s_name, ntohs(port->s_port));

}

