/*
  线性表实验程序
  实验目的：
   （1）掌握线性表的顺序存储和链式存储及其相关操作
   （2）掌握顺序存储下的有关算法
   （3）理解测试程序的方法
*/
#ifndef _LINEAST
#define _CRT_SECURE_NO_WARNINGS

#define _LINEAST
#include <stdio.h>
#define LINEASTMAXSIZE 1000
#include<iostream>
/*抽象数据类型定义*/
typedef int ElemType;
typedef struct list {
	ElemType data[LINEASTMAXSIZE];
	int Length;
} SqList;
void InitList(SqList *L); /*初始化线性表*/
void CreateList(SqList *L); /*创建线性表*/
int GetLength(SqList *L);  /*获得线性表的长度*/
int GetElem(SqList *L,int i,ElemType *e); /*取线性表第i个表元素，并放在e指向的的内存中*/
int SetElem(SqList *L,int i,ElemType *e); /*修改第i个表元素*/
int InsertElem(SqList *L,int i, ElemType *e);  /*在第i个位置插入元素*/
int DeleteElem(SqList *L,int i);  /*删除第i个元素*/
int SearchElem(SqList *L,ElemType *e); /*查找元素*e的位置i*/
int TraversList(SqList *L);   /*遍历线性表*/
void ClearList(SqList *L);    /*清除线性表*/
/*以下是要添加的操作:顺序表逆置*/
SqList* Reverse(SqList *L);


/*添加结束*/
#endif
