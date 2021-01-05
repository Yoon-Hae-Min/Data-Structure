#include <stdio.h>

void InsertionSort(int arr[],int arrlen){
	int selectedData,j;
	for(int i=1;i<arrlen;i++){
		selectedData=arr[i];
		for(j=i-1;j>=0;j--){
			if(selectedData<arr[j])arr[j+1]=arr[j];
			else break;
		}
		arr[j+1]=selectedData;
		
	}
	
}

int main(){
	int arr[5]={5,3,4,6,2};
	
	InsertionSort(arr,5);
	for(int i=0;i<5;i++){
		printf("%d ",arr[i]);
	}
}