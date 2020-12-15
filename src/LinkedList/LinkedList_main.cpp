#include "LinkedList.cpp"
int WhatIsPre(int data1,int data2){
	if(data1<data2){
		return 0;
	}
	else{
		return 1;
	}
}
int main(){
	LinkedList list;
	int data;
	ListInit(&list);
	DataCmpSet(&list,WhatIsPre);
	Linsert(&list, 11);
	Linsert(&list, 22);
	Linsert(&list, 44);
	Linsert(&list, 33);
	Linsert(&list, 55);
	
	LPrint(&list);
	
	printf("\n%d가 삭제되었습니다 남은 데이터는 %d개 입니다\n",LRemove(&list),LCount(&list));
	LPrint(&list);
	printf("\n%d가 삭제되었습니다 남은 데이터는 %d개 입니다\n",LRemove(&list),LCount(&list));
	LPrint(&list);
	printf("\n%d가 삭제되었습니다 남은 데이터는 %d개 입니다\n",LRemove(&list),LCount(&list));
	LPrint(&list);

	
}