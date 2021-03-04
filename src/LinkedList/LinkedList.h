#include <stdio.h>
#include <stdlib.h>

typedef int LData;
typedef struct lnode{
	LData data;
	lnode *next;
}LNode;

typedef struct LinkedList{
	LNode *head;
	LNode *last;
	LNode *before;
	LNode *cur;
	int numOfData;
	int (*cmp)(LData D1,LData D2);
}LinkedList;

void ListInit(LinkedList *list);
void Linsert(LinkedList *list, LData data);
void Sinsert(LinkedList *list, LData data);
void Finsert(LinkedList *list, LData data);
LNode* LMakeNode(LData data);
LData LRemove(LinkedList *list);
int  LCount(LinkedList *list);
int Lnext(LinkedList *list, LData *pdata);
void DataCmpSet(LinkedList *list, int (*cmp)(LData D1,LData D2));
