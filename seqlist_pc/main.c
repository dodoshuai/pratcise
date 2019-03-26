#include<stdio.h>
#include"SeqList.h"
int main(void){
	SeqList qe;
	SeqListInit(&qe,10);
	SeqListPushFront(&qe,1);
	SeqListPushBack(&qe,2);
	
	SeqListPushBack(&qe,3);
	
	SeqListPushBack(&qe,5);
	SeqListInsert(&qe,3,4);
	for(int i=0;i<qe.size;i++){
		printf("%d\n",qe.array[i]);
	}
	SeqListPopFront(&qe);
	SeqListPopBack(&qe);	
	for(int i=0;i<qe.size;i++){
		printf("%d\n",qe.array[i]);
	}
return 0;
}
