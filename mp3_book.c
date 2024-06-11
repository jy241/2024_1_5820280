#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode { //���߿��� ��� Ÿ��
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

DListNode* current;

//���߿��Ḯ��Ʈ�� �ʱ�ȭ
void init(DListNode* phead) {
	phead->llink = phead;
	phead->llink = phead;
}

//���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main() {
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("��ɾ �Է��Ͻÿ�(<, >, q): ");
		ch = getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
		}
		else if (ch == '>') {
			current = current->rlink;
			if (current == head)
				current = current->rlink;
		}
		print_dlist(head);
		getchar();
	} while (ch != 'q');
	//���� �޸� ���� �ڵ带 ���⿡

}