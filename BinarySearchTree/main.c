/**
 * 2015253065 배경민 - 이원탐색트리
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
		printf("수행할 작업은(i, p, d, s, h, b, u, e)? ");
		gets(line);
		if(sscanf(line, "%c", &cmd) == 1) {
			switch(cmd) {
			case 'i':
				if(sscanf(line, "%*c%d%s", &key, name) == 2) {
					if(treeInsert(&root, key, name)) {
						puts("\t입력 성공!");
					}
				} else {
					puts("\t<사용법> i 학번 이름");
				}
				break;
			case 'p':
				inOrderTraversal(root);
				break;
			case 'd':
				if(sscanf(line, "%*c%s", name) == 1) {
					if(treeDelete(&root, name)) {
						puts("\t삭제되었습니다.");
					}
				} else {
					puts("\t<사용법> d 이름");
				}
				break;
			case 's':
				if(sscanf(line, "%*c%s", name) == 1) {
					Ty_Node_Search search = treeSearch(root, name);
					if(search.node) {
						printf("\t이름: %s, 학번: %d, 레벨위치 = %d\n", search.node->name, search.node->key, search.level);
					} else {
						puts("\t노드를 찾을 수 없습니다.");
					}
				} else {
					puts("\t<사용법> s 이름");
				}
				break;
			case 'h':
				printf("\t이 BST의 높이 = %d\n", treeDepth(root, 1));
				break;
			case 'b':
				if(sscanf(line, "%*c%s", name) == 1) {
					Ty_Node_Search search = treeSearch(root, name);
					if(search.node && search.parent) {
						if(search.node == search.parent->leftChild && search.parent->rightChild) {
							printf("\t%s의 우측 형제는 %s\n", search.node->name, search.parent->rightChild->name);
						} else if(search.node == search.parent->rightChild && search.parent->leftChild) {
							printf("\t%s의 좌측 형제는 %s\n", search.node->name, search.parent->leftChild->name);
						} else {
							printf("\t%s의 형제 노드가 없습니다.\n", search.node->name);
						}
					} else if(!search.parent) {
						printf("\t%s의 형제 노드가 없습니다. 이 노드는 루트 노드입니다.\n", search.node->name);
					} else {
						puts("\t노드를 찾을 수 없습니다.");
					}
				} else {
					puts("\t<사용법> b 이름");
				}
				break;
			case 'u':
				if(sscanf(line, "%*c%s", name) == 1) {
					Ty_Node_Search search = treeSearch(root, name);
					if(search.node && search.parent) {
						printf("\t%s의 부모) 이름: %s, 학번: %d, 레벨위치 = %d\n", search.node->name, search.parent->name, search.parent->key, search.level - 1);
					} else if(!search.parent) {
						printf("\t%s의 부모 노드가 없습니다. 이 노드는 루트 노드입니다.\n", search.node->name);
					} else {
						puts("\t노드를 찾을 수 없습니다.");
					}
				} else {
					puts("\t<사용법> u 이름");
				}
				break;
			case 'e':
				puts("종료합니다.");
				return 0;
			default:
				puts("\t잘못된 명령입니다.");
				break;
			}
		} else {
			puts("\t잘못된 명령입니다.");

		}
	}
	return 0;
}
