#include "PostCarculator.cpp"

int main(){
	char exp2[]="(1+3*(2+3))";
	printf("%s ",exp2);
	ConvToRPNExp(exp2);
	printf("= %d \n",EvalRPNExp(exp2));
}