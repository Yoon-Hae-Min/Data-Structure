#include "InfixToPostfix.cpp"

int main(){
	char exp1[]="1+2*3";
	char exp2[]="(1+3*(2+3))";
	
	
	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	
	printf("%s \n",exp1);
	printf("%s \n",exp2);
}