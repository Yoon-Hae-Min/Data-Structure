#include "Queue.cpp"
#include <time.h>

#define Cus_Come_Term 15

#define CHE_buger 0
#define BUL_buger 1
#define DUB_buger 2

#define CHE_Time 12
#define BUL_Time 15
#define DUB_Time 24

int main(){
	Queue q;
	QueueInit(&q);
	srand(time(NULL));
	int simu;
	int overflow=0;
	int order=0,make=0;
	int CHEM=0,BULM=0,DUBM=0;
	for(simu=0;simu<3000;simu++){
		for(int i=0;i<3600;i++){
			if(i%Cus_Come_Term == 0){
				switch(rand()%3){
					case CHE_buger:
						Enqueue(&q,CHE_Time);
						CHEM++;
						order++;
						break;
					case BUL_buger:
						Enqueue(&q,BUL_Time);
						BULM++;
						order++;
						break;
					case DUB_buger:
						Enqueue(&q,DUB_Time);
						DUBM++;
						order++;
						break;
				}
			}
			if(!QueueIsEmpty(&q)&&make<=0){
				make=Dequeue(&q);
				order--;
			}
			if(order>15){
				overflow++;
				break;
			}
			make--;

		}
		if(order<15){
			printf("치즈버거: %d\n",CHEM);
			printf("불고기버거: %d\n",BULM);
			printf("더블버거: %d\n",DUBM);
			printf("남은 대기실 인원수: %d\n\n",order);
		}
		CHEM=0;
		BULM=0;
		DUBM=0;
		order=0;

		
	}
	printf("안정적으로 고객을 수용할 확률: %f %%입니다", 100-((double)overflow/(simu)*100));
}
