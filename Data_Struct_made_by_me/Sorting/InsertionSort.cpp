#include <stdio.h>



void InsertionSort(int arr[],int arrsize){
	int select,j;
	for(int i=0;i<arrsize;i++){
		select=arr[i];
		for(j=i-1;j>=0;j--){
			if(select>arr[j]){
				arr[j+1]=arr[j];
			}
			else break;
		}
		arr[j+1]=select;//for문이 한칸더 내려감
	}
}

int main(){
	int arr[5]={5,3,7,2,1};
	
	InsertionSort(arr,5);
	
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
}