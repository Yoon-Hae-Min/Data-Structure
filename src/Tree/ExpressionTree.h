#include "Tree.cpp"
#include "../Stack/Stack.cpp"
#include <string.h>
#include <ctype.h>
treeNode *MakeExpTree(char exp[]);
void ShowData(int data);
int EvaluateExpTree(treeNode *et);
void ShowPrefixTypeExp(treeNode *tnode);
void ShowInfixTypeExp(treeNode *tnode);
void ShowPostfixTypeExp(treeNode *tnode);