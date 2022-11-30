/*
  线性表实验程序--单链表
  实验目的：
   （1）掌握线性表的顺序存储和链式存储及其相关操作
   （2）掌握顺序存储下的有关算法
   （3）理解测试程序的方法
*/

#ifndef _LINK

#define _LINK

#include <stdio.h>
#include <malloc.h>
#include <bits/stdc++.h>
#include <stack>

/*抽象数据类型定义*/
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}*LKList,LNode;
void InitList(LKList *L); /*初始化线性表*/
void CreateList(LKList *L); /*创建线性表*/
int GetLength(LKList *L);  /*获得线性表的长度*/
int GetElem(LKList *L,int i,ElemType *e); /*取线性表第i个表元素，并放在e指向的的内存中*/
int SetElem(LKList *L,int i,ElemType *e); /*修改第i个表元素*/
int InsertElem(LKList *L,int i, ElemType *e);  /*在第i个位置插入元素*/
int DeleteElem(LKList *L,int i);  /*删除第i个元素*/
int SearchElem(LKList *L,ElemType *e); /*查找元素*e的位置i*/
int TraversList(LKList *L);   /*遍历线性表*/
void ClearList(LKList *L);    /*清除线性表*/
LKList FindElem(LKList *L,int i);  /*取第i个元素的地址*/

/*以下补充单链表的逆序操作说明*/
void Reverse(LKList *L);

/*补充结束*/

#endif
