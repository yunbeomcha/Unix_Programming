#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main (int argc, char **argv){
	struct stat buf;
	int per, i;
	char mode[10] = {0,};
	stat("unix.txt", &buf);
	
	switch(argv[1][0]){
	case 'u':
		if(argv[1][1] == '+'){
			switch(argv[1][2]){
			case 'r':
			buf.st_mode |= S_IRUSR;
			chmod("unix.txt", buf.st_mode);
			break;
			case 'w':
			buf.st_mode |= S_IWUSR;
			chmod("unix.txt", buf.st_mode);
			break;
			case 'x':
			buf.st_mode |= S_IXUSR;
			chmod("unix.txt", buf.st_mode);
			break;
			default:
			break;
			}
		}
		else if(argv[1][1] == '-'){
                        switch(argv[1][2]){
                        case 'r':
                        buf.st_mode &= ~(S_IRUSR);
			chmod("unix.txt", buf.st_mode);
                        break;  
                        case 'w':
                        buf.st_mode &= ~(S_IWUSR);
			chmod("unix.txt", buf.st_mode);
                        break;
                        case 'x':
                        buf.st_mode &= ~(S_IXUSR);
			chmod("unix.txt", buf.st_mode);
                        break;
                        default:
                        break;
                	}
                }
	break;
	case 'g':
	if(argv[1][1] == '+'){
                        switch(argv[1][2]){
                        case 'r':
                        buf.st_mode |= S_IRGRP;
			chmod("unix.txt", buf.st_mode); 
		       break;  
                        case 'w':
                        buf.st_mode |= S_IWGRP;
			chmod("unix.txt", buf.st_mode);
                        break;
                        case 'x':
                        buf.st_mode |= S_IXGRP;
			chmod("unix.txt", buf.st_mode);
                        break;
                        default:
                        break;
                        }
	}
	else if(argv[1][1] == '-'){
                        switch(argv[1][2]){
                        case 'r':
                        buf.st_mode &= ~(S_IRGRP);
			chmod("unix.txt", buf.st_mode);
                        break;  
                        case 'w':
                        buf.st_mode &= ~(S_IWGRP);
			chmod("unix.txt", buf.st_mode);
                        break;
                        case 'x':
                        buf.st_mode &= ~(S_IXGRP);
			chmod("unix.txt", buf.st_mode);
                        break;
                        default:
                        break;
                        }
        }
	break;
	case 'o':	
	if(argv[1][1] == '+'){
                        switch(argv[1][2]){
                        case 'r':
                        buf.st_mode |= S_IROTH;
			chmod("unix.txt", buf.st_mode);
                        break;  
                        case 'w':
                        buf.st_mode |= S_IWOTH;
			chmod("unix.txt", buf.st_mode);
                        break;
                        case 'x':
                        buf.st_mode |= S_IXOTH;
			chmod("unix.txt", buf.st_mode);
                        break;
                        default:
                        break;
                        }
        }
	else if(argv[1][1] == '-'){
                        switch(argv[1][2]){
                        case 'r':
                        buf.st_mode &= ~(S_IROTH);
			chmod("unix.txt", buf.st_mode);
                        break;  
                        case 'w':
                        buf.st_mode &= ~(S_IWOTH);
			chmod("unix.txt", buf.st_mode);
                        break;
                        case 'x':
                        buf.st_mode &= ~(S_IXOTH);
			chmod("unix.txt", buf.st_mode);
                        break;
                        default:
                        break;
                        }
                }
	break;
	default:
	break;
	}
}
