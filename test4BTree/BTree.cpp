#include "BTree.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


void InitBTree(BTreeNode *&BT) {
	/*���²������*/
	BT = NULL;
	/*���벹�����*/
}

void CreatBTree(BTreeNode *&BT,char *a) {
	const int MaxSize=100;
	BTreeNode *s[MaxSize];
	int top=-1;
	BT = NULL;
	BTreeNode *p;
	int k;
	int i=0;
	/*���²������*/
	while(a[i]!='\0') {
		if(a[i]==' ') {
			i++;
			continue;
		} else if(a[i]=='(') {
			top++;
			s[top]=p;
			k=1;
			i++;
			continue;
		} else if(a[i]==')') {
			top--;
			i++;
			continue;
		} else if(a[i]==',') {
			k=2;
			i++;
			continue;
		} else {
			p=new BTreeNode;
			p->data=a[i];
			p->left=p->right=NULL;
			if(BT==NULL) BT=p;
			else {
				if(k==1)
					s[top]->left=p;
				else if(k==2)
					s[top]->right=p;
			}
			i++;
		}

		/*���벹�����*/
	}
}



bool EmptyBTree(BTreeNode *BT) {
	/*���²������*/
	return BT==NULL;
	/*���벹�����*/
}


void TraverseBTree(BTreeNode *BT) {
	if(BT!=NULL) {
		/*���²������*/
		cout<<BT->data<<" ";
		TraverseBTree(BT->left);
		TraverseBTree(BT->right);
		/*���벹�����*/
	}
}



int BTreeDepth(BTreeNode *BT) {
	if(BT==NULL)
		return 0;
	else {
		/*���²������*/
		int depl = BTreeDepth(BT->left);
		int depr = BTreeDepth(BT->right);
		if(depl>depr)
			return depl + 1;
		else
			return depr + 1;
		/*���벹�����*/
	}
}


//����������
int BTreeCount(BTreeNode *BT) {
	/*���²������*/
	if(BT==NULL)
		return 0;
	return BTreeCount(BT->left)+BTreeCount(BT->right)+1;

	/*���벹�����*/
}

void PrintBTree(BTreeNode *BT) {
	/*���²������*/
	if(BT!=NULL) {
		cout<<BT->data;
		if(BT->left!=NULL||BT->right!=NULL) {
			cout<<'(';
			PrintBTree(BT->left);
			if(BT->right!=NULL) {
				cout<<',';
			}
			PrintBTree(BT->right);
			cout<<')';
		}
	}


	/*���벹�����*/
}


int main() {
	BTreeNode *bt;
	InitBTree(bt);

	char b[50]="A(B(C),D(E(F,G),H(,I)))";

	CreatBTree(bt,b);
	PrintBTree(bt);
	cout<<endl;

	cout<<"ǰ��:";
	TraverseBTree(bt);
	cout<<endl;

	cout<<"�����������Ϊ:";
	cout<<BTreeDepth(bt)<<endl;

	cout<<"�������Ľ������Ϊ:";
	cout<<BTreeCount(bt)<<endl;

	return 0;
}

