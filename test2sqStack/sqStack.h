/*
  （1）顺序栈的数据类型定义及操作实现
  （2）程序调试的方法
  （3）如何判定你的程序是正确的

*/
#ifndef _SqStack
#define _SqStack

#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#define STACKSIZE 1000

/*抽象数据类型定义*/
typedef int ElemType;
typedef struct stack {
	ElemType data[STACKSIZE];
	int top;
} Sqstack;

void Initstack(Sqstack *L); /*初始化顺序栈*/
void Createstack(Sqstack *L); /*创建顺序栈*/
int GetLength(Sqstack *L);  /*获得顺序栈的长度*/
int Push(Sqstack *L,ElemType *e);  /*插入元素*/
int Pop(Sqstack *L,int *i);  /*删除元素*/
int Traversstack(Sqstack *L);   /*遍历顺序栈*/
void Clearstack(Sqstack *L);    /*清除顺序栈*/
int StackEmpty(Sqstack *L); /*判断栈是否空*/
int StackFull(Sqstack *L); /*判断栈是否满*/
int StackTop(Sqstack *L,ElemType *e);  /*取栈顶元素*/

#endif
