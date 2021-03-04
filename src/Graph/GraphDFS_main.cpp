#include "GraphDFS.h"

int main(){
    DFSGraph graph;
    GraphInit(&graph,7);

    AddEdge(&graph,0,1);
    AddEdge(&graph,0,3);
    AddEdge(&graph,1,2);
    AddEdge(&graph,3,2);
    AddEdge(&graph,3,4);
    AddEdge(&graph,4,5);
    AddEdge(&graph,4,6);

    ShowGraph(&graph);

    DFSGraphShow(&graph,0);printf("\n");
    DFSGraphShow(&graph,2);printf("\n");
    DFSGraphShow(&graph,4);printf("\n");
    DFSGraphShow(&graph,6);printf("\n");

    GraphDestory(&graph);
    
}