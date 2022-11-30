#include "lkqueue.h"
#include "malloc.h"
#include "stdio.h"

/*本例采用具有头结点的单链表*/
int InitQueue(LkQueue *q) {
	LNode *p;
	p=(LNode *)malloc(sizeof(LNode));
	p->next=NULL;
	if(!p)return 0;
	q->front=q->rear=p;
	return 1;
}
int GetFirst(LkQueue *q,DataType *e) {
	if(IsEmpty(q)) return 0;
	*e=q->front->next->data;
	return 1;
}

int GetRear(LkQueue *q,DataType *e) {
	if(IsEmpty(q)) return 0;
	*e=q->rear->data;
	return 1;
}
/*出队操作*/
int DeQueue(LkQueue *q,DataType *e) {
	LNode *p;
	if(IsEmpty(q)) return 0;
	/*请插入正确的程序代码*/
	else {
		p = q->front;
		*e = q->front->next->data;
		q->front = q->front->next;
		free(p);
	}
	/*插入结束*/
	return 1;
}
/*入队操作*/
int EnQueue(LkQueue *q,DataType *e) {
	LNode *p;
	if(IsFull(q))
		return 0;
	/*请插入正确的程序代码*/
	p = (LNode *)malloc(sizeof(LNode));
	p->data = *e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;

	/*插入结束*/
	return 1;
}
int IsEmpty(LkQueue *q) {
	return q->front==q->rear;
}
int IsFull(LkQueue *q) {
	LNode *p;
	p=(LNode *)malloc(sizeof(LNode));
	return p==NULL;
}
/*销毁链队列*/
int DestroyQueue(LkQueue *q) {
	DataType e;
	if(!q->front) return 0;
	/*插入正确的代码*/
	LNode *p1 = q->front;
	LNode *p2 = q->front;
	while (p2 == NULL) {
		p1 = p2;
		p2 = p2->next;
		free(p1);
	}
	/*插入结束*/
	return 1;
}
int TraversQueue(LkQueue *q) {
	LNode *p;
	p=q->front->next;
	while(p) {
		printf("%5d",p->data);
		p=p->next;
	}
	printf("\n");
	return 1;
}

int Length(LkQueue *q) {
	LNode *p;

	int i=0;
	p=q->front->next;
	while(p) {
		i++;
		p=p->next;
	}
	return i;
}
