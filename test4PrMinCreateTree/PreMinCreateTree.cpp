#include "PreMinCreateTree.h"
#include <iostream>
#include <stdlib.h>

using namespace std;
int Position(ElemType x, char a[]) {
	int i;
	for(i=0; i<8; i++)
		if(x==a[i])
			return i;
}

BTreeNode *PreMinCreateTree(char pre[],char min[],BTreeNode *&p,int i,int j,int len) {
	/*以下补充代码*/
	if (len == 0) { // base case
		p = NULL;
		return p;
	}

// Create the root node using the first element in the pre-order traversal sequence
	//p = new BTreeNode {pre[i], NULL, NULL };
	p = new BTreeNode ;
	p->data=pre[i];
	p->left=NULL;
	p->right=NULL;

	// Find the index of the root in the mid-order traversal sequence
	int k=Position(pre[i], min);

	// Recursively create the left and right subtrees
	int left_len = k - j;
	int right_len = len - left_len - 1;
	
	PreMinCreateTree(pre, min, p->left, i + 1, j, left_len);
	PreMinCreateTree(pre, min, p->right, i + 1 + left_len, k + 1, right_len);
	/*代码补充结束*/

	return p;
}




void PrintBTree(BTreeNode *BT) {
	if(BT!=NULL) {
		cout<<BT->data;
		if(BT->left!=NULL||BT->right!=NULL) {
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
	char pre[]= {'a','b','c','d','e','f','g','h'};
	char in[]= {'c','b','d','a','f','e','h','g'};
	BTreeNode *p;
	int prestart=0;
	int preend=7;
	int instart=0;
	int inend=7;
	BTreeNode *bt;
	bt=PreMinCreateTree(pre,in,p,0,0,8);
	PrintBTree(bt);
	cout<<endl;
	return 0;
}


