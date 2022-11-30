#include "LINK.H"
/*抽象数据类型的操作实现*/
void InitList(LKList *L) { /*初始化线性表*/
	*L=NULL;
}

void CreateList(LKList *L) { /*创建线性表*/
	int i,ok;
	ElemType e;

	InitList(L);
	i=0;
	printf("input end while enter -9999!\n");
	while(1) {
		scanf("%d",&e);
		if(e!=-9999) {
			ok=InsertElem(L,++i,&e);
			if(!ok) break;
		} else
			break;
	}
}

int GetLength(LKList *L) { /*获得线性表的长度*/
	int i=0;
	LKList p=*L;
	while(p) {
		i++;
		p=p->next;
	}
	return i;
}

LKList FindElem(LKList *L,int i) { /*查找第i个元素的操作,近到返回元素地址,找不到返回空*/
	LKList p=*L;
	int j=0;

	/*以下补充代码*/
	if(i>GetLength(L)||i<=0) {
		return NULL;
	}
	if(i>1) {
		for(j=1; j<i; j++) {
			p=p->next;
		}
	}
	/*代码补充结束*/
	return p;
}

int GetElem(LKList *L,int i,ElemType *e) { /*取线性表第i个表元素，并放在e指向的的内存中*/
	LKList p=FindElem(L,i);
	int j=0;

	if(p==NULL)
		return 0;
	*e=p->data;
	return 1;
}

int SetElem(LKList *L,int i,ElemType *e) { /*修改第i个表元素*/
	LKList p=FindElem(L,i);
	int j=0;

	if(p) p->data=*e;
	return 1;
}

int InsertElem(LKList *L,int i, ElemType *e) { /*在第i个位置插入元素*/
	LKList p=FindElem(L,i-1);
	LNode *s;
	/*构造待插入的结点*/
	s=(LNode*)malloc(sizeof(LNode));
	s->data=*e;
	s->next=NULL;
	/*以下补充代码*/
	if(i>GetLength(L)+1||i<=0) {
		printf("输入插入的位置有误\n");
		return 0;
	}
	if(p==NULL) {
		s->next=*L;
		*L=s;
	} else {
		s->next=p->next;
		p->next=s;
	}

	/*代码补充结束*/
	return 1;
}

int DeleteElem(LKList *L,int i) { /*删除第i个元素,成功,返回1*/
	LKList p,q;
	if(*L==NULL)return 0;
	/*以下补充代码*/
	if(i>GetLength(L)||i<=0) {
		printf("输入删除的位置有误\n");
		return 0;
	}
	p=FindElem(L,i-1);//删除结点的前一个结点
	q=FindElem(L,i);//要删除的结点
	if(p==NULL) {
		p=*L;
		*L=p->next;
		delete p;
	} else {
		p->next=q->next;
		delete q;
	}

	/*代码补充结束*/
	return 1;
}

int SearchElem(LKList *L,ElemType *e) { /*查找元素*e的位置i*/
	LNode *p=*L;
	int j=0;

	while(p) {
		j++;
		if(p->data==*e)break;
	}
	return p?j:0;
}

int TraversList(LKList *L) { /*遍历线性表*/
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

void ClearList(LKList *L) {  /*清除线性表*/
	LNode *p,*q;
	p=*L;
	while(p) {
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}

/*  以下补充逆序单链表的实现*/
void Reverse(LKList *L) {
    LNode *lp, *rp, *temp1;
    if (*L == NULL )
        return;
    else
    {
        lp = *L;
        rp = lp->next;
        lp->next = NULL;
    }
    while (rp != NULL)
    {
        temp1 = rp->next;
        rp->next = lp;
        lp = rp;
        rp = temp1;
    }
    *L = lp;
}

/*  补充结束 */
