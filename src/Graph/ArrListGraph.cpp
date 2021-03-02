#include "ArrListGraph.h"

int main(){
	ALGraph graph;
	
	GraphInit(&graph,5);
	
	AddEdge(&graph,A,B);
	AddEdge(&graph,A,D);
	AddEdge(&graph,B,C);
	AddEdge(&graph,C,D);
	AddEdge(&graph,D,E);
	AddEdge(&graph,E,A);
	
	ShowGraph(&graph);
	GraphDestory(&graph);
}