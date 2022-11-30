#include "Lineast01.h"
#include<iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
/*抽象数据类型的操作实现*/
void InitList(SqList *L) { /*初始化线性表*/
	L->Length=0;
}

void CreateList(SqList *L) { /*创建线性表*/
	int i,ok;
	ElemType e;

	InitList(L);
	i=0;
	printf("input end while enter -9999!\n");
	while(1) {
		cin >> e;
		if(e!=-9999) {
			ok=InsertElem(L,++i,&e);
			if(!ok) break;
		} else
			break;
	}
	L->Length=i;
}

int GetLength(SqList *L) { /*获得线性表的长度*/
	return L->Length;
}

int GetElem(SqList *L,int i,ElemType *e) { /*取线性表第i个表元素，并放在e指向的的内存中*/
	if(i<1||i>GetLength(L))
		return 0;
	*e=L->data[i];
	return 1;
}

int SetElem(SqList *L,int i,ElemType *e) { /*修改第i个表元素*/
	if(i<1||i>GetLength(L))
		return 0;
	L->data[i]=*e;
	return 1;
}

int InsertElem(SqList *L,int i, ElemType *e) { /*在第i个位置插入元素,插入成功返回1*/
	int j;
	/*请在以下部分插入程序代码*/
	if (i>L->Length+1||i<=0 ) {
		cout << "插入位置有误，你这样我怎么插进去？" <<endl;
		return 0;
	}
	if (L->Length == LINEASTMAXSIZE) {//内存用完
		cout<<"内存不足";
		return 0;
	}
	if (i == L->Length+1) {//插在表尾
		i = L->Length+1 ;
	} else {
		for (j = L->Length; j >= i; j--) {
			L->data[j + 1] = L->data[j];
		}
	}
	L->data[i]=*e;
	L->Length++;
	/*插入代码结束*/
	return 1;
}

int DeleteElem(SqList *L,int i) { /*删除第i个元素,删除成功返回1*/
	int j=0;
	int n=GetLength(L);
	/*请在以下部分插入程序代码*/
	if(n==0||i>n) {
		cout<<"删除位置有误";
		return 0;
	}
	if(i!=n) {
		for(j=i+1; j<=n; j++) {
			L->data[j-1]=L->data[j];
		}
	}
	L->Length--;
	/*插入代码结束*/
	return 1;
}

int SearchElem(SqList *L,ElemType *e) { /*查找元素*e的位置j,找到返回,找不到返回-1,表示查找失败*/
	int j;
	int n=GetLength(L);
	/*请在下面插入你的代码*/
	for(j=1; j<=n; j++) {
		if (L->data[j] == *e) {
			*e = L->data[j];
			break;
		}
	}


	/*插入代码结束*/
	return j<=n?j:-1;
}

int TraversList(SqList *L) { /*遍历线性表*/
	int j;
	int n=GetLength(L);
	ElemType e;

	if(n==0) {
		printf("Lineast is Empty!!!\n");
		return 0;
	}
	for(j=1; j<=n; j++) {
		GetElem(L,j,&e);
		printf("%6d",e);
	}
	return 1;
}

void ClearList(SqList *L) {  /*清除线性表*/
	L->Length=0;
}

/*  以下为补充顺序表逆置操作实现 */
SqList* Reverse(SqList *L) {
	int temp;
	int i;

	for (i = 1; i <= L->Length/ 2; i++) {
		temp = L->data[i];
		L->data[i] = L->data[L->Length - i + 1];
		L->data[L->Length - i + 1] = temp;
	}
	return L;
}

/*   补充结束      */
