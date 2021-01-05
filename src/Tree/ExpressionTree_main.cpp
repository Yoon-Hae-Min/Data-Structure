#include "ExpressionTree.cpp"


int main(){
	char exp[]="12+3*";
	treeNode *exptree=MakeExpTree(exp);
	ShowPrefixTypeExp(exptree);
	printf("\n");
	ShowInfixTypeExp(exptree);
	printf("\n");
	ShowPostfixTypeExp(exptree);
	printf("\n");
	
	printf("%d ",EvaluateExpTree(exptree));
}