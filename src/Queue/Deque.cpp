#include "Deque.h"

void DQInit(Deque *dq){
	dq->front=NULL;
	dq->rear=NULL;
}
int DQIsEmpty(Deque *dq){
	if(dq->front==NULL) return 1;
	else return 0;
}
void DQAddFirst(Deque *dq, Data data){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->before=NULL;
	newNode->next=NULL;
	
	if(DQIsEmpty(dq)){
		dq->rear=newNode;
	}
	else{
		dq->front->before=newNode;
		newNode->next=dq->front;
	}
	dq->front=newNode;
}
void DQAddLast(Deque *dq,Data data){
	Node *newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->before=NULL;
	newNode->next=NULL;
	
	if(DQIsEmpty(dq)){
		dq->front=newNode;
	}
	else{
		newNode->before=dq->rear;
		dq->rear->next=newNode;
	}
	dq->rear=newNode;
}
Data DQRemoveFirst(Deque *dq){
	Node *fNode=dq->front;
	Data fNodeData;
	if(DQIsEmpty(dq)){
		printf("Memory Error");
		exit(-1);
	}
	fNodeData=fNode->data;
	dq->front=dq->front->next;
	
	if(dq->front==NULL){
		dq->rear=NULL;
	}
	else{
		dq->front->before=NULL;
	}

	
	free(fNode);
	
	return fNodeData;
	
	
}
Data DQRemoveLast(Deque *dq){
	Node *lNode=dq->rear;
	Data lNodeData;
	if(DQIsEmpty(dq)){
		printf("Memory Error");
		exit(-1);
	}
	lNodeData=lNode->data;
	dq->rear=dq->rear->before;
	
	if(dq->rear==NULL){
		dq->front=NULL;
	}
	else{
		dq->rear->next=NULL;	
	}
	
	free(lNode);
	
	return lNodeData;
}

Data DQPeekFirst(Deque *dq){
	if(DQIsEmpty(dq)){
		printf("Memory Error");
		exit(-1);
	}
	return dq->front->data;
}

Data DQPeekrear(Deque *dq){
	if(DQIsEmpty(dq)){
		printf("Memory Error");
		exit(-1);
	}
	return dq->rear->data;
}