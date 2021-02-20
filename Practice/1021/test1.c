#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>

main()
{
        struct  utsname system_info;

        uname(&system_info);

        printf("OS name : %s\n",system_info.sysname);
        printf("Node name : %s\n",system_info.nodename);
        printf("Release : %s\n", system_info.release);
        printf("Version : %s\n", system_info.version);
        printf("Machine : %s\n", system_info.machine);
}


