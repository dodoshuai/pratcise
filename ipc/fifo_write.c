/*  命名管道的基本使用
 *  命名管道可见于文件系统，会 创建一个管道文件（文件只是名字）
 *  管道通信的本质还是内核的那块缓冲区
 *  int mkfifo(const char *pathname, mode_t mode);
 *      pathname：  管道文件的路径名
 *      mode:       创建文件的权限
 *  返回值：0   失败：-1
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    char *file = "./tmp.fifo";
    umask(0);
    int ret = mkfifo(file, 0664);
    if (ret < 0) {
        //如果文件不是因为已经存在而报错，则退出
        if (errno != EEXIST) {
            perror("mkfifo error");
            return -1;
        }
    }
    printf("create fifo success!!\n");
    int fd = open(file, O_WRONLY);
    if (fd < 0) {
        perror("open error");
        return -1;
    }
    printf("open fifo success!!\n");
    while(1) {
        char buf[1024] = {0};
        scanf("%s", buf);
        write(fd, buf, strlen(buf));
    }
    close(fd);
    return 0;
}
