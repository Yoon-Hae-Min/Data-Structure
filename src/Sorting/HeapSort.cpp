#include "../Tree/Heap/ArrHeap.h"

int PriComp(int n1,int n2){
	return n1-n2;//오름차순
}

void HeapSort(HeapElement arr[],int n, PriorityCmp pc){
	Heap heap;
	HeapInit(&heap, PriComp);
	
	for(int i=0;i<n;i++){
		HeapInsert(&heap,arr[i].data,arr[i].priority);
	}
	for(int i=0;i<n;i++){
		arr[i].data=HeapDelete(&heap);
	}
	
}

int main(){
	HeapElement arr[4]={{1,5},{2,3},{5,2},{7,6}};
	
	HeapSort(arr,4,PriComp);
	
	for(int i=0;i<4;i++){
		printf("%d ",arr[i].data);
	}
}