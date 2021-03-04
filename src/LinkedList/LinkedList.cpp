#include "LinkedList.h"

int Lnext(LinkedList *list, LData *pdata){
	if(list->cur==NULL){
		return 0;
	}
	else{
		*pdata=list->cur->data;
		list->cur=list->cur->next;
		return 1;
	}
	
}

void ListInit(LinkedList *list){
	list->head=NULL;
	list->last=NULL;
	list->before=NULL;
	list->cmp=NULL;
	list->numOfData=0;
	list->cur=NULL;
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
	LNode *NewNode=LMakeNode(data);
	if(list->head==NULL){
		list->head=NewNode;
		list->last=NewNode;
		list->before=list->head;
		list->cur=list->head;
	}
	else{
		list->last->next=NewNode;
		list->last=NewNode;
	}
}
void Sinsert(LinkedList *list, LData data){
	LNode *NewNode=LMakeNode(data);
	LNode *pNode=list->head;
	if(pNode==NULL){
		list->head=NewNode;
		list->cur=list->head;
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

LNode* LMakeNode(LData data){
	LNode *NewNode=(LNode*)malloc(sizeof(LNode));
	NewNode->data=data;
	NewNode->next=NULL;
	return NewNode;
}
LData LRemove(LinkedList *list){
	LNode *h=list->head;
	LNode *RNode=list->last;
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
	LNode *firstNode=list->head;
	while(firstNode->next!=NULL){
		firstNode=firstNode->next;
		cnt++;
	}
	return cnt;
}
void LPrint(LinkedList *list){
	LNode *num=list->head;
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