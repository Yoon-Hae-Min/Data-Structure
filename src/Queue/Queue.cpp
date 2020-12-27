#include "Queue.h"
void QueueInit(Queue *q){
	q->front=NULL;
	q->rear=NULL;
}
int QueueIsEmpty(Queue *q){
	if(q->front==NULL) return 1;
	else return 0;
}
void Enqueue(Queue *q, Data data){
	Node *newnode =(Node *)malloc(sizeof(Node));
	newnode->data=data;
	newnode->next=NULL;
	if(QueueIsEmpty(q)){
		q->front=newnode;
		q->rear=newnode;
	}
	else{
		q->rear->next=newnode;
		q->rear=newnode;
	}
}
Data Dequeue(Queue *q){
	Node *dnode;
	Data returnData;
	if(QueueIsEmpty(q)){
		printf("QueueIsEmpty");
		exit(-1);
	}
	else{
		dnode=q->front;
		returnData=dnode->data;
		q->front=q->front->next;
		free(dnode);
		return returnData;
	}
}
Data QueuePeek(Queue *q){
	if(QueueIsEmpty(q)){
		printf("QueueIsEmpty");
		exit(-1);
	}
	else{
		return q->front->data;
	}
}