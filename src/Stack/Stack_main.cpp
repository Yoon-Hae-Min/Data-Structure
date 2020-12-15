#include "Stack.cpp"

int main(){
	Stack stack;
	StackInit(&stack);
	
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	StackPush(&stack, 6);
	
	while(!StackEmpty(&stack)){
		printf("%d 가 pop되었습니다.\n", StackPop(&stack));
	}
	
}