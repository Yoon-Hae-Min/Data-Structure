#include "AVLBinarySearchTree.h"

int main()
{
	
	treeNode * avlRoot;
	treeNode * clNode;		// current left node
	treeNode * crNode;		// current right node

	treeNode * clNode2;    
	treeNode * crNode2;

	treeNode * clNode3;
	treeNode * crNode3;

	BinarySearchTreeMake(&avlRoot);
	
	BinarySearchTreeInsert(&avlRoot, 1);
	BinarySearchTreeInsert(&avlRoot, 2);
	BinarySearchTreeInsert(&avlRoot, 3);//여기부터 오류
	BinarySearchTreeInsert(&avlRoot, 4);
	BinarySearchTreeInsert(&avlRoot, 5);
	BinarySearchTreeInsert(&avlRoot, 6);
	BinarySearchTreeInsert(&avlRoot, 7);
	BinarySearchTreeInsert(&avlRoot, 8);
	BinarySearchTreeInsert(&avlRoot, 9);

	printf("루트 노드: %d \n", avlRoot->data);    //4

	clNode = GetLeftSubNode(avlRoot);   //2, 루트 4의 왼편
	crNode = GetRightSubNode(avlRoot);  //6, 루트 4의 오른편
	printf("%d, %d \n",clNode->data,crNode->data);

	clNode2 = GetLeftSubNode(clNode);    //1, 2의 왼편
	crNode2 = GetRightSubNode(clNode);   //3, 2의 오른편
	printf("%d, %d \n",clNode2->data,crNode2->data);

	clNode2 = GetLeftSubNode(crNode);    //5, 3의 왼편
	crNode2 = GetRightSubNode(crNode);   //8, 3의 오른편
	printf("%d, %d \n",clNode2->data,crNode2->data);

	clNode3 = GetLeftSubNode(crNode2);   //7, 8의 왼편
	crNode3 = GetRightSubNode(crNode2);  //9, 8의 오른편
	printf("%d, %d \n",clNode3->data,crNode3->data); 
	return 0;
}