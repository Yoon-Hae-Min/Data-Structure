#include "../Tree/Tree.h"
#include "AVLRebalance.h"
typedef BTData BTSData;

void BinarySearchTreeMake(treeNode *rtree);

treeNode *BinarySearchTreeInsert(treeNode *rtree,BTSData data);

treeNode *BinarySearchTreeSearch(treeNode *rtree,BTSData target);

void BinarySearchTreeRemove(treeNode **rtree, BTSData target);

void BinarySearchTreeMake(treeNode **rtree){
	*rtree=NULL;
}

treeNode *BinarySearchTreeInsert(treeNode **rtree,BTSData data){
	if(*rtree==NULL){
		*rtree=MakeNode(data);
	}
	else if(data<(*rtree)->data){
		BinarySearchTreeInsert(&((*rtree)->left),data);
		*rtree=Rebalance(rtree);
	}
	else if(data>(*rtree)->data){
		BinarySearchTreeInsert(&((*rtree)->right),data);
		*rtree=Rebalance(rtree);
	}
	else{
		return NULL;
	}
	return *rtree;
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

void BinarySearchTreeRemove(treeNode **rtree, BTSData target){
	treeNode *temporaryHead=MakeNode(0);//가상의 헤드
	treeNode *parentNode=temporaryHead;
	treeNode *currentNode=*rtree;
	temporaryHead->right=currentNode;
	treeNode *deleteNode;

	printf("완료");
	while(currentNode!=NULL && currentNode->data!=target){
		parentNode=currentNode;
		if(target<currentNode->data)currentNode=GetLeftSubNode(currentNode);
		else currentNode=GetRightSubNode(currentNode);
	}
	deleteNode=currentNode;
	printf("완료");
	if(GetRightSubNode(deleteNode)==NULL && GetLeftSubNode(deleteNode)==NULL){//자식노드가 단말일때		
		printf("완료");
		if(GetRightSubNode(parentNode)==currentNode) RemoveRightSubTree(parentNode);
		else RemoveLeftSubTree(parentNode);
	}
	else if(GetRightSubNode(deleteNode)==NULL || GetLeftSubNode(deleteNode)==NULL){// 하나의 자식을 가질때
		treeNode *deleteChildNode;
		if(GetLeftSubNode(deleteNode)!=NULL){
			deleteChildNode=GetLeftSubNode(deleteNode);
		}
		else{
			deleteChildNode=GetRightSubNode(deleteNode);
		}
		if(GetLeftSubNode(parentNode)==deleteNode){
			parentNode->left=deleteChildNode;
		}
		else{
			parentNode->right=deleteChildNode;
		}
	}
	else{//두개의 자식을 가질때(6을 제거할때 에러)
		treeNode *temporaryNode=GetRightSubNode(deleteNode);
		treeNode *temporaryParentNode=deleteNode;
		BTSData backupData;
		while(GetLeftSubNode(temporaryNode)!=NULL){
			temporaryParentNode=temporaryNode;
			temporaryNode=GetLeftSubNode(temporaryNode);
		}
		backupData=temporaryNode->data;
		deleteNode->data=backupData;
		if(GetLeftSubNode(temporaryParentNode)==temporaryNode){
			temporaryParentNode->left=temporaryNode->right;
		}
		else{
			temporaryParentNode->right=temporaryNode->right;
		}
		
		
	}
	if(GetRightSubNode(temporaryHead)!=*rtree){
		*rtree=GetRightSubNode(temporaryHead);
	}
	Rebalance(rtree);
	free(temporaryHead);
}