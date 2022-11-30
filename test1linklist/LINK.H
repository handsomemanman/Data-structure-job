/*
  ���Ա�ʵ�����--������
  ʵ��Ŀ�ģ�
   ��1���������Ա���˳��洢����ʽ�洢������ز���
   ��2������˳��洢�µ��й��㷨
   ��3��������Գ���ķ���
*/

#ifndef _LINK

#define _LINK

#include <stdio.h>
#include <malloc.h>
#include <bits/stdc++.h>
#include <stack>

/*�����������Ͷ���*/
typedef int ElemType;
typedef struct node {
	ElemType data;
	struct node *next;
}*LKList,LNode;
void InitList(LKList *L); /*��ʼ�����Ա�*/
void CreateList(LKList *L); /*�������Ա�*/
int GetLength(LKList *L);  /*������Ա��ĳ���*/
int GetElem(LKList *L,int i,ElemType *e); /*ȡ���Ա���i����Ԫ�أ�������eָ��ĵ��ڴ���*/
int SetElem(LKList *L,int i,ElemType *e); /*�޸ĵ�i����Ԫ��*/
int InsertElem(LKList *L,int i, ElemType *e);  /*�ڵ�i��λ�ò���Ԫ��*/
int DeleteElem(LKList *L,int i);  /*ɾ����i��Ԫ��*/
int SearchElem(LKList *L,ElemType *e); /*����Ԫ��*e��λ��i*/
int TraversList(LKList *L);   /*�������Ա�*/
void ClearList(LKList *L);    /*������Ա�*/
LKList FindElem(LKList *L,int i);  /*ȡ��i��Ԫ�صĵ�ַ*/

/*���²��䵥�������������˵��*/
void Reverse(LKList *L);

/*�������*/

#endif