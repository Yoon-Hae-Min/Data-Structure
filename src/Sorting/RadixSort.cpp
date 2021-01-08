#include "../Queue/Queue.cpp"

void RadixSort(int arr[],int maxNumLen,int arrLen){
	Queue bucket[10];
	int div=1;
	int di=0;
	for(int i=0;i<10;i++){
		QueueInit(&bucket[i]);
	}
	
	for(int digitlen=0;digitlen<maxNumLen;digitlen++){
		for(int i=0;i<arrLen;i++){
			Enqueue(&bucket[(arr[i]/div)%10],arr[i]);
		}
		di=0;
		for(int j=0;j<10;j++)
			while(!QueueIsEmpty(&bucket[j])){
				arr[di++]=Dequeue(&bucket[j]);
			}
		}
		div*=10;
	}
}




int main(){
	int arr[7]={13,212,14,7141,10987,6,15};
	RadixSort(arr,5,7);
	for(int i=0;i<7;i++){
		printf("%d ",arr[i]);
	}
}