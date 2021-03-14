#include <stdio.h>
#include <stdlib.h>


typedef struct RNode{
	int data;
	RNode *next;
}RNode;

typedef struct RQueue{
	RNode *head;
	RNode *tail;
}RQueue;

void QueueInit(RQueue *queue){
	queue->head=NULL;
	queue->tail=NULL;
}

RNode *MakeNewNode(int data){
	RNode *newNode=(RNode*)malloc(sizeof(RNode));
	newNode->data=data;
	newNode->next=NULL;
	return newNode;
}

void Enqueue(RQueue *Rq,int data){
	RNode *newNode=MakeNewNode(data);
	if(Rq->head==NULL){
		Rq->head=newNode;
	}
	else{
		Rq->tail->next=newNode;
	}
	Rq->tail=newNode;
}

int Dequeue(RQueue *Rq){
	RNode *Pop=Rq->head;
	int returndata=Pop->data;
	Rq->head=Rq->head->next;
	free(Pop);
	return returndata;
}

int QueueIsEmpty(RQueue *Rq){
	if(Rq->head==NULL){
		return 1;
	}
	else{
		return 0;
	}
}

void RadixSort(int arr[],int arrlen, int maxNumlen){
	int div=1,k=0;
	RQueue Radix[10];
	for(int i=0;i<10;i++){
		QueueInit(&Radix[i]);
	}
	for(int i=0;i<maxNumlen;i++){
		for(int j=0;j<arrlen;j++){
			Enqueue(&Radix[(arr[j]/div)%10],arr[j]);
		}
		k=0;
		for(int j=0;j<10;j++){
			while(!QueueIsEmpty(&Radix[j])){
				arr[k++]=Dequeue(&Radix[j]);
			}
		}
		div*=10;
	}
}


int main(){
	
	int arr[5]={4,154,7,12354,23};
	RadixSort(arr,5,5);
	
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
	
}