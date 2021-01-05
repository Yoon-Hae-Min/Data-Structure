#include "ArrHeap.h"

int PriorityComp(int d1, int d2){
	return d1-d2;
}


int main(){
	Heap heap;
	HeapInit(&heap, PriorityComp);
	
	HeapInsert(&heap, 'A',1);
	HeapInsert(&heap, 'B',2);
	HeapInsert(&heap, 'C',3);
	printf("%c\n",HeapDelete(&heap));
	
	HeapInsert(&heap, 'A',1);
	HeapInsert(&heap, 'B',2);
	HeapInsert(&heap, 'C',3);
	
	printf("%c\n",HeapDelete(&heap));
	
	while(!HeapIsEmpty(&heap)){
		printf("%c\n",HeapDelete(&heap));
	}
}