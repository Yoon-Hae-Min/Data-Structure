#include <stdio.h>
#include <stdlib.h>
#define BUCKET_NUM 10


//visual code로 제출해 볼것
typedef struct node{
	int data;
	node * next=NULL;
}node;

typedef struct Que{
	node *last;
	node *head;
}Q;

void QueSetting(Q *q){
	q->head=NULL;
	q->last=NULL;
}

int QisEmpty(Q *q){
	if(q->head==NULL)return 1;
	else return 0;
}
void Enqueue(Q *q,int data){
	node * newNode=(node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->next=NULL;
	if(QisEmpty(q)){
		q->head=newNode;
		q->last=newNode;
	}
	else{
		q->last->next=newNode;
		q->last=newNode;
	}
	printf("%d ",q->last->data);
}
int Dequeue(Q *q){
	int rdata;
	node * outputnode=q->head;
	rdata=outputnode->data;
	q->head=outputnode->next;
	
	free(outputnode);
	return rdata;
}

void RadixSort(int arr[], int num, int maxLen){
	Q bucket[BUCKET_NUM];
	int divnum=1;
	int radix;
	int l=0;
	for(int i=0;i<BUCKET_NUM;i++){
		QueSetting(&bucket[i]);
	}
	for(int i=0;i<maxLen;i++){
		for(int j=0;j<num;j++){
			radix=(arr[i]/divnum)%10;
			Enqueue(&bucket[radix],arr[i]);
		}
		for(int k=0;k<BUCKET_NUM;k++){
			while(!QisEmpty(&bucket[k])){
				arr[l]=Dequeue(&bucket[k]);
				l++;
			}
		}
		divnum*=10;
	}
}

int main(){
	int arr[7]={13,212,14,7141,10987,6,15};
	int len=sizeof(arr)/sizeof(int);
	
	RadixSort(arr,len,5);
	for(int i=0;i<len;i++){
		printf("%d ",arr[i]);
	}
	
}