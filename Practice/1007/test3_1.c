#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/errno.h>


int main(int argc, char *argv[]) {

        struct stat buf;
        int kind;
	int per, i;
	char arr[10] = {0,};
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
	if((buf.st_mode & S_IREAD) != 0){
		printf("r");
	}
	else{
		printf("-");
	}
	if((buf.st_mode & S_IWRITE) != 0){
                printf("w");
        }       
        else{
                printf("-");
        }
	if((buf.st_mode & S_IEXEC) != 0){
                printf("x");
        }       
        else{
                printf("-");
        }


	if((buf.st_mode & S_IREAD >> 3) != 0){
                printf("r");
        }       
        else{
                printf("-");
        }
	if((buf.st_mode & S_IWRITE >> 3) != 0){
                printf("w");
        }       
        else{
                printf("-");
        }
	if((buf.st_mode & S_IEXEC >> 3) != 0){
                printf("x");
        }       
        else{
                printf("-");
        }
	
	if((buf.st_mode & S_IREAD >> 6) != 0){
                printf("r");
        }       
        else{
                printf("-");
        }
	if((buf.st_mode & S_IWRITE >> 6) != 0){
                printf("w");
        }
        else{
                printf("-");
        }
	if((buf.st_mode & S_IEXEC >> 6) != 0){
                printf("x");
        }
        else{
                printf("-");
        }
	
	
	printf("\n");
	printf("UID : %d\n", (int)buf.st_uid);
	printf("Size : %d\n",(int)buf.st_size);
}

