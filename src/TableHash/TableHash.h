/*

오류의 결과: 구조체가 문제였음 이미 포인터 함수가 정의되어있는 
시점에서 포인터를 써서 구조체안에 포인터함수를 만들었으니 
이중포인터함수가 되어버려서 꼬이게 된것



*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 50
#define TABLE_LEN 30
typedef int(*HashFunction)(int);

enum SlotStatus {EMPTY,DELETE,INUSE};

typedef struct person{
	int ssn;
	char name[STR_LEN];
	char address[STR_LEN];
}person;

typedef struct Slot{
	int key;
	person *value;
	enum SlotStatus status;
}slot;

typedef struct Table{
	slot table[TABLE_LEN];
	HashFunction hash;//여기가 문제였음
}table;

int HashFun();
void TableInit(table *mtable, HashFunction h);
void TableInsert(table *mtable,int key, person *per);
person *TableDelete(table *mtable, int key);
person *TableSearch(table *mtable, int key);
void PrintPersonData(person *p);
person *MakePersonData();

person *MakePersonData(int ssn, char *name, char *adress){
	person *newPersonData=(person*)malloc(sizeof(person));
	newPersonData->ssn=ssn;
	strcpy(newPersonData->address,adress);
	strcpy(newPersonData->name,name);
	return newPersonData;
}

void PrintPersonData(person *p){
	printf("주민등록 번호:%d\n",p->ssn);
	printf("이름:%s\n",p->name);
	printf("주소:%s\n",p->address);
	printf("\n");
}

void TableInit(table *mtable, HashFunction h){//* 안붙여도 이미 포인터 함수가 정의되어있음(주소를 가지고있음)
	for(int i=0;i<TABLE_LEN;i++){
		(mtable->table[i]).status=EMPTY;
	}
	mtable->hash=h;// hash도 HashFunction(즉 h)랑 같은 자료형으로 정의되어있으므로 그냥 주소값을 넣으면 됨
	
}
void TableInsert(table *mtable,int key, person *per){
	int hashvalue=(mtable->hash)(key);//mtable->hash(key) 같은의미
	(mtable->table[hashvalue]).status=INUSE;
	(mtable->table[hashvalue]).value=per;
	(mtable->table[hashvalue]).key=key;
}
person *TableDelete(table *mtable, int key){
	int hashvalue=mtable->hash(key);
	if((mtable->table[hashvalue]).status != INUSE) return NULL;
	else {
		(mtable->table[hashvalue]).status=DELETE;
		return (mtable->table[hashvalue]).value;
	}
}
person *TableSearch(table *mtable, int key){
	int hashvalue=mtable->hash(key);
	if((mtable->table[hashvalue]).status != INUSE) return NULL;
	else {
		return (mtable->table[hashvalue]).value;
	}
	
}

