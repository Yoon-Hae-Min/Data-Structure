#include "Deque.cpp"

int main(){
	Deque dq;
	
	DQInit(&dq);
	
	DQAddFirst(&dq,3);
	DQAddFirst(&dq,2);
	DQAddFirst(&dq,1);
	DQAddFirst(&dq,4);
	
	DQAddLast(&dq,5);
	DQAddLast(&dq,6);
	DQAddLast(&dq,7);
	
	while(!DQIsEmpty(&dq)){
		printf("%d ",DQRemoveFirst(&dq));
	}
	printf("\n\n\n\n");
	DQAddFirst(&dq,3);
	DQAddFirst(&dq,2);
	DQAddFirst(&dq,1);
	DQAddFirst(&dq,4);
	DQAddLast(&dq,5);
	DQAddLast(&dq,6);
	DQAddLast(&dq,7);
	
	while(!DQIsEmpty(&dq)){
		printf("%d ",DQRemoveLast(&dq));
	}
	
}