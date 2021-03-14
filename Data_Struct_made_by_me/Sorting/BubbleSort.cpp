#include <stdio.h>
#include <stdlib.h>

void Swap(int arr[],int i,int j){
	int num=arr[i];
	arr[i]=arr[j];
	arr[j]=num;
}


void BubleSort(int arr[],int arrsize){
	for(int i=0;i<arrsize;i++){
		for(int j=0;j<arrsize-i-1;j++){
			if(arr[j]>arr[j+1]) Swap(arr,j,j+1);
		}
	}
}

int main(){
	int arr[6]={45,7,2,3,8,1};
	BubleSort(arr,sizeof(arr)/sizeof(int));
	for(int i=0;i<6;i++){
		printf("%d ",arr[i]);
	}
}