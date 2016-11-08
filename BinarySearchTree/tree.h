/**
 * 2015253065 배경민 - 이원탐색트리
 */
#ifndef TREE_H
#define TREE_H

typedef struct anod * Ty_Node_Ptr;
typedef struct anod { // 한 노드의 구조
    int key; // 학번
    char name[50];  // 이름
    Ty_Node_Ptr leftChild, rightChild ; // 노드의 자식에 대한 포인터
} Ty_Node;

// 트리 탐색 결과를 저장하는 구조체, 찾은 노드와 그 노드의 레벨, 그리고 부모 노드를 포함한다.
// 노드를 찾을 수 없을 경우 node는 NULL이 되며, 찾은 노드가 루트 노드인 경우 parent가 NULL이 된다.
typedef struct node_search {
	Ty_Node_Ptr node, parent;
	int level;
} Ty_Node_Search;

Ty_Node_Search treeSearch(Ty_Node_Ptr tree, char name[50]);
int treeInsert(Ty_Node_Ptr* root, int key, char name[50]);
void inOrderTraversal(Ty_Node_Ptr node);
int treeDelete(Ty_Node_Ptr* root, char name[50]);

#endif
