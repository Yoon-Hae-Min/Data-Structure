#include <string.h>
#include "../LinkedList/LinkedList.cpp"
#include "../Stack/Stack.h"

typedef struct slot{
	int numOfValue;
	int numOfEdge;
	LinkedList *GraphList;
    int *visitInfo;
} DFSGraph;

void GraphInit(DFSGraph *ag, int numOfValue){
	ag->GraphList=(LinkedList*)malloc(sizeof(LinkedList)*numOfValue);
	ag->numOfValue=numOfValue;
	ag->numOfEdge=0;
	for(int i=0;i<numOfValue;i++){
		ListInit(&(ag->GraphList[i]));
	}

    ag->visitInfo=(int*)malloc(sizeof(int)*numOfValue);
    memset(ag->visitInfo,0,sizeof(int)*numOfValue);

}
void AddEdge(DFSGraph *ag, int fromA, int toB){
	Linsert(&(ag->GraphList[fromA]),toB);
	Linsert(&(ag->GraphList[toB]),fromA);
	ag->numOfEdge++;
}
void ShowGraph(DFSGraph *ag){
	for(int i=0;i<ag->numOfValue;i++){
		printf("%d와 연결된 정점: ",i);
		LPrint(&(ag->GraphList[i]));
		printf("\n");
	}
	
}
void GraphDestory(DFSGraph *ag){
	if(ag->GraphList!=NULL)free(ag->GraphList);
    if(ag->visitInfo != NULL) free(ag->visitInfo);
}

int VisitNode(DFSGraph *ag,int visitTarget){
	if(ag->visitInfo[visitTarget]==0){
		ag->visitInfo[visitTarget]=1;
		printf("%d를 방문했습니다  ",visitTarget);
		return 1;
	}
	else return 0;
}

void DFSGraphShow(DFSGraph *ag, int start){
	Stack stack;
	int visit=start;
	int nextvisit;
	int Flag=0;
	StackInit(&stack);
	VisitNode(ag,visit);
	StackPush(&stack, visit);
	while(1){
		Flag=0;
		if(Lnext(&(ag->GraphList[visit]),&nextvisit)){
			if(VisitNode(ag,nextvisit)){
				StackPush(&stack,visit);
				visit=nextvisit;
				Flag=1;
			}
			else{
				while(Lnext(&(ag->GraphList[visit]),&nextvisit)){
					if(VisitNode(ag,nextvisit)){
						StackPush(&stack,visit);
						visit=nextvisit;
						Flag=1;
						break;//이유
					}
				}
			}
		}
		if(Flag==0){
			if(StackEmpty(&stack)) break;
			else visit=StackPop(&stack);
		}
	}

	memset(ag->visitInfo,0,sizeof(int)*ag->numOfValue);
	for(int i=0;i<(ag->numOfValue);i++){
		ag->GraphList[i].cur=ag->GraphList[i].head;
	}
}
