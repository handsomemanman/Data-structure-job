/*
  ���Ա�ʵ�����
  ʵ��Ŀ�ģ�
   ��1���������Ա��˳��洢����ʽ�洢������ز���
   ��2������˳��洢�µ��й��㷨
   ��3�������Գ���ķ���
*/
#ifndef _LINEAST
#define _CRT_SECURE_NO_WARNINGS

#define _LINEAST
#include <stdio.h>
#define LINEASTMAXSIZE 1000
#include<iostream>
/*�����������Ͷ���*/
typedef int ElemType;
typedef struct list {
	ElemType data[LINEASTMAXSIZE];
	int Length;
} SqList;
void InitList(SqList *L); /*��ʼ�����Ա�*/
void CreateList(SqList *L); /*�������Ա�*/
int GetLength(SqList *L);  /*������Ա�ĳ���*/
int GetElem(SqList *L,int i,ElemType *e); /*ȡ���Ա��i����Ԫ�أ�������eָ��ĵ��ڴ���*/
int SetElem(SqList *L,int i,ElemType *e); /*�޸ĵ�i����Ԫ��*/
int InsertElem(SqList *L,int i, ElemType *e);  /*�ڵ�i��λ�ò���Ԫ��*/
int DeleteElem(SqList *L,int i);  /*ɾ����i��Ԫ��*/
int SearchElem(SqList *L,ElemType *e); /*����Ԫ��*e��λ��i*/
int TraversList(SqList *L);   /*�������Ա�*/
void ClearList(SqList *L);    /*������Ա�*/
/*������Ҫ��ӵĲ���:˳�������*/
SqList* Reverse(SqList *L);


/*��ӽ���*/
#endif
