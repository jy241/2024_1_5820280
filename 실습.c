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
        fprintf(stderr, "�޸� �Ҵ� ����\n");
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
        printf("�̹� �����ϴ� �����Դϴ�.\n");
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
        printf("�ش� ������ �����ϴ�.\n");
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
        printf("�޴�:\n");
        printf("1. ����Ʈ�� �� �������� ���ο� ���� �߰�\n");
        printf("2. ����Ʈ�� �ִ� ������ ����\n");
        printf("3. ������ ���� ��� ���\n");
        printf("4. ����\n");
        printf("����: ");
        scanf_s("%d", &choice);
        getchar(); // ���� ���ڸ� �����ϱ� ���� ���

        switch (choice) {
        case 1:
            printf("�߰��� ���� �̸�: ");
            scanf_s("%49s", fruit, sizeof(fruit));
            append(&fruitList, fruit);
            break;
        case 2:
            printf("������ ���� �̸�: ");
            scanf_s("%49s", fruit, sizeof(fruit));
            deleteNode(&fruitList, fruit, &deletedList);
            break;
        case 3:
            printf("������ ���� ���: ");
            printList(deletedList.head);
            break;
        case 4:
            printf("���α׷��� �����մϴ�.\n");
            break;
        default:
            printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    } while (choice != 4);

    // �޸� ����
    freeList(fruitList.head);
    freeList(deletedList.head);

    return 0;
}
