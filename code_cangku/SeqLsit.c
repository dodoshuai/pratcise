#include<stdio.h>
typedef struct SeqList{
	int *array;	//指向数据存储空间
	int capacity;	//空间总容量
	int size;	//数据有效个数
}SeqList;
void PushFront(struct SeqList *s,int v){
	if(s->size>=s->capacity){
	s->capacity*=2;
	int *newArray=(int *)malloc(s->capacity*sizeof(int));
	for(int i=s->size-1;i>=0;i--){
		newArray[i+1]=s->array[i];
	}
	newArray[0]=v;
	free(s->array);
	s->array=newArray;
	s->size++;
	return;	
}
	for(int i=s->size-1;i>=0;--i){
		s->array[i+1]=s->array[i];
	}
	s->array[0]=v;
	s->size++;
}

void SeqList_init(SeqList *s,int num){
	s->array=(int *)malloc(sizeof(int)*num);
	s->capacity=num;
	s->size=0;
}
int main(void){
	SeqList new1;
	SeqList_init(&new1,10);
		new1.size=6;
	for(int i=0;i<new1.size;++i){
		new1.array[i]=i;
	}
	for(int i=0;i<new1.size;++i){
		printf("%d\n",new1.array[i]);
	}
	PushFront(&new1,7);
	printf("------`---------------------\n");
	for(int i=0;i<new1.size;++i){
		printf("%d\n",new1.array[i]);
	}
return 0;
}
