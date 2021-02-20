#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>


int main(int argc, char *argv[]) {

        struct stat buf;
        int kind;
	int per, i;
	char mode[10] = {0,};
        stat("unix.txt", &buf);

        printf("File Name : %s\n", argv[1]);
	printf("Inode Number : %d\n", (int)buf.st_ino);
        kind = buf.st_mode & S_IFMT;
        
        switch (kind) {

                case S_IFIFO:
                        printf("File Type : FIFO\n");
                        break;
                case S_IFDIR:
                        printf("File Type : Directory\n");
                        break;
                case S_IFREG:
                        printf("File Type : Regular File\n");
                        break;	
        }
	printf("Permission : ");
	if((buf.st_mode & S_IRUSR) != 0){
        	mode[0] = 'r';
	}
	else{
        	mode[0] = '-';
	}
	if((buf.st_mode & S_IWUSR) != 0){
        	mode[1] = 'w';
	}
	else{
		mode[1] = '-';
	}
	if((buf.st_mode & S_IXUSR) != 0){
        	mode[2] = 'x';
	}
	else{
		mode[2] = '-';
	}
	
	if((buf.st_mode & S_IRGRP) != 0){
        	mode[3] = 'r';
	}
	else{
		mode[3] = '-';
	}
	if((buf.st_mode & S_IWGRP) != 0){
        	mode[4] = 'w';
	}
	else{
		mode[4] = '-';
	}
    	if((buf.st_mode & S_IXGRP) != 0){
        	mode[5] = 'x';
	}
	else{
		mode[5] = '-';
	}

    	if((buf.st_mode & S_IROTH) != 0){
        	mode[6] = 'r';
	}
	else{
		mode[6] = '-';
	}
	if((buf.st_mode & S_IWOTH) != 0){
        	mode[7] = 'w';
	}
	else{
		mode[7] = '-';
	}
    	if((buf.st_mode & S_IXOTH) != 0){
        	mode[8] = 'x';
	}
	else{
		mode[8] = '-';
	}
	
	printf("%s", mode);

	printf("\n");
	printf("UID : %d\n", (int)buf.st_uid);
	printf("Size : %d\n",(int)buf.st_size);
}

