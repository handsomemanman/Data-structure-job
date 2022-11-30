#include "BTree.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


void InitBTree(BTreeNode *&BT) {
	/*以下补充代码*/
	BT = NULL;
	/*代码补充完成*/
}

void CreatBTree(BTreeNode *&BT,char *a) {
	const int MaxSize=100;
	BTreeNode *s[MaxSize];
	int top=-1;
	BT = NULL;
	BTreeNode *p;
	int k;
	int i=0;
	/*以下补充代码*/
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

		/*代码补充完成*/
	}
}



bool EmptyBTree(BTreeNode *BT) {
	/*以下补充代码*/
	return BT==NULL;
	/*代码补充完成*/
}


void TraverseBTree(BTreeNode *BT) {
	if(BT!=NULL) {
		/*以下补充代码*/
		cout<<BT->data<<" ";
		TraverseBTree(BT->left);
		TraverseBTree(BT->right);
		/*代码补充完成*/
	}
}



int BTreeDepth(BTreeNode *BT) {
	if(BT==NULL)
		return 0;
	else {
		/*以下补充代码*/
		int depl = BTreeDepth(BT->left);
		int depr = BTreeDepth(BT->right);
		if(depl>depr)
			return depl + 1;
		else
			return depr + 1;
		/*代码补充完成*/
	}
}


//求结点总数；
int BTreeCount(BTreeNode *BT) {
	/*以下补充代码*/
	if(BT==NULL)
		return 0;
	return BTreeCount(BT->left)+BTreeCount(BT->right)+1;

	/*代码补充完成*/
}

void PrintBTree(BTreeNode *BT) {
	/*以下补充代码*/
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


	/*代码补充完成*/
}


int main() {
	BTreeNode *bt;
	InitBTree(bt);

	char b[50]="A(B(C),D(E(F,G),H(,I)))";

	CreatBTree(bt,b);
	PrintBTree(bt);
	cout<<endl;

	cout<<"前序:";
	TraverseBTree(bt);
	cout<<endl;

	cout<<"二叉树的深度为:";
	cout<<BTreeDepth(bt)<<endl;

	cout<<"二叉树的结点总数为:";
	cout<<BTreeCount(bt)<<endl;

	return 0;
}

