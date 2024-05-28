#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// ���� ����Ʈ�� ù ��° ��� ����
ListNode* insert_first(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

// ���� ����Ʈ�� ������ ��� ����
ListNode* insert_last(ListNode* head, element data) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

// ���� ����Ʈ�� ù ��° ��� ����
ListNode* delete_first(ListNode* head) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return NULL;
    }
    ListNode* removed = head->link;
    if (head == removed) {
        free(removed);
        return NULL;
    }
    else {
        head->link = removed->link;
        free(removed);
    }
    return head;
}

// ���� ����Ʈ�� ������ ��� ����
ListNode* delete_last(ListNode* head) {
    if (head == NULL) {
        printf("����Ʈ�� ��� �ֽ��ϴ�.\n");
        return NULL;
    }
    ListNode* prev = head;
    ListNode* removed = head->link;
    if (removed == head) {
        free(removed);
        head = NULL;
    }
    else {
        while (removed->link != head->link) {
            prev = removed;
            removed = removed->link;
        }
        prev->link = head->link;
        free(removed);
        head = prev;
    }
    return head;
}

// ���� ����Ʈ ���
void print_list(ListNode* head) {
    if (head == NULL) return; // ����Ʈ�� ��������� �Լ� ����
    ListNode* p = head->link; // p�� ù ��° ���� ����
    do {
        printf("%d -> ", p->data); // p�� ����Ű�� ��� ���
        p = p->link; // p�� ���� ���� �̵�
    } while (p != head); // p�� �ٽ� ù ��° ��带 ����Ű�� ���� ����
    printf("%d (head)\n", p->data);
}

// �޴� ���
void menu() {
    printf("\n�޴�\n");
    printf("1. ����Ʈ ó���� �߰�\n");
    printf("2. ����Ʈ �������� �߰�\n");
    printf("3. ����Ʈ ó�� ��� ����\n");
    printf("4. ����Ʈ ������ ��� ����\n");
    printf("5. ����Ʈ ���\n");
    printf("6. ����\n");
}

int main() {
    ListNode* head = NULL;
    int choice;
    element data;

    while (1) {
        menu();
        printf("�޴��� �����ϼ���: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &data);
            head = insert_first(head, data);
            break;
        case 2:
            printf("�߰��� ���ڸ� �Է��ϼ���: ");
            scanf_s("%d", &data);
            head = insert_last(head, data);
            break;
        case 3:
            head = delete_first(head);
            break;
        case 4:
            head = delete_last(head);
            break;
        case 5:
            print_list(head);
            break;
        case 6:
            printf("���α׷��� �����մϴ�.\n");
            exit(0);
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �����ϼ���.\n");
            break;
        }
    }
    return 0;
}