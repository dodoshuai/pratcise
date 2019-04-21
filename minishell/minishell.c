#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){
	//字符串输入
	while(1){
		printf("dodobrid@bogon~:");
		fflush(stdout);
		char buf[1024]={0};
		//%[^\n]获取字符串直到遇见\n
		//%*c 将一个字符从缓冲区中取出
		if(scanf("%[^\n]%*c",buf)!=1){
			getchar();
			continue;
		}
	//	printf("%s\n",buf);
	
	//解析输入的数据
	//buf:[   ls -a  ] 
	char *argv[32];
	int argc=0;
	char *ptr=buf;
	while(*ptr!='\0'){
		if(!isspace(*ptr)){
		//当前位置是非空白字符
		argv[argc++]=ptr;
		while(!isspace(*ptr)&&*ptr!='\0'){
			ptr++;
		}
		}
		*ptr='\0';
		ptr++;
	}
	argv[argc]=NULL;
	if(strcmp(argv[0],"cd")==0){
		//int chdir(const char *path);
		//改变当前工作路径
		chdir(argv[1]);
		continue;
			}
			int pid=fork();
			if(pid<0){
				continue;
			}else if(pid==0){
				if(execvp(argv[0],argv)<0){
					perror("");
				}
				exit(0);
			}
			wait(NULL);
		}
return 0;
}
