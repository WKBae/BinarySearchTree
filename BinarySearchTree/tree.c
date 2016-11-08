/**
 * 2015253065 배경민 - 이원탐색트리
 */
#include "tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Ty_Node_Search treeSearch(Ty_Node_Ptr tree, char name[50]) {
	Ty_Node_Ptr parent = NULL;
	Ty_Node_Search res;
	int cmp;
	res.level = 1;

	while(tree) {
		cmp = strcmp(name, tree->name);
		if(cmp == 0) {
			res.node = tree;
			res.parent = parent;
			return res;
		}
		res.level++;
		parent = tree;
		if(cmp < 0) {
			tree = tree->leftChild;
		} else {
			tree = tree->rightChild;
		}
	}

	res.node = tree;
	res.parent = parent;
	return res;
}

int treeInsert(Ty_Node_Ptr* root, int key, char name[50]) {
	Ty_Node_Search search;
	Ty_Node_Ptr node = (Ty_Node_Ptr) malloc(sizeof(Ty_Node));
	node->key = key;
	strcpy(node->name, name);
	node->leftChild = node->rightChild = NULL;

	if(!*root) {
		*root = node;
		return 1;
	} else {
		search = treeSearch(*root, name);
		if(search.node) {
			printf("같은 이름의 노드가 이미 존재합니다: %s\n", name);
			return 0;
		} else {
			if(strcmp(name, search.parent->name) < 0) {
				search.parent->leftChild = node;
			} else {
				search.parent->rightChild = node;
			}
		}
		return 1;
	}
}

void inOrderTraversal(Ty_Node_Ptr node) {
	if(node) {
		inOrderTraversal(node->leftChild);
		
		printf("\t%s, %d\n", node->name, node->key);

		inOrderTraversal(node->rightChild);
	}
}

int treeDelete(Ty_Node_Ptr* root, char name[50]) {
	Ty_Node_Ptr node, parent, curr;
	int cmp;
	Ty_Node_Search search = treeSearch(*root, name);
	node = search.node;
	parent = search.parent;

	if(!node) {
		puts("\t해당 노드가 없습니다.");
		return 0;
	}
	if(node->leftChild && node->rightChild) {
		Ty_Node_Ptr succ = node->rightChild;
		parent = node;
		while(succ->leftChild) {
			parent = succ;
			succ = succ->leftChild;
		}

		node->key = succ->key;
		strcpy(node->name, succ->name);

		node = succ;
	}

	curr = node->leftChild;
	if(!curr)
		curr = node->rightChild;

	if(!parent)
		*root = curr;
	else if(parent->leftChild == node)
		parent->leftChild = curr;
	else
		parent->rightChild = curr;

	free(node);
	return 1;
}
