#include <stdio.h>
#include <stdlib.h>
//다시해보기
void MergeTwoArea(int arr[],int left,int mid,int right){
	int leftIDX=left;
	int rightIDX=mid+1;
	
	int sIDX=left;
	int * sortedArr=(int *)malloc(sizeof(int)*(right+1));
	
	while(leftIDX<=mid&&rightIDX<=right){
		if(arr[leftIDX]<=arr[rightIDX])sortedArr[sIDX]=arr[leftIDX++];
		else sortedArr[sIDX]=arr[rightIDX++];
		sIDX++;
	}
	if(leftIDX>mid){
		for(int i=rightIDX;i<right;i++,sIDX++){
			sortedArr[sIDX]=arr[i];
		}
	}
	else{
		for(int i=leftIDX;i<=mid;i++,sIDX++){
			sortedArr[sIDX]=arr[i];
		}
	}
	for(int i=left;i<=right;i++){
		arr[i]=sortedArr[i];
	}
	free(sortedArr);
}

void MergeSort(int arr[], int left,int right){
	int mid;
	if(left<right){
		mid=(left+right)/2;
		MergeSort(arr,left,mid);
		MergeSort(arr,mid+1,right);
		MergeTwoArea(arr,left,mid,right);
	}

}

int main(){
	int arr[7]={3,2,4,1,7,6,5};
	
	MergeSort(arr,0,6);
	
	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
}