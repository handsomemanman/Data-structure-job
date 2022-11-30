typedef char ElemType;
struct BTreeNode {
	ElemType data;
	BTreeNode *left;
	BTreeNode *right;
};

void InitBTree(BTreeNode *&BT);

void CreatBTree(BTreeNode *&BT,char *a);

bool EmptyBTree(BTreeNode *BT);

void TraverseBTree(BTreeNode *BT);

int BTreeDepth(BTreeNode *BT);

int BTreeCount(BTreeNode &BT);

void PrintBTree(BTreeNode *BT);
