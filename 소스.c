#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
    element data[MAX_QUEUE_SIZE];
    int front, rear;
} QueueType;

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

// ���� �ʱ�ȭ �Լ�
void init_stack(Stack* s) {
    s->top = -1;
}

// ������ ����ִ��� Ȯ���ϴ� �Լ�
int is_empty(Stack* s) {
    return (s->top == -1);
}

// ���ÿ� �����͸� �߰��ϴ� �Լ�
void push(Stack* s, int item) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->data[++(s->top)] = item;
    }
    else {
        fprintf(stderr, "������ ���� á���ϴ�.\n");
        exit(1);
    }
}

// ���ÿ��� �����͸� ������ �Լ�
int pop(Stack* s) {
    if (!is_empty(s)) {
        return s->data[(s->top)--];
    }
    else {
        fprintf(stderr, "������ ����ֽ��ϴ�.\n");
        exit(1);
    }
}

// ť �ʱ�ȭ �Լ�
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// ť�� ����ִ��� Ȯ���ϴ� �Լ�
int is_empty_queue(QueueType* q) {
    return (q->front == q->rear);
}

// ť�� ���� á���� Ȯ���ϴ� �Լ�
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ť�� �����͸� �߰��ϴ� �Լ�
void enqueue(QueueType* q, int item) {
    if (is_full(q)) {
        fprintf(stderr, "ť�� ���� á���ϴ�.\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// ť���� �����͸� ������ �Լ�
int dequeue(QueueType* q) {
    if (is_empty_queue(q)) {
        fprintf(stderr, "ť�� ����ֽ��ϴ�.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// ȸ�� �˻� �Լ�
int is_palindrome(char* str) {
    Stack s;
    QueueType q;
    int len = strlen(str);

    init_stack(&s);
    init_queue(&q);

    // ���ڿ��� ���ð� ť�� ���� ����
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
        enqueue(&q, str[i]);
    }

    // ���ð� ť���� ���ڸ� �ϳ��� �����鼭 ��
    while (!is_empty(&s) && !is_empty_queue(&q)) {
        if (pop(&s) != dequeue(&q)) {
            return 0; // ȸ���� �ƴ�
        }
    }

    return 1; // ȸ����
}

int main() {
    char str[100];
    int choice;

    while (1) {
        printf("1. ȸ�� �Է�\n");
        printf("2. ȸ�� �˻�\n");
        printf("3. ����\n");
        printf("�޴� ����: ");
        scanf_s("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printf("ȸ���� �Է��ϼ���: ");
            scanf_s("%[^\n]s", str);
            while (getchar() != '\n');
            break;
        case 2:
            if (is_palindrome(str))
                printf("�Է��� ���ڿ��� ȸ���Դϴ�.\n");
            else
                printf("�Է��� ���ڿ��� ȸ���� �ƴմϴ�.\n");
            break;
        case 3:
            exit(0);
        default:
            printf("�߸��� �޴� ����\n");
            break;
        }
    }
    return 0;
}
