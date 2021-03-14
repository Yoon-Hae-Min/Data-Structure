#include <stdio.h>

void Swap(int arr[],int l,int r){
	int num=arr[l];
	arr[l]=arr[r];
	arr[r]=num;
}

void QuickSort(int arr[],int left,int right){
	int pivot=arr[left];
	int leftIDX=left+1;
	int rightIDX=right;
	if(left>=right) return;
	else{
		while(leftIDX<=rightIDX){
			while(pivot<arr[leftIDX] && leftIDX<=right)leftIDX++;
			while(pivot>=arr[rightIDX] && rightIDX>left)rightIDX--;
			if(leftIDX<=rightIDX) Swap(arr,leftIDX,rightIDX);
		}
		Swap(arr,left,rightIDX);

		QuickSort(arr,left,rightIDX-1);
		QuickSort(arr,rightIDX+1,right);
	}
}

int main(){
	int arr[7]={3,2,4,1,7,6,5};
	QuickSort(arr,0,6);
	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
}