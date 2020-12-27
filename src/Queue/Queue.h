#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct node{
	Data data;
	node *next;
}Node;

typedef struct Queue{
	Node *front;
	Node *rear;
}Queue;

void QueueInit(Queue *q);
int QueueIsEmpty(Queue *q);
void Enqueue(Queue *q, Data data);
Data Dequeue(Queue *q);
Data QueuePeek(Queue *q);
