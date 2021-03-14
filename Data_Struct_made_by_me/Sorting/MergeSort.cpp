#include <stdio.h>
#include <stdlib.h>

void MergeTwoArea(int arr[],int left,int right){
	int i=0,k=0;
	int mid=(left+right)/2;
	int leftIDX=left;
	int rightIDX=mid+1;
	int * numArr=(int *)malloc(sizeof(int)*(right-left+1));//right-left=index번호이므로 +1을 해줘야함
	
	while(leftIDX<=mid && rightIDX<=right){
		if(arr[leftIDX]>arr[rightIDX]){
			numArr[i++]=arr[leftIDX++];
		}
		else{
			numArr[i++]=arr[rightIDX++];
		}
	}
	
	if(leftIDX>mid){
		while(rightIDX<=right){
			numArr[i++]=arr[rightIDX++];
		}		
	}
	else{
		while(leftIDX<=mid){//부등호가 문제였음 
			numArr[i++]=arr[leftIDX++];
		}		
	}

	for(int j=left;j<=right;j++,k++){
		arr[j]=numArr[k];
		//printf("%d ",numArr[k]);
	}
	free(numArr);
	//printf("\n");
}

void MergeSort(int arr[],int left,int right){
	int center;
	if(left<right){
		center=(left+right)/2;
		MergeSort(arr,left,center);
		MergeSort(arr,center+1,right);
		MergeTwoArea(arr,left,right);
	}

}

int main(){
	int arr[10]={3,2,10,4,1,7,6,5,23,8};
	MergeSort(arr,0,9);
	
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
}