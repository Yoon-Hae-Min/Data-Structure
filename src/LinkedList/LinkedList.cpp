#include "LinkedList.h"

void ListInit(LinkedList *list){
	list->head=NULL;
	list->last=NULL;
	list->before=NULL;
	list->cmp=NULL;
	list->numOfData=0;
}

void Linsert(LinkedList *list, LData data){
	if(list->cmp==NULL){
		Finsert(list, data);
	}
	else{
		Sinsert(list, data);
	}
}
void Finsert(LinkedList *list, LData data){
	Node *NewNode=LMakeNode(data);
	if(list->head==NULL){
		list->head=NewNode;
		list->last=NewNode;
		list->before=list->head;
	}
	else{
		list->last->next=NewNode;
		list->last=NewNode;
	}
}
void Sinsert(LinkedList *list, LData data){
	Node *NewNode=LMakeNode(data);
	Node *pNode=list->head;
	if(pNode==NULL){
		list->head=NewNode;
	}
	else{
		while(pNode->next!=NULL && list->cmp(data,pNode->next->data)){
			pNode=pNode->next;
		}
		if(pNode->next==NULL){
			list->last=NewNode;
		}
		NewNode->next=pNode->next;
		pNode->next=NewNode;
	}
}

Node* LMakeNode(LData data){
	Node *NewNode=(Node*)malloc(sizeof(Node));
	NewNode->data=data;
	NewNode->next=NULL;
	return NewNode;
}
LData LRemove(LinkedList *list){
	Node *h=list->head;
	Node *RNode=list->last;
	LData RData=RNode->data;
	
	while(h->next->next!=NULL){
		h=h->next;
	}
	h->next=NULL;//데이터 free후 빈자리가 NULL값이 아님
	list->last=h;
	
	free(RNode);
	RNode=NULL;
	return RData;
}

int  LCount(LinkedList *list){
	int cnt=0;
	Node *firstNode=list->head;
	while(firstNode->next!=NULL){
		firstNode=firstNode->next;
		cnt++;
	}
	return cnt;
}
void LPrint(LinkedList *list){
	Node *num=list->head;
	while(num!=NULL){
		if(num->next==NULL){
			printf("%d",num->data);
		}
		else{
			printf("%d-> ",num->data);	
		}
		num=num->next;
	}
}
void DataCmpSet(LinkedList *list, int (*cmp)(LData D1,LData D2)){
	list->cmp=cmp;
}