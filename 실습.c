#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char fruit[50];
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

Node* createNode(const char* fruit) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "메모리 할당 실패\n");
        exit(1);
    }
    strcpy_s(newNode->fruit, sizeof(newNode->fruit), fruit);
    newNode->next = NULL;
    return newNode;
}

int isFruitInList(Node* head, const char* fruit) {
    Node* current = head;
    while (current != NULL) {
        if (strcmp(current->fruit, fruit) == 0) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void append(LinkedList* list, const char* new_fruit) {
    if (isFruitInList(list->head, new_fruit)) {
        printf("이미 존재하는 과일입니다.\n");
        return;
    }

    Node* newNode = createNode(new_fruit);

    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    }
    else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void deleteNode(LinkedList* list, const char* key, LinkedList* deletedList) {
    Node* temp = list->head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->fruit, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("해당 과일이 없습니다.\n");
        return;
    }

    if (prev == NULL) {
        list->head = temp->next;
    }
    else {
        prev->next = temp->next;
    }

    if (temp == list->tail) {
        list->tail = prev;
    }

    temp->next = NULL;
    append(deletedList, temp->fruit);
    free(temp);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%s ", node->fruit);
        node = node->next;
    }
    printf("\n");
}

void freeList(Node* node) {
    Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    LinkedList fruitList = { NULL, NULL };
    LinkedList deletedList = { NULL, NULL };

    const char* initialFruits[] = { "Mango", "Orange", "Apple", "Grape", "Cherry", "Plum", "Guava", "Raspberry", "Banana", "Peach" };
    for (int i = 0; i < 10; i++) {
        append(&fruitList, initialFruits[i]);
    }

    int choice;
    char fruit[50];

    do {
        printf("메뉴:\n");
        printf("1. 리스트의 맨 마지막에 새로운 과일 추가\n");
        printf("2. 리스트에 있는 과일을 삭제\n");
        printf("3. 삭제된 과일 목록 출력\n");
        printf("4. 종료\n");
        printf("선택: ");
        scanf_s("%d", &choice);
        getchar(); // 개행 문자를 제거하기 위해 사용

        switch (choice) {
        case 1:
            printf("추가할 과일 이름: ");
            scanf_s("%49s", fruit, sizeof(fruit));
            append(&fruitList, fruit);
            break;
        case 2:
            printf("삭제할 과일 이름: ");
            scanf_s("%49s", fruit, sizeof(fruit));
            deleteNode(&fruitList, fruit, &deletedList);
            break;
        case 3:
            printf("삭제된 과일 목록: ");
            printList(deletedList.head);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            break;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    } while (choice != 4);

    // 메모리 해제
    freeList(fruitList.head);
    freeList(deletedList.head);

    return 0;
}
