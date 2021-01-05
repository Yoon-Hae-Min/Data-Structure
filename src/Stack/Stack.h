#include <stdio.h>
#include <stdlib.h>
typedef treeNode* Data;
typedef struct node{
	Data data;
	node *next;
}Node;

typedef struct Stack{
	Node*head;
}LStack;


void StackInit(LStack *stack);
int StackEmpty(LStack *stack);
Data StackPop(LStack *stack);
Data StackPeek(LStack *stack);
void StackPush(LStack *stack, Data data);


void StackInit(LStack *stack){
	stack->head=NULL;
}

int StackEmpty(LStack *stack){
	if(stack->head==NULL) return 1;
	else return 0;
}

Data StackPop(LStack *stack){
	Node *pstack;
	Data sdata;
	if(StackEmpty(stack)){
		printf("Stack Memory Error");	
		exit(-1);
	}
	else{
		pstack=stack->head;
		sdata=pstack->data;
		stack->head=stack->head->next;
		free(pstack);
		return sdata;
	}
}
Data StackPeek(LStack *stack){
	if(StackEmpty(stack)){
		//printf("Stack Memory Error");	
		exit(-1);
	}
	return stack->head->data;
	
}
void StackPush(LStack *stack, Data data){
	Node *NewNode=(node*)malloc(sizeof(node));
	NewNode->data=data;
	NewNode->next=stack->head;
	stack->head=NewNode;
}