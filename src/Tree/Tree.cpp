#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

treeNode *MakeNode(BTData data){
	treeNode * newNode=(treeNode *)malloc(sizeof(treeNode));
	newNode->data=data;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
}
BTData GetBTData(treeNode *tree){
	return tree->data;
}
treeNode *GetLeftSubNode(treeNode *tree){
	return tree->left;
}
treeNode *GetRightSubNode(treeNode *tree){
	return tree->right;
}
void ConnectLeftNode(treeNode *tree, treeNode *sub){
	if(GetLeftSubNode(tree)!=NULL) free(tree->left);
	tree->left=sub;
}
void ConnectRightNode(treeNode *tree, treeNode *sub){
	if(GetRightSubNode(tree)!=NULL) free(tree->right);
	tree->right=sub;
}

void PreorderTraversal(treeNode *tree, VisitFuncPtr action){
	if(tree==NULL){
		return;
	}
	action(tree->data);
	PreorderTraversal(tree->left,action);
	PreorderTraversal(tree->right,action);
}

void InorderTraversal(treeNode *tree, VisitFuncPtr action){
	if(tree==NULL){
		return;
	}
	InorderTraversal(tree->left,action);
	action(tree->data);
	InorderTraversal(tree->right,action);
	
}
void PostorderTraversal(treeNode *tree, VisitFuncPtr action){
	if(tree==NULL){
		return;
	}
	PostorderTraversal(tree->left,action);
	PostorderTraversal(tree->right,action);
	action(tree->data);
}