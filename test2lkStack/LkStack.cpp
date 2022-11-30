#include "LkStack.h"

/*抽象数据类型的操作实现*/
void Initstack(LkStack *L) { /*初始化链栈*/
	*L=NULL;
}

int GetLength(LkStack *L) { /*获得栈的长度*/
	int i=0;
	LkStack p=*L;
	while(p) {
		i++;
		p=p->next;
	}
	return i;
}


int Push(LkStack *L,ElemType *e) { /*元素*e入栈*/
	LNode *s;
	s=(LNode*)malloc(sizeof(LNode));
	/*在下面插入代码*/
	s->data=*e;
	s->next=*L;
	*L = s;

	/*插入结束*/

	return 1;
}

int Pop(LkStack *L,ElemType *e) { /*出栈一个元素,元素保存在*e中*/
	/*在以下地方插入代码*/
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

	/*插入结束*/

	return 1;
}

int Traversstack(LkStack *L) { /*遍历栈*/
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

void Clearstack(LkStack *L) {  /*清除栈占用的内存空间*/
	/*在以下地方插入代码*/
	LNode *s;
	while(*L!=NULL) {
		s=*L;
		*L=s->next;
		free(s);
	}


	/*插入结束*/
}
/********判断栈是否为空********/
int StackEmpty(LkStack *L) {
	return *L==NULL;
}
/********判断栈是否满了**********/
int StackFull(LkStack *L) {
	LNode *p;
	p=(LNode*)malloc(sizeof(LNode));
	if(p==NULL) return 1;
	free(p);
	return 0;
}
/********取栈顶元素*************/
int StackTop(LkStack *L,ElemType *e) {
	if(StackEmpty(L))
		return 0;
	*e=(*L)->data;
	return 1;
}
