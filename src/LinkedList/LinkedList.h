#include <stdio.h>
#include <stdlib.h>

typedef int LData;
typedef struct node{
	LData data;
	node *next;
}Node;

typedef struct LinkedList{
	Node *head;
	Node *last;
	Node *before;
	int numOfData;
	int (*cmp)(LData D1,LData D2);
}LinkedList;

void ListInit(LinkedList *list);
void Linsert(LinkedList *list, LData data);
void Sinsert(LinkedList *list, LData data);
void Finsert(LinkedList *list, LData data);
Node* LMakeNode(LData data);
LData LRemove(LinkedList *list);
int  LCount(LinkedList *list);
int Lnext(LinkedList *list, LData *pdata);
void DataCmpSet(LinkedList *list, int (*cmp)(LData D1,LData D2));
