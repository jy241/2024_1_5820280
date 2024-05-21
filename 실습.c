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
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    newNode->data = value;
    newNode->link = head;
    return newNode;
}

ListNode* insert(ListNode* head, int position, element value, int* steps) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
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
        printf("위치가 리스트의 길이를 초과합니다.\n");
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
        printf("위치가 리스트의 길이를 초과합니다.\n");
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
        printf("메뉴: \n");
        printf("1. 숫자를 위치에 삽입\n");
        printf("2. 위치에서 숫자 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("삽입할 숫자와 위치를 입력하세요 (숫자 위치): ");
            scanf_s("%d %d", &value, &position);
            steps = 0;
            head = insert(head, position, value, &steps);
            printf("노드를 삽입하는데 %d회 링크를 따라 이동했습니다.\n", steps);
            break;
        case 2:
            printf("삭제할 위치를 입력하세요: ");
            scanf_s("%d", &position);
            steps = 0;
            head = delete(head, position, &steps);
            printf("노드를 삭제하는데 %d회 링크를 따라 이동했습니다.\n", steps);
            break;
        case 3:
            print_list(head);
            break;
        case 0:
            exit(0);
        default:
            printf("유효하지 않은 선택입니다!\n");
        }
    }

    return 0;
}
