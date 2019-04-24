#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
int * thread(void * arg)
{
	        pthread_t newthid;
			        newthid = pthread_self();
					        printf("this is a new thread,thread ID = %lu\n",newthid);
							        return NULL;
}
int main(void)
{
	        pthread_t thid;
			        printf("main thread,ID is %lu\n",pthread_self());  //pthread_self()获取本线程id。
					        if(pthread_create(&thid,NULL,(void *)thread,NULL)!=0) //创建线程
								        {
											                printf("thread creation failed\n");
															                exit(1);
																			        }
							        sleep(1);
									        exit(0);
}
