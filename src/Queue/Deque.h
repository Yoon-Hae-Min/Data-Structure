#include <stdio.h>
#include <stdlib.h>

typedef int Data;

typedef struct node{
	Data data;
	node *before;
	node *next;
}Node;

typedef struct Deque{
	Node *front;
	Node *rear;
}Deque;

void DQInit(Deque *dq);
int DQIsEmpty(Deque *dq);
void DQAddFirst(Deque *dq, Data data);
void DQAddLast(Deque *dq,Data data);
Data DQRemoveFirst(Deque *dq);
Data DQRemoveLast(Deque *dq);
Data DQPeekFirst(Deque *dq);
Data DQPeekLast(Deque *dq);
