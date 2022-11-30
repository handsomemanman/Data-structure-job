#include "huffman.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

BTreeNode *CreateHuffman(ElemType a[],int n) {
	BTreeNode **b,*q;
	/*���²������*/
	b=new BTreeNode *[n];
	int i,j;
	for(i=0; i<n; i++) {
		b[i]=new BTreeNode;
		b[i]->data=a[i];
		b[i]->left=b[i]->right=NULL;
	}
	for(i=1; i<n; i++) {
		int k1=-1,k2;
		for(j=0; j<n; j++) {
			if(b[j]!=NULL && k1==-1) {
				k1=j;
				continue;
			}
			if(b[j]!=NULL) {
				k2=j;
				break;
			}
		}
		for(j=k2; j<n; j++) {
			if(b[j]!=NULL) {
				if(b[j]->data<b[k1]->data) {
					k2=k1;
					k1=j;
				} else if(b[j]->data<b[k2]->data)
					k2=j;
			}
		}
		q=new BTreeNode;
		q->data=b[k1]->data + b[k2]->data;
		q->left=b[k1];
		q->right=b[k2];
		b[k1]=q;
		b[k2]=NULL;
	}
	delete []b;

	/*���벹�����*/

	return q;
}

ElemType WeightPathLength(BTreeNode *FBT,int len) {
	/*���²������*/
	if(FBT==NULL)
		return 0;
	else {
		if(FBT->left==NULL && FBT->right==NULL) {
			return FBT->data*len;
		} else {
			return WeightPathLength(FBT->left,len+1)+WeightPathLength(FBT->right,len+1);
		}
	}

	/*���벹�����*/

}

void HuffManCoding(BTreeNode *FBT,int len) {
	static int a[10];
	int i;
	/*���²������*/
	if(FBT!=NULL) {
		if(FBT->left==NULL && FBT->right==NULL) {
			cout<<"���ȨֵΪ"<<FBT->data<<"�ı��룺";
			for( i=0; i<len; i++) {
				cout<<a[i]<<" ";
			}
			cout<<endl;
		} else {
			a[len]=0;
			HuffManCoding(FBT->left,len+1);
			a[len]=1;
			HuffManCoding(FBT->right,len+1);
		}
	}

	/*���벹�����*/

}

void PrintBTree(BTreeNode *BT) {
	if(BT!=NULL) {
		cout<<BT->data;
		if(BT->left!=NULL ||BT->right!=NULL) {
			cout<<'(';
			PrintBTree(BT->left);
			if(BT->right!=NULL)
				cout<<',';
			PrintBTree(BT->right);
			cout<<')';
		}
	}
}


int main() {
	int i,n;
	BTreeNode *fbt=NULL;
	n=6;
	ElemType a[6]= {3,9,5,12,6,15};
	fbt=CreateHuffman(a,n);
	cout<<"�Թ�������ʽ�����������:";
	PrintBTree(fbt);
	cout<<endl;

	cout<<"����������Ȩ:";
	cout<<WeightPathLength(fbt,0)<<endl;

	cout<<"����ÿ��Ҷ�ӽ��Ĺ���������:"<<endl;
	HuffManCoding(fbt,0);
	return 0;
}








