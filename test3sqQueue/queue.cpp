#include "queue.h"

/*q->front指向队首元素,q->rear指向队尾元素的后一个位置*/
/*当q->front==q->rear=0时,队列为空
  当(q->rear+1)%QUEUESIZE==q->front时,队列满*/
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
int DeQueue(Queue *q,DataType *e) {//队列pop
	/*在此处插入正确的代码*/
	if(IsEmpty(q)) {
		cout<<"The queue is empty,can't pop."<<endl;
		return 0;
	} else {
		*e=q->data[q->front];
		q->front=(q->front+1)%QUEUESIZE;
	}


	/*插入结束*/
	return 1;
}
int EnQueue(Queue *q,DataType *e) {//队列push
	/*在此处插入正确的代码*/
	if(IsFull(q)) {
		return 0;
	} else {
		q->data[q->rear]=*e;
		q->rear=(q->rear+1)%QUEUESIZE;
	}

	/*插入结束*/
	return 1;
}
int IsEmpty(Queue *q) {
	return q->rear==q->front;
}
int IsFull(Queue *q) {
	return (q->rear+1)%QUEUESIZE==q->front;
}
