#include <stdio.h>

void Swap(int arr[],int low, int high){
	int temp;
	temp=arr[low];
	arr[low]=arr[high];
	arr[high]=temp;
}

int Pivot(int arr[], int left, int right){
	int pivot = arr[left];
	int low= left+1;
	int high=right;
	

	while(low<=high){
		while(pivot>=arr[low]&& low<=right){
			low++;
		}
		while(pivot<=arr[high]&& high>=(left+1)){
			high--;
		}
		if(low<high){
			Swap(arr,low,high);
		}
		
	}
	Swap(arr,left,high);
	return high;
}

void QuickSort(int arr[],int left,int right){
	int pivot;
	if(left<=right){
		pivot=Pivot(arr,left,right);
		QuickSort(arr,left,pivot-1);
		QuickSort(arr,pivot+1,right);
	}

}

int main(){
	
	int arr[7]={3,2,4,1,7,6,5};
	QuickSort(arr,0,6);
	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
}