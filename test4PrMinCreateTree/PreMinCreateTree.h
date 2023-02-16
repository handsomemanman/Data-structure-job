typedef char ElemType;
struct BTreeNode {
	ElemType data;
	BTreeNode *left;
	BTreeNode *right;
};


BTreeNode *PreMinCreateTree(char pre[],char min[],BTreeNode *&p,int i,int j,int len);

int Position(ElemType x, char a[]);

void PrintBTree(BTreeNode *BT);
