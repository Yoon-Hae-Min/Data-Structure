#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct treeNode{
    int data;
    treeNode *right=NULL;
    treeNode *left=NULL;
}treeNode;

typedef struct Stack{
    treeNode *data;
    Stack *next=NULL;
}Stack;

Stack *head=NULL;
//트리 노드 구성 함수
void Preorderprint(treeNode *main);
void Inorderprint(treeNode *main);
void Postorderprint(treeNode *main);

treeNode * MakeNode(int data);
void Lrootconnect(treeNode *connect,treeNode *main);
void Rrootconnect(treeNode *main, treeNode *connect);
void DeleteTree(treeNode *main);

//스텍으로 연산 트리만들기
void StackInit(treeNode *stack);
treeNode *StackPop();
treeNode *MakeExpTree(char exp[]);
void Stackprint();
int EvaluateExpTree(treeNode * tn);


//트리 출력
void printNodeData(int data);
void treeadressprint(treeNode *tree);
int main(){
/*treeNode *n1=MakeNode(1);
treeNode *n2=MakeNode(2);
treeNode *n3=MakeNode(3);
treeNode *n4=MakeNode(4);
treeNode *n5=MakeNode(5);

Lrootconnect(n2,n1);
Rrootconnect(n1,n3);
Lrootconnect(n4,n2);
Rrootconnect(n2,n5);

Inorderprint(n1);
DeleteTree(n1);
Inorderprint(n1);
*/
char exp[]="12+6*";
treeNode *etree=MakeExpTree(exp);
//Inorderprint(etree);
//Postorderprint(etree);
//Preorderprint(etree);
treeadressprint(etree);
//printf("%d ",EvaluateExpTree(etree));

}
void treeadressprint(treeNode *tree){
    if(tree==NULL) return;
 
    treeadressprint(tree->left);
    //printf("%p ",tree);
    //printNodeData(tree->data);//NULL인데 주소값이 있다??? 이건 무슨경우?
    treeadressprint(tree->right);
}

void printNodeData(int data){
    if(data>=0&&data<10){
        printf("%d ",data);
    }
    else{
        printf("%c ",data);
    }

}


void StackInit(treeNode *stack){
    Stack *num=(Stack*)malloc(sizeof(Stack));
    num->data=stack;
    num->next=head;
    head=num;
}

void Stackprint(){
    Stack *ptr=head;
    while(ptr->next!=NULL){
        printf("%p ",ptr->data);
        ptr=ptr->next;
    }
    printf("%p ",ptr->data);
}

treeNode * StackPop(){
    Stack *ptr=head;
    treeNode *nodedata=head->data;
    head=ptr->next; 
    free(ptr);
    //printf("%c", nodedata->data);
    return nodedata;
}

treeNode *MakeExpTree(char exp[]){
    int explen=strlen(exp);
    treeNode *main,*k;
    for (int i=0;i<explen;i++){
        if(isdigit(exp[i])){
            if(exp[i]-'0'==6){
                printf("%c ",exp[i]);
               k=MakeNode(exp[i]-'0');
            }
            
            main=MakeNode(exp[i]-'0');//왜 7오른쪽에 쓰레기값이 붙어짔지? 만드는게 문제 100퍼
            if(exp[i]-'0'==6){
                Inorderprint(k);
            }
            //Inorderprint(main);
        }
        else{
            
            main=MakeNode(exp[i]);
            Rrootconnect(main,StackPop());
            Lrootconnect(StackPop(),main);
            //Inorderprint(main);
            //printf("\n\n\n");
        }
        StackInit(main);
        //Stackprint();
       // printf("\n\n\n");
    }
    return StackPop();
}

int EvaluateExpTree(treeNode * tn){
    if(tn->left==NULL && tn->right==NULL){ //지금 스페이스바가 하나가 껴들어가있음 출력했을때 주소값이 5개나와야하는데 6개 나옴
        //printf("%d ",tn->data-'0');
        //return tn->data-'0';
        return 1;
    }
    int leftdata=EvaluateExpTree(tn->left);
    int rightdata=EvaluateExpTree(tn->right);
    return leftdata+rightdata;
    /*switch(tn->data){
        case '+':
            return leftdata + rightdata;
        case '-':
            return leftdata - rightdata;
        case '*':
            return leftdata * rightdata;
        case '/':
            return leftdata / rightdata;
    }*/

}














void Preorderprint(treeNode *main){//전위순회
    if(main==NULL) return;
    printf("%d ",main->data);
    Preorderprint(main->left);
    Preorderprint(main->right);
}

void Inorderprint(treeNode *main){//중위순회
    if(main==NULL) return;
    Inorderprint(main->left);
    printf("%d ",main->data);
    Inorderprint(main->right);

}

void Postorderprint(treeNode *main){//후위순회
    if(main==NULL) return;
    Postorderprint(main->left);
    Postorderprint(main->right);
    printf("%d ",main->data);

}

void Lrootconnect(treeNode *connect,treeNode *main){
    main->left=connect;
}

void Rrootconnect(treeNode *main, treeNode *connect){
    main->right=connect;
}

void DeleteTree(treeNode *main){
    if(main==NULL)return;
    DeleteTree(main->left);
    DeleteTree(main->right);
    free(main);
}

treeNode * MakeNode(int data){
    treeNode *newnode=(treeNode *)malloc(sizeof(treeNode));
    newnode->data=data;
	newnode->left=NULL;
	newnode->right=NULL;
    return newnode;
}
