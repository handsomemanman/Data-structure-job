#include "lkqueue.h"
#include "stdio.h"

int main( ) {
	LkQueue s;
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

	/*���´�����������е�����Ԫ��*/
	i=0;
	while(!IsEmpty(&s)) {
		/*������ȷ�Ĵ���*/
		if(DeQueue(&s,&e))
			printf("%4d",e);
		/*�������*/
		if(++i%10==0) printf("\n");
	}
	DestroyQueue(&s);
	return 0;
}
