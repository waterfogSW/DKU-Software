/* mycp.c file copy program using system call, by san kim, waterfog9580@gmail.com*/
#include<unistd.h> // SEEK_CUR, SEEK_END, SEEK_SET
#include<stdio.h> //standard IO
#include<errno.h> //error code
#include<fcntl.h> // O_RDONLY, O_CREAT, O_EXCL
#include<sys/stat.h> //file stat structure
#include<sys/types.h>
#include<utime.h> //last access, modify time modify
#define MAX_BUF 64 //Buffer size

int main(int argc,char *argv[]){
    int fd_src, fd_dest;
    int read_size, write_size;
    char buf[MAX_BUF];
    struct stat st_source;
    struct utimbuf ust_source;

    /* argument check */
    if(argc != 3){
		perror("Invalid number of argument\n");
		exit(-1);
	}

    /* source open */
	if((fd_src = open(argv[1], O_RDONLY)) == -1){
		perror("source open error");
		exit(-1);
	}

    /* destination open */
    if((fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_EXCL)) == -1){
		perror("destination open error");
		exit(-1);
	}

    /* file content copy */
    while(1){
        read_size = read(fd_src,buf,MAX_BUF);
        if(read_size == 0) break;
        write_size = write(fd_dest, buf, read_size);
    }

    /* get attribute from source file */
    fstat(fd_src, &st_source);
    ust_source.actime = st_source.st_atime;
    ust_source.modtime = st_source.st_mtime;

    /* assign attribute to destination file */
    chmod(argv[2], st_source.st_mode);
    chown(argv[2], st_source.st_uid, st_source.st_gid);
    utime(argv[2], &ust_source);

    /* close file desriptor */
    close(fd_src);
    close(fd_dest);
    return 0;
}