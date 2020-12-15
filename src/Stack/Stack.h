#include <stdio.h>
#include <stdlib.h>
typedef int Data;

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