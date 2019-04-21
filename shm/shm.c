//1.创建
//2.建立映射
//3.内存操作
//4.解除操作
//5.删除
//
//ftok 生成key值
//
#include<stdio.h>
#include<sys/shm.h>
#include<stdlib.h>



int main(void){
	//1.创建
	//	key_T ftok(const char *pathname,int proj_id);
	//	通过文件inode几点好与proj_id生成一个key值
	//	shmget(key_t key,size_t size,int shmflg);
	//	key:共享内存标识符
	//	size：共享内存大小
	//	shmflg：选项标志
	//	IPC_CREAT	共享内存不存在则创建，存在则打开
	//	IPC_EXCL	与IPC_CREAT共用，则共享内存存在是报错
	//	shm_mode	权限
	//	返回值：	标识符（代码中的操作句柄）
	//key_t	key=ftok(".",PROJ_ID);
	int shmid=shmget(IPC_KEY,32,IPC_CREAT|0664);
	if(shmid<0)
	{
		perror("shmget open error!");
		return -1;
	}
	//建立映射
	//void *shmat(int shmid，const void *shmaddr，int shmflg);
	//shmid	创建共享内存，返回的句柄
	//shmaddr:	置空-映射首地址有操作系统
	//shmflg:	映射成功后的操作权限
	//	SHM_RDONLY	只读
	//	0	默认-可读可写
	//	返回值：映射首地址 	失败：(void *)-1
	char *shm_start=shmat(shmid,NULL,0);
	if(shm_start==(void *)-1){
		perror("shmat error");
		return -1;
	}
	while(1){
		sprintf(shm_start，"今天天气好热"，i++);
		sleep(1);
	}
	//解除映射
	//int shmdt()
	//shmaddr:映射首地址
	shmdt(shm_start);
	//删除
	//int shmctl(int shmid,int cmd,struct shmid_ds *buf);
	//shmid:	操作句柄
	//cmd:	操作类型
	//IPCRMID	删除共享内存
	//buf:	设置/获取共享内存信息
	//共享内存不会被直接删除，而是判断映射连接数是否为0
	//为零：直接删除
	//不为零：拒绝后续其他进程的映射链接，当映射链接数为0是自动删除
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}i
