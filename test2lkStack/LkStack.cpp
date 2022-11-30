#include "LkStack.h"

/*�����������͵Ĳ���ʵ��*/
void Initstack(LkStack *L) { /*��ʼ����ջ*/
	*L=NULL;
}

int GetLength(LkStack *L) { /*���ջ�ĳ���*/
	int i=0;
	LkStack p=*L;
	while(p) {
		i++;
		p=p->next;
	}
	return i;
}


int Push(LkStack *L,ElemType *e) { /*Ԫ��*e��ջ*/
	LNode *s;
	s=(LNode*)malloc(sizeof(LNode));
	/*������������*/
	s->data=*e;
	s->next=*L;
	*L = s;

	/*�������*/

	return 1;
}

int Pop(LkStack *L,ElemType *e) { /*��ջһ��Ԫ��,Ԫ�ر�����*e��*/
	/*�����µط��������*/
	if(*L==NULL) {
		cout<<"Stack is empty!"<<endl;
		return 0;
	} else {
		LNode *s;
		s=*L;
		*e=s->data;
		*L=s->next;
		free (s);
	}

	/*�������*/

	return 1;
}

int Traversstack(LkStack *L) { /*����ջ*/
	LNode *p=*L;
	ElemType e;

	if(p==NULL) {
		printf("Lineast is Empty!!!\n");
		return 0;
	}
	while(p) {
		e=p->data;
		printf("%6d",e);
		p=p->next;
	}
	return 1;
}

void Clearstack(LkStack *L) {  /*���ջռ�õ��ڴ�ռ�*/
	/*�����µط��������*/
	LNode *s;
	while(*L!=NULL) {
		s=*L;
		*L=s->next;
		free(s);
	}


	/*�������*/
}
/********�ж�ջ�Ƿ�Ϊ��********/
int StackEmpty(LkStack *L) {
	return *L==NULL;
}
/********�ж�ջ�Ƿ�����**********/
int StackFull(LkStack *L) {
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	if(p==NULL) return 1;
	free(p);
	return 0;
}
/********ȡջ��Ԫ��*************/
int StackTop(LkStack *L,ElemType *e) {
	if(StackEmpty(L))
		return 0;
	*e=(*L)->data;
	return 1;
}
