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

	/*以下代码输出队列中的所有元素*/
	i=0;
	while(!IsEmpty(&s)) {
		/*插入正确的代码*/
		if(DeQueue(&s,&e))
			printf("%4d",e);
		/*插入结束*/
		if(++i%10==0) printf("\n");
	}
	DestroyQueue(&s);
	return 0;
}
