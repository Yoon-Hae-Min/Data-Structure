#include <stdio.h>
#include <string.h>

int main(){
	char arr[]="ABC한글";
	
	printf("%ld ",sizeof(arr));
	printf("%ld ",strlen(arr));
}