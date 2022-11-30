/*
  ��1��˳��ջ���������Ͷ��弰����ʵ��
  ��2��������Եķ���
  ��3������ж���ĳ�������ȷ��

*/
#ifndef _SqStack
#define _SqStack

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define STACKSIZE 1000

/*�����������Ͷ���*/
typedef int ElemType;
typedef struct stack {
	ElemType data[STACKSIZE];
	int top;
} Sqstack;

void Initstack(Sqstack *L); /*��ʼ��˳��ջ*/
void Createstack(Sqstack *L); /*����˳��ջ*/
int GetLength(Sqstack *L);  /*���˳��ջ�ĳ���*/
int Push(Sqstack *L,ElemType *e);  /*����Ԫ��*/
int Pop(Sqstack *L,int *i);  /*ɾ��Ԫ��*/
int Traversstack(Sqstack *L);   /*����˳��ջ*/
void Clearstack(Sqstack *L);    /*���˳��ջ*/
int StackEmpty(Sqstack *L); /*�ж�ջ�Ƿ��*/
int StackFull(Sqstack *L); /*�ж�ջ�Ƿ���*/
int StackTop(Sqstack *L,ElemType *e);  /*ȡջ��Ԫ��*/

#endif
