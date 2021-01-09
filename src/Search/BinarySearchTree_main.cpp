#include "BinarySearchTree.h"

void print(int data){
	printf("%d ",data);
}

int main(){
	
	treeNode *roottree;
	treeNode *searchNode;
	
	BinarySearchTreeMake(&roottree);

	BinarySearchTreeInsert(&roottree, 9);
	BinarySearchTreeInsert(&roottree, 1);
	BinarySearchTreeInsert(&roottree, 6);
	BinarySearchTreeInsert(&roottree, 2);
	BinarySearchTreeInsert(&roottree, 8);
	BinarySearchTreeInsert(&roottree, 3);
	BinarySearchTreeInsert(&roottree, 5);
	
	searchNode=BinarySearchTreeSearch(&roottree,3);
	if(searchNode==NULL){
		printf("실패\n");
	}
	else{
		printf("성공\n");
	}
	
	PreorderTraversal(roottree, print);
}