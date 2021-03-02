#include "../LinkedList/LinkedList.cpp"

enum {A,B,C,D,E,F,G,H,I,J};

typedef struct slot{
	int numOfValue;
	int numOfEdge;
	LinkedList *GraphList;
}ALGraph;

void GraphInit(ALGraph *ag, int numOfValue);
void AddEdge(ALGraph *ag, int fromA, int toB);
void ShowGraph(ALGraph *ag);
void GraphDestory(ALGraph *ag);

void GraphInit(ALGraph *ag, int numOfValue){
	ag->GraphList=(LinkedList*)malloc(sizeof(LinkedList)*numOfValue);
	ag->numOfValue=numOfValue;
	ag->numOfEdge=0;
	for(int i=0;i<numOfValue;i++){
		ListInit(&(ag->GraphList[i]));
	}
}
void AddEdge(ALGraph *ag, int fromA, int toB){
	Linsert(&(ag->GraphList[fromA]),toB);
	Linsert(&(ag->GraphList[toB]),fromA);
	ag->numOfEdge++;
}
void ShowGraph(ALGraph *ag){
	for(int i=0;i<ag->numOfValue;i++){
		printf("%d와 연결된 정점: ",i);
		LPrint(&(ag->GraphList[i]));
		printf("\n");
	}
	
}
void GraphDestory(ALGraph *ag){
	if(ag->GraphList!=NULL){
		free(ag->GraphList);
	}
}

