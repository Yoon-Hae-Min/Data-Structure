#include <stdio.h>


int BSearch(int arr[],int first,int last,int target){
	int mid=(double)(target-arr[first])*(last-first)/(arr[last]-arr[first])+first;
	if(last<first) return-1;
	
	if(arr[mid]==target) return mid;
	else if(target<arr[mid]) return BSearch(arr,first,mid-1,target);
	else return BSearch(arr,mid+1,last,target);
}

int main(){
	int arr[]={1,3,5,7,9};
	int idx=BSearch(arr,0,5,7);
	printf("%d ",idx+1);
}