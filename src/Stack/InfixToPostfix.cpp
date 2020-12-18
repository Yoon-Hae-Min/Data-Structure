#include "InfixToPostfix.h"
#include <string.h>
#include <ctype.h>

int GetOpPrec(char op){
	switch(op){
		case '*': case '/':
			return 5;
			break;
		case '+': case '-':
			return 3;
			break;
		case '(':
			return 1;
			break;
		
	}
	return -1;
}
int WhoPrecOp(char op1, char op2){
	int GetOpPrecResult1=GetOpPrec(op1);
	int GetOpPrecResult2=GetOpPrec(op2);
	
	if(GetOpPrecResult1>GetOpPrecResult2) return 1;
	else if(GetOpPrecResult1<GetOpPrecResult2)
		return -1;
	else{
		return 0;
	}

}
void ConvToRPNExp(char exp[]){
	Stack stack;
	int explen=strlen(exp);
	char num,pop;
	int idx=0;
	char *conexp=(char*)malloc(sizeof(explen+1));
	
	memset(conexp,0,sizeof(char)*explen+1);
	StackInit(&stack);
	for(int i=0;i<explen;i++){
		num=exp[i];
		if(isdigit(num)){
			conexp[idx++]=num;
		}
		else{
			switch(num){
				case '(':
					StackPush(&stack,num);
					break;
				case ')':
					while(1){
						pop=StackPop(&stack);
						if(pop=='('){
							break;
						}
						conexp[idx++]=pop;
					}
					break;
				case '+': case '-': case '*': case '/':
					while(WhoPrecOp(StackPeek(&stack),num)>=0 && !StackEmpty(&stack)){
						conexp[idx++]=StackPop(&stack);
					}
					StackPush(&stack,num);
					break;
					
			}
		}
	}
	while(!StackEmpty(&stack)){
		conexp[idx++]=StackPop(&stack);
	}
	strcpy(exp,conexp);
	free(conexp);
}

