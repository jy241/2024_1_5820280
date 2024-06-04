#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
    element data;
    struct DListNode* llink;
    struct DListNode* rlink;
} DListNode;

// ����Ʈ �ʱ�ȭ �Լ�
void init(DListNode* phead) {
    phead->llink = phead;
    phead->rlink = phead;
}

// ����Ʈ ó���� ��� ���� �Լ�
void insert_first(DListNode* phead, element data) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->llink = phead;
    newNode->rlink = phead->rlink;
    phead->rlink->llink = newNode;
    phead->rlink = newNode;
}

// ����Ʈ �������� ��� ���� �Լ�
void insert_last(DListNode* phead, element data) {
    DListNode* newNode = (DListNode*)malloc(sizeof(DListNode));
    newNode->data = data;
    newNode->rlink = phead;
    newNode->llink = phead->llink;
    phead->llink->rlink = newNode;
    phead->llink = newNode;
}

// ����Ʈ ó�� ��� ���� �Լ�
void delete_first(DListNode* phead) {
    if (phead->rlink == phead) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    DListNode* removedNode = phead->rlink;
    phead->rlink = removedNode->rlink;
    removedNode->rlink->llink = phead;
    free(removedNode);
}

// ����Ʈ ������ ��� ���� �Լ�
void delete_last(DListNode* phead) {
    if (phead->rlink == phead) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return;
    }
    DListNode* removedNode = phead->llink;
    phead->llink = removedNode->llink;
    removedNode->llink->rlink = phead;
    free(removedNode);
}

// ����Ʈ ��� �Լ�
void print_dlist(DListNode* phead) {
    DListNode* p;
    for (p = phead->rlink; p != phead; p = p->rlink) {
        printf(" %d ->", p->data);
    }
    printf(" HEAD\n");
}

int main() {
    DListNode* head = (DListNode*)malloc(sizeof(DListNode));
    init(head); // ��� ��� �ʱ�ȭ
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
        scanf_s("%d", &choice); // ����� �Է�

        switch (choice) {
        case 1:
            printf("�߰��� ���� �Է�: ");
            scanf_s("%d", &data);
            insert_first(head, data);
            break;
        case 2:
            printf("�߰��� ���� �Է�: ");
            scanf_s("%d", &data);
            insert_last(head, data);
            break;
        case 3:
            delete_first(head);
            break;
        case 4:
            delete_last(head);
            break;
        case 5:
            print_dlist(head);
            break;
        case 6:
            printf("���α׷� ����\n");
            return 0;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �Է����ּ���.\n");
        }
    }
    return 0;
}
