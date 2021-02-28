#include "TableHash.h"
int HashFun(int key);

int HashFun(int key){
	return key%100;
}//main에 있어야 할것

int main(){
	table mytable;
	person *sp;
	TableInit(&mytable, HashFun);//????
	person *p1=MakePersonData(20120003,"Lee","Seoul");
	TableInsert(&mytable,p1->ssn,p1);
	person *p2=MakePersonData(20120012,"KIM","Jeju");
	TableInsert(&mytable,p2->ssn,p2);
	person *p3=MakePersonData(20170049,"Han","Kangwon");
	TableInsert(&mytable,p3->ssn,p3);
	
	sp=TableSearch(&mytable,2012003);
	if(sp!=NULL) PrintPersonData(sp);
	
	sp=TableSearch(&mytable,2012012);
	if(sp!=NULL) PrintPersonData(sp);
	
	sp=TableSearch(&mytable,2017049);
	if(sp!=NULL) PrintPersonData(sp);

	
}