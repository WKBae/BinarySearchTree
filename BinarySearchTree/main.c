/**
 * 2015253065 ���� - �̿�Ž��Ʈ��
 */
#include <stdio.h>
#include "tree.h"

int treeDepth(Ty_Node_Ptr node, int current) {
	if(node) {
		int left = treeDepth(node->leftChild, current + 1);
		int right = treeDepth(node->rightChild, current + 1);
		return left > right? left : right;
	} else {
		return current - 1;
	}
}

int main() {
	FILE* in;
	Ty_Node_Ptr root = NULL;
	char line[100], cmd;

	int key;
	char name[50];

	in = fopen("sdata.txt", "r");
	while(fscanf(in, "%d%s", &key, name) != EOF) {
		treeInsert(&root, key, name);
	}

	while(1) {
		printf("������ �۾���(i, p, d, s, h, b, u, e)? ");
		gets(line);
		if(sscanf(line, "%c", &cmd) == 1) {
			switch(cmd) {
			case 'i':
				if(sscanf(line, "%*c%d%s", &key, name) == 2) {
					if(treeInsert(&root, key, name)) {
						puts("\t�Է� ����!");
					}
				} else {
					puts("\t<����> i �й� �̸�");
				}
				break;
			case 'p':
				inOrderTraversal(root);
				break;
			case 'd':
				if(sscanf(line, "%*c%s", name) == 1) {
					if(treeDelete(&root, name)) {
						puts("\t�����Ǿ����ϴ�.");
					}
				} else {
					puts("\t<����> d �̸�");
				}
				break;
			case 's':
				if(sscanf(line, "%*c%s", name) == 1) {
					Ty_Node_Search search = treeSearch(root, name);
					if(search.node) {
						printf("\t�̸�: %s, �й�: %d, ������ġ = %d\n", search.node->name, search.node->key, search.level);
					} else {
						puts("\t��带 ã�� �� �����ϴ�.");
					}
				} else {
					puts("\t<����> s �̸�");
				}
				break;
			case 'h':
				printf("\t�� BST�� ���� = %d\n", treeDepth(root, 1));
				break;
			case 'b':
				if(sscanf(line, "%*c%s", name) == 1) {
					Ty_Node_Search search = treeSearch(root, name);
					if(search.node && search.parent) {
						if(search.node == search.parent->leftChild && search.parent->rightChild) {
							printf("\t%s�� ���� ������ %s\n", search.node->name, search.parent->rightChild->name);
						} else if(search.node == search.parent->rightChild && search.parent->leftChild) {
							printf("\t%s�� ���� ������ %s\n", search.node->name, search.parent->leftChild->name);
						} else {
							printf("\t%s�� ���� ��尡 �����ϴ�.\n", search.node->name);
						}
					} else if(!search.parent) {
						printf("\t%s�� ���� ��尡 �����ϴ�. �� ���� ��Ʈ ����Դϴ�.\n", search.node->name);
					} else {
						puts("\t��带 ã�� �� �����ϴ�.");
					}
				} else {
					puts("\t<����> b �̸�");
				}
				break;
			case 'u':
				if(sscanf(line, "%*c%s", name) == 1) {
					Ty_Node_Search search = treeSearch(root, name);
					if(search.node && search.parent) {
						printf("\t%s�� �θ�) �̸�: %s, �й�: %d, ������ġ = %d\n", search.node->name, search.parent->name, search.parent->key, search.level - 1);
					} else if(!search.parent) {
						printf("\t%s�� �θ� ��尡 �����ϴ�. �� ���� ��Ʈ ����Դϴ�.\n", search.node->name);
					} else {
						puts("\t��带 ã�� �� �����ϴ�.");
					}
				} else {
					puts("\t<����> u �̸�");
				}
				break;
			case 'e':
				puts("�����մϴ�.");
				return 0;
			default:
				puts("\t�߸��� ����Դϴ�.");
				break;
			}
		} else {
			puts("\t�߸��� ����Դϴ�.");

		}
	}
	return 0;
}
