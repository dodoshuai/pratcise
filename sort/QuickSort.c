#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
void Swap(datatype array[],int x,int y){
	int t=array[x];
	array[x]=array[y];
	array[y]=t;
}

int Partition_3(datatype array[],int left,int right){// xiabiao
	int d=left;
	for(int i=left;i<right;++i){
		if(array[i]<=array[right]){
		Swap(array,i,d);
		d++;
		}
	}
}
int Partition_2(datatype array[],int left,int right){// wakeng fa
	int begin=left;
	int end=right;
	int pivot=array[right];
	while(begin<end){
		while(begin<end&&array[begin]<=pivot){
			begin++;
		}
		array[end]=	array[begin];
		while(begin<end&&array[end]>=pivot){
		end--;
		}
		array[begin]=array[end];
	}
	array[begin]=pivot;
	return begin;
}
int Partition_1(datatype array[],int left,int right){//hoare fa
	int begin=left;
	int end=right;
	int pivit=array[right];
	while(begin<end){
		while(begin<end&&array[begin]<=pivot){
			begin++;
		}
		while(begin<end&&array[end]>=pivot){
		end--;
		}
		Swap(array,begin,right);
	}
	Swap(array,begin,right);
	return begin;
}

void QuickSort(datatype array[],int left,int right){
	if(left==right||left>right){
		return ;
	}
	int d=Partition(array[],left,right);
	QuickSort(array,left,d-1);
	QuickSort(array,d+1,right);
}
