#include "PostCarculator.h"

int EvalRPNExp(char exp[]){
	Stack stack;
	int explen=strlen(exp);
	char num,op1,op2;
	
	StackInit(&stack);
	
	for(int i=0;i<explen;i++){
		num=exp[i];
		if(isdigit(num)){
			StackPush(&stack,num-'0');
		}
		else{
			op2=StackPop(&stack);
			op1=StackPop(&stack);
			
			switch(num){
				case '+':
					StackPush(&stack,op1+op2);
					break;
				case '-':
					StackPush(&stack,op1-op2);
					break;
				case '*':
					StackPush(&stack,op1*op2);
					break;
				case '/':
					StackPush(&stack,op1/op2);
					break;
			}
		}
	}
	return StackPop(&stack);
}