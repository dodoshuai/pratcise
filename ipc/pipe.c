/*  匿名管道的基本使用
 *  int pipe(int pipefd[2]);
 *      pipefd: 输出型参数---用于获取管道操作句柄
 *      pipefd[0]   管道的读取端
 *      pipefd[1]   管道的写入端
 *  返回值：0   失败：-1
 * */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
    int pipefd[2];

    int ret = pipe(pipefd);
    if (ret < 0) {
        perror("pipe error");
        return -1;
    }
    //使用匿名管道实现子进程与父进程之间的通信
    //父进程-写     子进程-读
    int pid = fork();
    if (pid < 0) {
        return -1;
    }else if (pid == 0) {
        close(pipefd[1]);
        //chil
//		while(1){
        char buf[1024] = {0};
        ret = read(pipefd[0], buf, 1023);
        if (ret < 0) {
            perror("read error");
		}else {
            printf("buf:[%s]\n", buf);
		}
  //      }
    }else {
        close(pipefd[0]);
        //parent
        int i = 0;
        while(1) {
            char ptr[]= "wodeskdjfl";
            i = write(pipefd[1], ptr, strlen(ptr));
            printf("ret:%d\n", i);
			sleep(5);
        }

    }
    return 0;
}
