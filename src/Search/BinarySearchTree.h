#include "../Tree/Tree.h"

typedef BTData BTSData;

void BinarySearchTreeMake(treeNode *rtree);

void BinarySearchTreeInsert(treeNode *rtree,BTSData data);

treeNode *BinarySearchTreeSearch(treeNode *rtree,BTSData target);

void BinarySearchTreeMake(treeNode **rtree){
	*rtree=NULL;
}

void BinarySearchTreeInsert(treeNode **rtree,BTSData data){
	treeNode *newNode=MakeNode(data);
	treeNode *currentNode=*rtree;
	treeNode *parentNode=NULL;
	
	while(currentNode!=NULL){
		parentNode=currentNode;
		if(data<currentNode->data){
			currentNode=GetLeftSubNode(currentNode);
		}
		else{
			currentNode=GetRightSubNode(currentNode);
		}
	}
	
	if(parentNode!=NULL){
		if(data<parentNode->data){
			ConnectLeftNode(parentNode,newNode);
		}
		else{
			ConnectRightNode(parentNode,newNode);
		}
	}
	else{
		*rtree=newNode;
	}
}

treeNode *BinarySearchTreeSearch(treeNode **rtree,BTSData target){
	treeNode *currentNode=*rtree;
	while(currentNode!=NULL){
		if(target==GetBTData(currentNode)){
			return currentNode;
		}
		else if(target<GetBTData(currentNode)){
			currentNode=GetLeftSubNode(currentNode);
		}
		else{
			currentNode=GetRightSubNode(currentNode);
		}
	}
	return NULL;
}