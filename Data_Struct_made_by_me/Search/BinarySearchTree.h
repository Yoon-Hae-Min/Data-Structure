#include <stdio.h>
#include <stdlib.h>

typedef int Tdata;

typedef int (*ComPriority)(int,int);

typedef struct tree{
    Tdata data;
    tree *right;
    tree *left;
    
}TNode;

typedef struct PriorityQueue{
    TNode *Rootnode;
    ComPriority cmp;
}BTree;


//프로토타입
void TreeInit(BTree *tree, ComPriority compareFuc,Tdata Rootdata);
int WhoIsPre(int a,int b);
TNode *ReturnLeftSubTree(TNode *Rtree);
TNode *ReturnRightSubTree(TNode *Rtree);
void ConnectRightSubTree(TNode *Rtree, TNode *Ctree);
void ConnectLeftSubTree(TNode *Rtree, TNode *Ctree);
TNode *MakeTreeNode();
void SetTreeData(TNode *Rtree, Tdata data);
void PreOrderTraversal(TNode *Rtree);
void InOrderTraversal(TNode *Rtree);
void PostOrderTraversal(TNode *Rtree);
void BinarySearchTreeInert(TNode *Rtree, Tdata data);
void interface();


//사용자 지정

int WhoIsPre(int a,int b){
    if(a>b) return 1;
    else return 0;
}




//basic


void TreeInit(BTree *tree, ComPriority compareFuc,Tdata Rootdata){
    tree->Rootnode=NULL;
    tree->cmp=compareFuc;
    tree->Rootnode=MakeTreeNode();
    SetTreeData(tree->Rootnode,Rootdata);
}

TNode *ReturnLeftSubTree(TNode *Rtree){
    return Rtree->left;
}

TNode *ReturnRightSubTree(TNode *Rtree){
    return Rtree->right;
}

void ConnectRightSubTree(TNode *Rtree, TNode *Ctree){
    Rtree->right=Ctree;   
}

void ConnectLeftSubTree(TNode *Rtree, TNode *Ctree){
    Rtree->left=Ctree;
}

TNode *MakeTreeNode(){
    TNode *NewNode=(TNode*)malloc(sizeof(TNode));
    NewNode->left=NULL;
    NewNode->right=NULL;
    return NewNode;
}

void SetTreeData(TNode *Rtree, Tdata data){
    Rtree->data=data;
}

//print


void PreOrderTraversal(TNode *Rtree){
    if(Rtree==NULL) return;
    printf("%d ",Rtree->data);
    PreOrderTraversal(ReturnLeftSubTree(Rtree));
    PreOrderTraversal(ReturnRightSubTree(Rtree));
}

void InOrderTraversal(TNode *Rtree){
    if(Rtree==NULL) return;
    PreOrderTraversal(ReturnLeftSubTree(Rtree));
    printf("%d ",Rtree->data);
    PreOrderTraversal(ReturnRightSubTree(Rtree));
}

void PostOrderTraversal(TNode *Rtree){
    if(Rtree==NULL) return;
    PreOrderTraversal(ReturnLeftSubTree(Rtree));
    PreOrderTraversal(ReturnRightSubTree(Rtree));
    printf("%d ",Rtree->data);
}

//

void BinarySearchTreeInert(TNode *Rtree, Tdata data){
    TNode *SubNode=MakeTreeNode();
    TNode *curNode=Rtree;
    TNode *parentNode=curNode;

    SetTreeData(SubNode,data);
    while(curNode !=NULL){
        if(curNode->data > SubNode->data){
            parentNode=curNode;
            curNode=ReturnLeftSubTree(curNode);
        }
        else{
            parentNode=curNode;
            curNode=ReturnRightSubTree(curNode);
        }
    }

    if(parentNode->data > SubNode->data){
        ConnectLeftSubTree(parentNode,SubNode);
    }
    else{
        ConnectRightSubTree(parentNode,SubNode);
    }
    

}


void interface(){
    int select;
    Tdata data;
    BTree Rtree;
    TreeInit(&Rtree, WhoIsPre, 3);//초기값 없게 설정하기
    TNode *RNode=Rtree.Rootnode;
    printf("************************이진 탐색 트리************************\n");
    printf("**********************************************************\n\n\n\n\n");

    while(1){
        printf("\n1.input\n");
        printf("2.output\n");
        printf("3.Delete\n");
        printf("끝내기\n");
        scanf("%d", &select);
        switch (select)
        {
        case 1://input
            printf("넣을 데이터를 입력해 주세요: ");
            scanf("%d",&data);
            BinarySearchTreeInert(RNode,data);
            break;
        case 2://output
            printf("어떤방법을 선택하시겠습니까?\n");
            printf("1.PreOrder\n");
            printf("2.InOrder\n");
            printf("3.PostOrder\n");

            scanf("%d",&select);

            switch(select){
                case 1:
                    printf("\n--------결과--------\n");
                    PreOrderTraversal(RNode);
                    printf("\n--------------------\n");
                    break;
                case 2:
                    printf("\n--------결과--------\n");
                    InOrderTraversal(RNode);
                    printf("\n--------------------\n");
                    break;
                case 3:
                    printf("\n--------결과--------\n");
                    PostOrderTraversal(RNode);
                    printf("\n--------------------\n");
                    break;
                default:
                    printf("input error\n");
            }
            break;
        default:
            printf("프로그램 종료\n");
            exit(-1);
        }
    }

}