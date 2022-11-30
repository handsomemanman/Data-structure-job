#ifndef _Queue
#define _Queue
#define QUEUESIZE 1000
#include <bits/stdc++.h>

using namespace std;

typedef int DataType;
typedef struct node {
	DataType data[QUEUESIZE];
	int front,rear;
} Queue;

int InitQueue(Queue *q);
int GetFirst(Queue *q,DataType *e);
int GetRear(Queue *q,DataType *e);
int DeQueue(Queue *q,DataType *e);
int EnQueue(Queue *q,DataType *e);
int IsEmpty(Queue *q);
int IsFull(Queue *q);

#endif
