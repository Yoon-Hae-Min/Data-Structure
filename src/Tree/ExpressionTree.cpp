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
	if(tnode==NULL) return;
	
	if(tnode->left!=NULL||tnode->right!=NULL){
		
		printf("(");
	}
		
	ShowInfixTypeExp(tnode->left);
	ShowData(tnode->data);
	ShowInfixTypeExp(tnode->right);
	if(tnode->left!=NULL||tnode->right!=NULL){
	printf(")");}
}
void ShowPostfixTypeExp(treeNode *tnode){
	 PostorderTraversal(tnode,ShowData);
}

int EvaluateExpTree(treeNode *et){
	int op1,op2;
	if(GetLeftSubNode(et)==NULL && GetRightSubNode(et)==NULL){
		return GetBTData(et);
	}
	op1=EvaluateExpTree(GetLeftSubNode(et));
	op2=EvaluateExpTree(GetRightSubNode(et));


	switch(GetBTData(et)){
		case '+':
			return op1+op2;
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
	}
	return 0;
}