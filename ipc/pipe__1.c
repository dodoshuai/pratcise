#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<errno.h>

int main(){

	int pipefd[2];
	int ret =pipe(pipefd);
	if(ret<0){
		perror("pipe error");
		return -1;
	}
	int pid=fork();
	if(pid<0){
		return -1;
	}else if(pid==0){
		close(pipefd[1]);//close write
		char buf[1024]={0};
		ret=read(pipefd[0],buf,1023);
		if(ret<0){
			perror("read error");
		}
		else {
			printf("buf[%s]\n",buf);
		}
	}else{
		close(pipefd[0]);//close read
				while(1){
					sleep(2);
					char str[]="abcdefg";
					int i=write(pipefd[1],str,strlen(str));
					printf("ret=%d\n",i);
				}
	}
return 0;
}
