#include <stdio.h>
#include <stdlib.h>
#define MAX_LEN 100
//index 1부터 시작
typedef int HData;

typedef struct HEAP{
	HData heaparr[MAX_LEN+1];
	int dataNum;
}Heap;

void HeapInit(Heap *heap){
	heap->dataNum=0;
}

int GetLeftSubTree(int parent){
	return parent*2;
}
int GetRightSubTree(int parent){
	return parent*2+1;
}

int GetParentTree(int child){
	return child/2;
}
void ShowTree(Heap *heap){
	for(int i=1;i<heap->dataNum+1;i++){
		printf("%d ",heap->heaparr[i]);
	}
}

void Swap(Heap *heap,int parent,int child){
	HData num;
	num=heap->heaparr[child];
	heap->heaparr[child]=heap->heaparr[parent];
	heap->heaparr[parent]=num;
}

void HeapInsert(Heap *heap, HData data){//고치기
	int parent,child;
	heap->dataNum+=1;
	
	parent=GetParentTree(heap->dataNum);
	child=heap->dataNum;
	heap->heaparr[child]=data;
	while(child!=1 && heap->heaparr[child] > heap->heaparr[parent]){// 덮어쓰면 덮어쓰는 대상이랑 비교하는게 아닌 data값을 비교해야했었음 SWAP함수 만들어서 하는게 보기편할듯
		Swap(heap,parent,child);
		child=parent;
		parent=GetParentTree(child);
	}
}

void HeapDelete(Heap *heap){
	int parent,child;
	heap->heaparr[1]=heap->heaparr[heap->dataNum];
	heap->dataNum-=1;
	parent=1;
	child=2;
	
	while(child<heap->dataNum){//고치기
		if(heap->heaparr[GetLeftSubTree(parent)] < heap->heaparr[GetRightSubTree(parent)]){//더 큰 child가져오기
			child=GetRightSubTree(parent);
		}
		else{
			child=GetLeftSubTree(parent);
		}
		
		if(heap->heaparr[child]>heap->heaparr[parent] && child<heap->dataNum){//비교후 child값이 크면 swap
			Swap(heap,parent,child);
			parent=child;
		}
		else{//완료된 상태
			break;
		}
		
	}
}