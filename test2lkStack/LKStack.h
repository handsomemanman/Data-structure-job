/*
  掌握链栈的使用

*/
#ifndef _LKStack
#define _LKStack

#include <stdio.h>
#include<bits/stdc++.h>
#include <malloc.h>

using namespace std;

/*抽象数据类型定义*/
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}*LkStack,LNode;

void Initstack(LkStack *L); /*初始化链栈*/

void Createstack(LkStack *L);

int GetLength(LkStack *L);  /*获得链栈的长度*/

int Pop(LkStack *L,ElemType *e);

int Push(LkStack *L,ElemType *e);

int Traversstack(LkStack *L);   /*遍历链栈*/

void Clearstack(LkStack *L);    /*清除链栈*/

int StackEmpty(LkStack *L);

int StackFull(LkStack *L);

int StackTop(LkStack *L,ElemType *e);

#endif
