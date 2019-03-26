#include"SeqList.h"
//初始化
void SeqListInit(SeqList *ps,int capacity)
{
	ps->array = malloc(sizeof(int)*capacity);
	assert(ps->array != NULL);
	ps->size = 0;
	ps->capacity = capacity;
}
//头插
void SeqListPushFront(SeqList *head,SLDataType x){
	SeqList *p1=head;//保存头指针
	size_t capacity=p1->capacity;
	if(p1->size==p1->capacity){
		p1->capacity*=2;
		capacity=p1->capacity;
	}
	SLDataType *newarray=(SLDataType *)malloc(capacity*sizeof(SLDataType));
	for(int i=p1->size-1;i>=0;++i){
		newarray[i]=p1->array[i];
	}
	newarray[0]=x;
	free(p1->array);
	p1->array=newarray;
	p1->size++;
}
 //头删
 void SeqListPopFront(SeqList *head){
	assert(head->size>0);
	for(int i=1;i<=head->size-1;++i){
		head->array[i-1]=head->array[i];
	}
	head->size--;
}

 //尾插
 void SeqListPushBack(SeqList *head,SLDataType x){
	size_t capacity=head->capacity;
	if(head->size==head->capacity){
		capacity=2*head->capacity;
		head->array=(SLDataType*)realloc(head->array,sizeof(SLDataType)*capacity);
		head->capacity=capacity;
	}
	head->array[head->size]=x;
	head->size++;	
}
 //尾删
 void SeqListPopBack(SeqList *head){
	assert(head->size>0);
	head->size--;
}
//pos插入
//根据pos下标做插入
void SeqListInsert(SeqList *ps, int pos, int v){
	assert(pos>0&&pos<ps->size);
	for(int i=ps->size;i>pos;--i){
		ps->array[i]=ps->array[i-1];
	}
	ps->array[pos]=v;
	ps->size++;
}
