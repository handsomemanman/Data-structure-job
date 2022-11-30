#include "SqStack.h"

/*抽象数据类型的操作实现*/
void Initstack(Sqstack *L) { /*初始化顺序栈*/
	L->top=0;
}

void Createstack(Sqstack *L) { /*创建顺序栈*/
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


int Push(Sqstack *L,ElemType *e) { /*元素*e进栈,进栈成功,函数返回1*/
	/*以下插入正确的代码*/
	if(L->top>=STACKSIZE) {
		cout<<"stack is full!"<<endl;
		return 0;
	}

	L->data[L->top]=*e;
	L->top++;
	/*代码插入结束*/
	return 1;
}

int Pop(Sqstack *L,ElemType *e) { /*从栈顶出栈一个元素,并何存在*e中,成功返回1*/
	/*以下插入正确的代码*/
	if(L->top==0) {
		cout<<"stack is empty!"<<endl;
		return 0;
	}
	L->top--;
	*e=L->data[L->top];

	/*代码插入结束*/
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

int StackEmpty(Sqstack *L) { /*判断栈顶否为空*/
	/*在空白处填上适当的表达式*/
	return(  L->top==0 ? 1 : 0  );
}

int Traversstack(Sqstack *L) { /*遍历顺序栈*/
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

void Clearstack(Sqstack *L) {  /*清除顺序栈*/
	L->top=0;
}
