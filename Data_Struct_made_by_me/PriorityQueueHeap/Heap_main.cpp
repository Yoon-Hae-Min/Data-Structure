#include "Heap.h"

int main(){
	
	Heap heap;
	HeapInit(&heap);
	
	HeapInsert(&heap, 3);
	
	HeapInsert(&heap, 5);
	HeapInsert(&heap, 4);
	HeapInsert(&heap, 1);
	HeapInsert(&heap, 2);
	HeapInsert(&heap, 7);
	HeapInsert(&heap, 10);
	HeapInsert(&heap, 14);
	HeapInsert(&heap, 16);
	
	ShowTree(&heap);
	printf("\n");
	HeapDelete(&heap);
	
	ShowTree(&heap);
}