#include <stdio.h>
#include <stdlib.h>

#define HEAP_LEN 10
typedef char heapData;
typedef int (*PriorityCmp)(int p1, int p2);

typedef struct Heap_Element{
	int priority;
	heapData data;
}HeapElement;

typedef struct Heap{
	HeapElement heapArr[HEAP_LEN+1];
	int numOfData;
	PriorityCmp comp;
}Heap;

void HeapInit(Heap *h, PriorityCmp pcmp);
int HeapIsEmpty(Heap *h);
void HeapInsert(Heap *h, heapData data, int priority);
heapData HeapDelete(Heap *h);

int GetLeftChildIDX(int idx);
int GetRightChildIDX(int idx);
int GetParentIDX(int idx);

int GetHighPriorityChildIDX(Heap *h, int idx);


void HeapInit(Heap *h,PriorityCmp pc){
	h->numOfData=0;
	h->comp=pc;
}
int HeapIsEmpty(Heap *h){
	if(h->numOfData==0)return 1;
	else return 0;
}
void HeapInsert(Heap *h, heapData data, int priority){
	int lastIDX= h->numOfData+1;
	HeapElement newHeap={priority, data};
	while(lastIDX!=1){
		if(h->comp(priority, h->heapArr[GetParentIDX(lastIDX)].priority)<0){
			h->heapArr[lastIDX]=h->heapArr[GetParentIDX(lastIDX)];
			lastIDX=GetParentIDX(lastIDX);
		}
		else{
			break;
		}
	}
	h->heapArr[lastIDX]=newHeap;
	h->numOfData+=1;
}

heapData HeapDelete(Heap *h){
	heapData DeleteData=h->heapArr[1].data;
	int parentIdx=1;
	int childIdx;
	HeapElement lastElement=h->heapArr[h->numOfData];
	h->heapArr[parentIdx]=h->heapArr[h->numOfData];
	
	while(childIdx=GetHighPriorityChildIDX(h,parentIdx)){
		if(h->comp(lastElement.priority,h->heapArr[childIdx].priority)<0)break;
			h->heapArr[parentIdx]=h->heapArr[childIdx];
			parentIdx=childIdx;
	}
	h->heapArr[parentIdx]=lastElement;
	h->numOfData-=1;
	return DeleteData;

	
}

int GetParentIDX(int childIdx){
	return childIdx/2;
}

int GetLeftChildIDX(int parentIdx){
	return parentIdx*2;
}
int GetRightChildIDX(int parentIdx){
	return parentIdx*2+1;
}

int GetHighPriorityChildIDX(Heap *h, int idx){
	if(GetLeftChildIDX(idx)>h->numOfData) return 0;
	else if(GetLeftChildIDX(idx)==h->numOfData) return GetLeftChildIDX(idx);
	else{
		if(h->comp(h->heapArr[GetLeftChildIDX(idx)].priority, h->heapArr[GetRightChildIDX(idx)].priority)>0) return GetRightChildIDX(idx);
		else return GetLeftChildIDX(idx);
	}
}
