#include <stdio.h>
#define arrsize 5
void SelectionSort(int arr[],int arrlen){
	int IDX,temp,j,i;
	for(i=0;i<arrlen;i++){
		IDX=i;
		for(j=i+1;j<arrlen;j++){
			if(arr[IDX]>arr[j]) IDX=j;
		}
		temp=arr[i];
		arr[i]=arr[IDX];
		arr[IDX]=temp;
	}
}

int main(){
	
	int arr[arrsize]={6,9,2,5,3};
	
	SelectionSort(arr,arrsize);
	for(int i=0;i<arrsize;i++){
		printf("%d ",arr[i]);
	}
}