//命名管道写端
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>

int main(){
	char *file="./abc.fifo";
	umask(0);
	int ret=mkfifo(file,0664);
	if(ret<0){
		if(errno!=EEXIST)//判断是否是因为存在而报错，不是就打印错误信息并退出
		{
			printf("mkfifo errno!");
			return -1;
		}
	}
	printf("creat mkfifo success!");
	int fd=open(file,O_WRONLY);
	if(fd<0){
		printf("open errno!");
		return -1;
	}
	printf("open file  success!");
	while(1){
		char buf[1024]={0};
		scanf("%s",buf);
		write(fd,buf,strlen(buf));
	}
	close(fd);
	return 0;
}
