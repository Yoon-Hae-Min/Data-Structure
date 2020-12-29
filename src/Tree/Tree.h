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


