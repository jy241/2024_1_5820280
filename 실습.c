#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element value) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = value;
    newNode->link = head;
    return newNode;
}

ListNode* insert(ListNode* head, int position, element value, int* steps) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "�޸� �Ҵ� ����\n");
        exit(1);
    }
    newNode->data = value;
    newNode->link = NULL;

    if (position == 0) {
        newNode->link = head;
        *steps = 1;
        return newNode;
    }

    ListNode* p = head;
    int i;
    for (i = 0; i < position - 1 && p != NULL; i++) {
        p = p->link;
        (*steps)++;
    }

    if (p == NULL) {
        printf("��ġ�� ����Ʈ�� ���̸� �ʰ��մϴ�.\n");
        free(newNode);
        return head;
    }

    newNode->link = p->link;
    p->link = newNode;
    (*steps)++;
    return head;
}

ListNode* delete_first(ListNode* head, int* steps) {
    if (head == NULL) return NULL;
    ListNode* remove = head;
    head = head->link;
    free(remove);
    *steps = 1;
    return head;
}

ListNode* delete(ListNode* head, int position, int* steps) {
    if (position == 0) {
        return delete_first(head, steps);
    }

    ListNode* p = head;
    int i;
    for (i = 0; i < position - 1 && p != NULL; i++) {
        p = p->link;
        (*steps)++;
    }

    if (p == NULL || p->link == NULL) {
        printf("��ġ�� ����Ʈ�� ���̸� �ʰ��մϴ�.\n");
        return head;
    }

    ListNode* remove = p->link;
    p->link = remove->link;
    free(remove);
    (*steps)++;
    return head;
}

void print_list(ListNode* head) {
    ListNode* p = head;
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->link;
    }
    printf("NULL\n");
}

int main() {
    ListNode* head = NULL;
    int choice, value, position, steps;

    while (1) {
        printf("�޴�: \n");
        printf("1. ���ڸ� ��ġ�� ����\n");
        printf("2. ��ġ���� ���� ����\n");
        printf("3. ����Ʈ ���\n");
        printf("0. ���α׷� ����\n");
        printf("�����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("������ ���ڿ� ��ġ�� �Է��ϼ��� (���� ��ġ): ");
            scanf_s("%d %d", &value, &position);
            steps = 0;
            head = insert(head, position, value, &steps);
            printf("��带 �����ϴµ� %dȸ ��ũ�� ���� �̵��߽��ϴ�.\n", steps);
            break;
        case 2:
            printf("������ ��ġ�� �Է��ϼ���: ");
            scanf_s("%d", &position);
            steps = 0;
            head = delete(head, position, &steps);
            printf("��带 �����ϴµ� %dȸ ��ũ�� ���� �̵��߽��ϴ�.\n", steps);
            break;
        case 3:
            print_list(head);
            break;
        case 0:
            exit(0);
        default:
            printf("��ȿ���� ���� �����Դϴ�!\n");
        }
    }

    return 0;
}
