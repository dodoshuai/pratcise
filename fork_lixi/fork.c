#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
	for(int i=0;i<2;i++){
		printf("%d",i);
		fork();
		printf("-");
		//printf("%d _\n",i++);
	}
return 0;
}
