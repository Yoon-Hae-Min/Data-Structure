#include "ExpressionTree.h"

treeNode *MakeExpTree(char exp[]){
	int explen=strlen(exp);
	Stack stack;
	treeNode * tnode;
	StackInit(&stack);
	for(int i=0;i<explen;i++){
		if(isdigit(exp[i])){
			tnode=MakeNode(exp[i]-'0');
		}
		else{
			tnode=MakeNode(exp[i]);
			ConnectRightNode(tnode,StackPop(&stack));
			ConnectLeftNode(tnode,StackPop(&stack));
		}
		StackPush(&stack,tnode);
	}
	return StackPop(&stack);
}

void ShowData(int data){
	if(0<=data&&data<=9) printf("%d ",data);
	else printf("%c ",data);
}

void ShowPrefixTypeExp(treeNode *tnode){
	 PreorderTraversal(tnode,ShowData);
}
void ShowInfixTypeExp(treeNode *tnode){
	 InorderTraversal(tnode,ShowData);
}
void ShowPostfixTypeExp(treeNode *tnode){
	 PostorderTraversal(tnode,ShowData);
}