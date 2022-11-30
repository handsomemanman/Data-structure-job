#include "queue.h"

/*q->frontָ�����Ԫ��,q->rearָ���βԪ�صĺ�һ��λ��*/
/*��q->front==q->rear=0ʱ,����Ϊ��
  ��(q->rear+1)%QUEUESIZE==q->frontʱ,������*/
int InitQueue(Queue *q) {
	q->rear=0;
	q->front=0;
	return 0;
}
int GetFirst(Queue *q,DataType *e) {
	if(IsEmpty(q))
		return 0;
	*e=q->data[q->front];
	return 1;
}
int GetRear(Queue *q,DataType *e) {
	if(IsEmpty(q))
		return 0;
	*e=q->data[q->rear];
	return 1;
}
int DeQueue(Queue *q,DataType *e) {//����pop
	/*�ڴ˴�������ȷ�Ĵ���*/
	if(IsEmpty(q)) {
		cout<<"The queue is empty,can't pop."<<endl;
		return 0;
	} else {
		*e=q->data[q->front];
		q->front=(q->front+1)%QUEUESIZE;
	}


	/*�������*/
	return 1;
}
int EnQueue(Queue *q,DataType *e) {//����push
	/*�ڴ˴�������ȷ�Ĵ���*/
	if(IsFull(q)) {
		return 0;
	} else {
		q->data[q->rear]=*e;
		q->rear=(q->rear+1)%QUEUESIZE;
	}

	/*�������*/
	return 1;
}
int IsEmpty(Queue *q) {
	return q->rear==q->front;
}
int IsFull(Queue *q) {
	return (q->rear+1)%QUEUESIZE==q->front;
}
