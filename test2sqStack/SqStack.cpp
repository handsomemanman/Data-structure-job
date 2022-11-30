#include "SqStack.h"

/*�����������͵Ĳ���ʵ��*/
void Initstack(Sqstack *L) { /*��ʼ��˳��ջ*/
	L->top=0;
}

void Createstack(Sqstack *L) { /*����˳��ջ*/
	int i,ok;
	ElemType e;

	Initstack(L);
	i=0;
	printf("input end while enter -9999!\n");
	while(1) {
		scanf("%d",&e);
		if(e!=-9999) {
			ok=Push(L,&e);
			if(!ok) break;
		} else
			break;
	}
}


int Push(Sqstack *L,ElemType *e) { /*Ԫ��*e��ջ,��ջ�ɹ�,��������1*/
	/*���²�����ȷ�Ĵ���*/
	if(L->top>=STACKSIZE) {
		cout<<"stack is full!"<<endl;
		return 0;
	}

	L->data[L->top]=*e;
	L->top++;
	/*����������*/
	return 1;
}

int Pop(Sqstack *L,ElemType *e) { /*��ջ����ջһ��Ԫ��,���δ���*e��,�ɹ�����1*/
	/*���²�����ȷ�Ĵ���*/
	if(L->top==0) {
		cout<<"stack is empty!"<<endl;
		return 0;
	}
	L->top--;
	*e=L->data[L->top];

	/*����������*/
	return 1;
}

int StackTop(Sqstack *L,ElemType *e) {
	if(StackEmpty(L)) return 0;
	*e=L->data[L->top-1];
	return 1;
}

int StackFull(Sqstack *L) {
	return L->top==STACKSIZE;
}

int StackEmpty(Sqstack *L) { /*�ж�ջ����Ϊ��*/
	/*�ڿհ״������ʵ��ı��ʽ*/
	return(  L->top==0 ? 1 : 0  );
}

int Traversstack(Sqstack *L) { /*����˳��ջ*/
	int j;
	int n=L->top;
	ElemType e;

	if(n==0) {
		printf("Stack is Empty!!!\n");
		return 0;
	}
	for(j=0; j<n; j++) {
		e=L->data[j];
		printf("%6d",e);
	}
	return 1;
}

void Clearstack(Sqstack *L) {  /*���˳��ջ*/
	L->top=0;
}
