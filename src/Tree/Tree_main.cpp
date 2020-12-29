#include <stdio.h>
#include "Tree.cpp"

int main(){
	node *b1=MakeNode(1);
	node *b2=MakeNode(2);
	node *b3=MakeNode(3);
	node *b4=MakeNode(4);
	
	ConnectLeftNode(b1,b2);
	ConnectRightNode(b1,b3);
	ConnectLeftNode(b2,b4);
	
	PostorderTraversal(b1);
	printf("\n");
	InorderTraversal(b1);
	printf("\n");
	PreorderTraversal(b1);
}