typedef int ElemType;
struct BTreeNode{
	ElemType data;
	BTreeNode *left;
	BTreeNode *right;
};

BTreeNode *CreateHuffman(ElemType a[],int n);

void HuffManCoding(BTreeNode *FBT,int len);

ElemType WeightPathLength(BTreeNode *FBT,int len);

void PrintBTree(BTreeNode *BT);



