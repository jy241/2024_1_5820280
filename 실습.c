/* #include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

//����Ʈ �ʱ�ȭ �Լ�
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

//����Ʈ ��� �Լ�
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf(" %d ->", p->data);
	}
	printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head); //��� ��� �ʱ�ȭ
	int choice, data;

	while (1) {
		printf("\n�޴�\n");
		printf("1. ���� �Է� �޾Ƽ� ����Ʈ ó���� �߰�\n");
		printf("2. ���� �Է� �޾Ƽ� ����Ʈ �������� �߰�\n");
		printf("3. ����Ʈ ó�� ��� ����\n");
		printf("4. ����Ʈ ������ ��� ����\n");
		printf("5. ����Ʈ ����Ʈ\n");
		printf("6. ����\n");
		printf("����: ");
		scanf_s("%d", &choice); //����� �Է�

		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			printf("���α׷� ����\n");
			return 0;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
		}
	}
	return 0;
} */