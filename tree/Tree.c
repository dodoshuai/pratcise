#include<stdio.h>

Node *CreateTree(char in[],char post[],int size){
	char root Value=post[size-1];
	int leftSize=find(in,rootValue);//Tree start point
	char *leftIn=in;
	char *leftRost=post;
	char *rightIn=in+leftSize+1;
	char *rightPost=post+leftSize;
	int rightSize=size-1-leftSize;
	CreateTree(leftIn,leftPost,leftSize);
	CreateTree(rightIn,rightPost,rightSize);
	// need return tijian
}
	
