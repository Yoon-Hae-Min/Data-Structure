#include <stdio.h>
#include <stdlib.h>

typedef int BTData;
typedef void (*VisitFuncPtr)(BTData data);

typedef struct Tnode{
	BTData data;
	Tnode *right;
	Tnode *left;
}treeNode;

treeNode *MakeNode(BTData data);
BTData GetBTData(treeNode *tree);
treeNode *GetLeftSubNode(treeNode *tree);
treeNode *GetRightSubNode(treeNode *tree);
void ConnectLeftNode(treeNode *tree, treeNode *sub);
void ConnectRightNode(treeNode *tree, treeNode *sub);

void PreorderTraversal(treeNode *tree, VisitFuncPtr action);
void InorderTraversal(treeNode *tree, VisitFuncPtr action);
void PostorderTraversal(treeNode *tree, VisitFuncPtr action);

treeNode *RemoveRightSubTree(treeNode *tree);
treeNode *RemoveLeftSubTree(treeNode *tree);

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
	if(tree==NULL) return NULL;
	return tree->left;
}
treeNode *GetRightSubNode(treeNode *tree){
	if(tree==NULL) return NULL;
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

treeNode *RemoveRightSubTree(treeNode *tree){
	treeNode *deleteTree;
	if(tree!=NULL){
		deleteTree=tree->right;
		tree->right=NULL;
	}
	return deleteTree;
}
treeNode *RemoveLeftSubTree(treeNode *tree){
	treeNode *deleteTree;
	if(tree!=NULL){
		deleteTree=tree->left;
		tree->left=NULL;
	}
	return deleteTree;
}

void ChangeLeftSubTree(treeNode *parent,treeNode *target){
	parent->left=target;
}
void ChangeRightSubTree(treeNode *parent,treeNode *target){
	parent->right=target;
}