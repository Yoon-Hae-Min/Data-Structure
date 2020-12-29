#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

node *MakeNode(Data data){
	node * newNode=(node *)malloc(sizeof(node));
	newNode->data=data;
	newNode->right=NULL;
	newNode->left=NULL;
	return newNode;
}
Data GetData(node *tree){
	return tree->data;
}
node *GetLeftSubNode(node *tree){
	return tree->left;
}
node *GetRightSubNode(node *tree){
	return tree->right;
}
void ConnectLeftNode(node *tree, node *sub){
	if(GetLeftSubNode(tree)!=NULL) free(tree->left);
	tree->left=sub;
}
void ConnectRightNode(node *tree, node *sub){
	if(GetRightSubNode(tree)!=NULL) free(tree->right);
	tree->left=sub;
}
