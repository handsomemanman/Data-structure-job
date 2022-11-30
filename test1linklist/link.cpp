#include "LINK.H"
/*�����������͵Ĳ���ʵ��*/
void InitList(LKList *L) { /*��ʼ�����Ա�*/
	*L=NULL;
}

void CreateList(LKList *L) { /*�������Ա�*/
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

int GetLength(LKList *L) { /*������Ա�ĳ���*/
	int i=0;
	LKList p=*L;
	while(p) {
		i++;
		p=p->next;
	}
	return i;
}

LKList FindElem(LKList *L,int i) { /*���ҵ�i��Ԫ�صĲ���,��������Ԫ�ص�ַ,�Ҳ������ؿ�*/
	LKList p=*L;
	int j=0;

	/*���²������*/
	if(i>GetLength(L)||i<=0) {
		return NULL;
	}
	if(i>1) {
		for(j=1; j<i; j++) {
			p=p->next;
		}
	}
	/*���벹�����*/
	return p;
}

int GetElem(LKList *L,int i,ElemType *e) { /*ȡ���Ա��i����Ԫ�أ�������eָ��ĵ��ڴ���*/
	LKList p=FindElem(L,i);
	int j=0;

	if(p==NULL)
		return 0;
	*e=p->data;
	return 1;
}

int SetElem(LKList *L,int i,ElemType *e) { /*�޸ĵ�i����Ԫ��*/
	LKList p=FindElem(L,i);
	int j=0;

	if(p) p->data=*e;
	return 1;
}

int InsertElem(LKList *L,int i, ElemType *e) { /*�ڵ�i��λ�ò���Ԫ��*/
	LKList p=FindElem(L,i-1);
	LNode *s;
	/*���������Ľ��*/
	s=(LNode*)malloc(sizeof(LNode));
	s->data=*e;
	s->next=NULL;
	/*���²������*/
	if(i>GetLength(L)+1||i<=0) {
		printf("��������λ������\n");
		return 0;
	}
	if(p==NULL) {
		s->next=*L;
		*L=s;
	} else {
		s->next=p->next;
		p->next=s;
	}

	/*���벹�����*/
	return 1;
}

int DeleteElem(LKList *L,int i) { /*ɾ����i��Ԫ��,�ɹ�,����1*/
	LKList p,q;
	if(*L==NULL)return 0;
	/*���²������*/
	if(i>GetLength(L)||i<=0) {
		printf("����ɾ����λ������\n");
		return 0;
	}
	p=FindElem(L,i-1);//ɾ������ǰһ�����
	q=FindElem(L,i);//Ҫɾ���Ľ��
	if(p==NULL) {
		p=*L;
		*L=p->next;
		delete p;
	} else {
		p->next=q->next;
		delete q;
	}

	/*���벹�����*/
	return 1;
}

int SearchElem(LKList *L,ElemType *e) { /*����Ԫ��*e��λ��i*/
	LNode *p=*L;
	int j=0;

	while(p) {
		j++;
		if(p->data==*e)break;
	}
	return p?j:0;
}

int TraversList(LKList *L) { /*�������Ա�*/
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

void ClearList(LKList *L) {  /*������Ա�*/
	LNode *p,*q;
	p=*L;
	while(p) {
		q=p->next;
		free(p);
		p=q;
	}
	*L=NULL;
}

/*  ���²������������ʵ��*/
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

/*  ������� */
