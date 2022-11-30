#ifndef _LKQUEUE
#define _LKQUEUE

typedef int DataType;

/*结点定义*/
typedef struct node
{
     DataType data;
	 struct node *next;
}LNode;
/*队列定义*/
typedef struct
{
	LNode *front;
	LNode *rear;
}LkQueue;

int InitQueue(LkQueue *q);
int GetFirst(LkQueue *q,DataType *e);
int GetRear(LkQueue *q,DataType *e);
int DeQueue(LkQueue *q,DataType *e);
int EnQueue(LkQueue *q,DataType *e);
int IsEmpty(LkQueue *q);
int IsFull(LkQueue *q);
int TraversQueue(LkQueue *q);
int DestroyQueue(LkQueue *q);
int Length(LkQueue *q);

#endif