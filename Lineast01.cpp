#include "Lineast01.h"
#include<iostream>
#include <bits/stdc++.h>
#include<cstdio>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
/*�����������͵Ĳ���ʵ��*/
void InitList(SqList *L) { /*��ʼ�����Ա�*/
	L->Length=0;
}

void CreateList(SqList *L) { /*�������Ա�*/
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

int GetLength(SqList *L) { /*������Ա�ĳ���*/
	return L->Length;
}

int GetElem(SqList *L,int i,ElemType *e) { /*ȡ���Ա��i����Ԫ�أ�������eָ��ĵ��ڴ���*/
	if(i<1||i>GetLength(L))
		return 0;
	*e=L->data[i];
	return 1;
}

int SetElem(SqList *L,int i,ElemType *e) { /*�޸ĵ�i����Ԫ��*/
	if(i<1||i>GetLength(L))
		return 0;
	L->data[i]=*e;
	return 1;
}

int InsertElem(SqList *L,int i, ElemType *e) { /*�ڵ�i��λ�ò���Ԫ��,����ɹ�����1*/
	int j;
	/*�������²��ֲ���������*/
	if (i>L->Length+1||i<=0 ) {
		cout << "����λ����������������ô���ȥ��" <<endl;
		return 0;
	}
	if (L->Length == LINEASTMAXSIZE) {//�ڴ�����
		cout<<"�ڴ治��";
		return 0;
	}
	if (i == L->Length+1) {//���ڱ�β
		i = L->Length+1 ;
	} else {
		for (j = L->Length; j >= i; j--) {
			L->data[j + 1] = L->data[j];
		}
	}
	L->data[i]=*e;
	L->Length++;
	/*����������*/
	return 1;
}

int DeleteElem(SqList *L,int i) { /*ɾ����i��Ԫ��,ɾ���ɹ�����1*/
	int j=0;
	int n=GetLength(L);
	/*�������²��ֲ���������*/
	if(n==0||i>n) {
		cout<<"ɾ��λ������";
		return 0;
	}
	if(i!=n) {
		for(j=i+1; j<=n; j++) {
			L->data[j-1]=L->data[j];
		}
	}
	L->Length--;
	/*����������*/
	return 1;
}

int SearchElem(SqList *L,ElemType *e) { /*����Ԫ��*e��λ��j,�ҵ�����,�Ҳ�������-1,��ʾ����ʧ��*/
	int j;
	int n=GetLength(L);
	/*�������������Ĵ���*/
	for(j=1; j<=n; j++) {
		if (L->data[j] == *e) {
			*e = L->data[j];
			break;
		}
	}


	/*����������*/
	return j<=n?j:-1;
}

int TraversList(SqList *L) { /*�������Ա�*/
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

void ClearList(SqList *L) {  /*������Ա�*/
	L->Length=0;
}

/*  ����Ϊ����˳������ò���ʵ�� */
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

/*   �������      */
