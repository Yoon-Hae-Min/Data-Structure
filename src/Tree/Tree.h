typedef int Data;
typedef struct node{
	Data data;
	node *right;
	node *left;
}node;

node *MakeNode(Data data);
Data GetData(node *tree);
node *GetLeftSubNode(node *tree);
node *GetRightSubNode(node *tree);
void ConnectLeftNode(node *tree, node *sub);
void ConnectRightNode(node *tree, node *sub);

