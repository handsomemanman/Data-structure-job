/*
  ������ջ��ʹ��

*/
#ifndef _LKStack
#define _LKStack

#include <stdio.h>
#include<bits/stdc++.h>
#include <malloc.h>

using namespace std;

/*�����������Ͷ���*/
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}*LkStack,LNode;

void Initstack(LkStack *L); /*��ʼ����ջ*/

void Createstack(LkStack *L);

int GetLength(LkStack *L);  /*�����ջ�ĳ���*/

int Pop(LkStack *L,ElemType *e);

int Push(LkStack *L,ElemType *e);

int Traversstack(LkStack *L);   /*������ջ*/

void Clearstack(LkStack *L);    /*�����ջ*/

int StackEmpty(LkStack *L);

int StackFull(LkStack *L);

int StackTop(LkStack *L,ElemType *e);

#endif
