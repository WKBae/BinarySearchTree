/**
 * 2015253065 ���� - �̿�Ž��Ʈ��
 */
#ifndef TREE_H
#define TREE_H

typedef struct anod * Ty_Node_Ptr;
typedef struct anod { // �� ����� ����
    int key; // �й�
    char name[50];  // �̸�
    Ty_Node_Ptr leftChild, rightChild ; // ����� �ڽĿ� ���� ������
} Ty_Node;

// Ʈ�� Ž�� ����� �����ϴ� ����ü, ã�� ���� �� ����� ����, �׸��� �θ� ��带 �����Ѵ�.
// ��带 ã�� �� ���� ��� node�� NULL�� �Ǹ�, ã�� ��尡 ��Ʈ ����� ��� parent�� NULL�� �ȴ�.
typedef struct node_search {
	Ty_Node_Ptr node, parent;
	int level;
} Ty_Node_Search;

Ty_Node_Search treeSearch(Ty_Node_Ptr tree, char name[50]);
int treeInsert(Ty_Node_Ptr* root, int key, char name[50]);
void inOrderTraversal(Ty_Node_Ptr node);
int treeDelete(Ty_Node_Ptr* root, char name[50]);

#endif
