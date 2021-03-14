#include <stdio.h>
#include <stdlib.h>
typedef int HData;

typedef struct Heap{
	HData *arr;
	int currentDataNum;
}Heap;

void HeapSwap(Heap *heap, int p,int c){
	HData num;
	num=heap->arr[p];
	heap->arr[p]=heap->arr[c];
	heap->arr[c]=num;
}

int GetLeftSubNode(int h){
	return h*2;
}
int GetRightSubNode(int h){
	return h*2+1;
}
int GetParentNode(int h){
	return h/2;
}


void HeapInit(Heap *heap,int arrlen){
	heap->currentDataNum=0;
	heap->arr=(HData*)malloc(sizeof(HData)*arrlen+1);
}

void HeapInsert(Heap *heap,HData data){
	heap->currentDataNum+=1;
	int newDataNum=heap->currentDataNum;
	int parent=GetParentNode(newDataNum);
	int child=newDataNum;
	
	heap->arr[newDataNum]=data;
	while(parent>0){
		if(heap->arr[parent]<heap->arr[child]){
			HeapSwap(heap,parent,child);
			child=parent;
			parent=GetParentNode(child);
		}
		else break;
	}
}

HData HeapDelete(Heap *heap){
	int Data=heap->arr[1];
	int parent=1;
	int child=2;
	heap->arr[1]=heap->arr[heap->currentDataNum];
	heap->currentDataNum-=1;
	
	while(1){
		if(heap->arr[GetLeftSubNode(parent)]<heap->arr[GetRightSubNode(parent)] && GetRightSubNode(parent)<=heap->currentDataNum){// 현제 지정된 길이보다 자식의 노드가 크면안됨
			child=GetRightSubNode(parent);
		}
		else{
			child=GetLeftSubNode(parent);
		}
		if(heap->arr[parent]<heap->arr[child] && child<=heap->currentDataNum){// 값으로 지정된 위치가 현제 트리를 구성하는것에 벗어나면 안됨
			HeapSwap(heap,parent,child);
			parent=child;
		}
		else{
			break;
		}
	}

	return Data;
}

void HeapSort(Heap *heap,HData arr[],int arrlen){
	for(int i=0;i<arrlen;i++){
		HeapInsert(heap,arr[i]);
	}
}

void HeapPrint(Heap *heap){
	printf("%d ",HeapDelete(heap));
}

int main(){
	Heap h;
	HData arr[20]={3,1,6,4,9,8,1,12,5,3,24,15,2,6,14,19,8,0,4,7};
	HeapInit(&h,20);
	HeapSort(&h,arr,20);
	//for(int i=1;i<=5;i++){
	//	printf("%d ",h.arr[i]);
	//}
	printf("\n");
	for(int i=1;i<=20;i++){
		HeapPrint(&h);
	}
}