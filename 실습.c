#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

// 원형 리스트의 첫 번째 노드 삽입
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

// 원형 리스트의 마지막 노드 삽입
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

// 원형 리스트의 첫 번째 노드 삭제
ListNode* delete_first(ListNode* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
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

// 원형 리스트의 마지막 노드 삭제
ListNode* delete_last(ListNode* head) {
    if (head == NULL) {
        printf("리스트가 비어 있습니다.\n");
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

// 원형 리스트 출력
void print_list(ListNode* head) {
    if (head == NULL) return; // 리스트가 비어있으면 함수 종료
    ListNode* p = head->link; // p를 첫 번째 노드로 설정
    do {
        printf("%d -> ", p->data); // p가 가리키는 노드 출력
        p = p->link; // p가 다음 노드로 이동
    } while (p != head); // p가 다시 첫 번째 노드를 가리키면 루프 종료
    printf("%d (head)\n", p->data);
}

// 메뉴 출력
void menu() {
    printf("\n메뉴\n");
    printf("1. 리스트 처음에 추가\n");
    printf("2. 리스트 마지막에 추가\n");
    printf("3. 리스트 처음 노드 삭제\n");
    printf("4. 리스트 마지막 노드 삭제\n");
    printf("5. 리스트 출력\n");
    printf("6. 종료\n");
}

int main() {
    ListNode* head = NULL;
    int choice;
    element data;

    while (1) {
        menu();
        printf("메뉴를 선택하세요: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("추가할 숫자를 입력하세요: ");
            scanf_s("%d", &data);
            head = insert_first(head, data);
            break;
        case 2:
            printf("추가할 숫자를 입력하세요: ");
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
            printf("프로그램을 종료합니다.\n");
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 선택하세요.\n");
            break;
        }
    }
    return 0;
}