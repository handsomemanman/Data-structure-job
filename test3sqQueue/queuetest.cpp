#include "queue.h"
#include "stdio.h"


int main( ) {
	Queue s;
	int i;
	DataType e;

	InitQueue(&s);
	for(i=0; i<10; i++)
		EnQueue(&s,&i);
	while(!IsEmpty(&s)) {
		if(DeQueue(&s,&e))
			printf("%4d",e);
		else
			printf("Qeueu is Empty!\n");
	}
	printf("\n");
	for(i=0; i<1001; i++)
		if(!EnQueue(&s,&i))
			printf("queue is Full,%d can't enter queue!\n",i);
	/*���°�ÿ��10��Ԫ����������е�����Ԫ��*/
	i=0;
	while(!IsEmpty(&s)) {
		/*������ȷ�Ĵ���*/
		if(DeQueue(&s,&e))
			printf("%4d",e);
		else
			printf("Qeueu is Empty!\n");
		/*�������*/
		if(++i%10==0) printf("\n");
	}
	return 0;
}
