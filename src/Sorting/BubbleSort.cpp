#include <stdio.h>

void BubleSort(int arr[],int arrlen){
	int temp;
	for(int i=0;i<arrlen;i++){
		for(int j=0;j<(arrlen-i);j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(){
	int arr[4]={2,4,6,3};
	BubleSort(arr,4);
	for(int i=0;i<4;i++){
		printf("%d ",arr[i]);
	}
	
}