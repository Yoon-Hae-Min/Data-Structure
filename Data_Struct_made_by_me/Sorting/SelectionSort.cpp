#include <stdio.h>

void SelectionSort(int arr[],int arrsize){
	int min,num,j;
	for(int i=0;i<arrsize;i++){
		min=i;
		for(j=i+1;j<arrsize;j++){
			if(arr[min]>arr[j])min=j;
		}
		num=arr[min];
		arr[min]=arr[i];
		arr[i]=num;
	}
}

int main(){
	int arr[5]={3,6,1,2,8};
	SelectionSort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
}
