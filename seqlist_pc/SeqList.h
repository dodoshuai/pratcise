#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#include<malloc.h>
typedef int SLDataType;
typedef struct SeqList{
	SLDataType* array;	//指向动态开辟的数组
	size_t size;		//有效数据个数
	size_t capacity;	//容量空间大小
}SeqList;

//基本增删改查接口
//初始化
void SeqListInit(SeqList *ps,int capacity);
//头插
void SeqListPushFront(SeqList *head,SLDataType x);
//头删
void SeqListPopFront(SeqList *head);
//尾插
void SeqListPushBack(SeqList *head,SLDataType x);
//尾删
void SeqListPopBack(SeqList *head);
//根据pos下标做插入
void SeqListInsert(SeqList *ps, int pos, int v);
//指定删除
