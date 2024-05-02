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

// 스택 초기화 함수
void init_stack(Stack* s) {
    s->top = -1;
}

// 스택이 비어있는지 확인하는 함수
int is_empty(Stack* s) {
    return (s->top == -1);
}

// 스택에 데이터를 추가하는 함수
void push(Stack* s, int item) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->data[++(s->top)] = item;
    }
    else {
        fprintf(stderr, "스택이 가득 찼습니다.\n");
        exit(1);
    }
}

// 스택에서 데이터를 꺼내는 함수
int pop(Stack* s) {
    if (!is_empty(s)) {
        return s->data[(s->top)--];
    }
    else {
        fprintf(stderr, "스택이 비어있습니다.\n");
        exit(1);
    }
}

// 큐 초기화 함수
void init_queue(QueueType* q) {
    q->front = q->rear = 0;
}

// 큐가 비어있는지 확인하는 함수
int is_empty_queue(QueueType* q) {
    return (q->front == q->rear);
}

// 큐가 가득 찼는지 확인하는 함수
int is_full(QueueType* q) {
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 큐에 데이터를 추가하는 함수
void enqueue(QueueType* q, int item) {
    if (is_full(q)) {
        fprintf(stderr, "큐가 가득 찼습니다.\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

// 큐에서 데이터를 꺼내는 함수
int dequeue(QueueType* q) {
    if (is_empty_queue(q)) {
        fprintf(stderr, "큐가 비어있습니다.\n");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

// 회문 검사 함수
int is_palindrome(char* str) {
    Stack s;
    QueueType q;
    int len = strlen(str);

    init_stack(&s);
    init_queue(&q);

    // 문자열을 스택과 큐에 각각 저장
    for (int i = 0; i < len; i++) {
        push(&s, str[i]);
        enqueue(&q, str[i]);
    }

    // 스택과 큐에서 문자를 하나씩 꺼내면서 비교
    while (!is_empty(&s) && !is_empty_queue(&q)) {
        if (pop(&s) != dequeue(&q)) {
            return 0; // 회문이 아님
        }
    }

    return 1; // 회문임
}

int main() {
    char str[100];
    int choice;

    while (1) {
        printf("1. 회문 입력\n");
        printf("2. 회문 검사\n");
        printf("3. 종료\n");
        printf("메뉴 선택: ");
        scanf_s("%d", &choice);
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            printf("회문을 입력하세요: ");
            scanf_s("%[^\n]s", str);
            while (getchar() != '\n');
            break;
        case 2:
            if (is_palindrome(str))
                printf("입력한 문자열은 회문입니다.\n");
            else
                printf("입력한 문자열은 회문이 아닙니다.\n");
            break;
        case 3:
            exit(0);
        default:
            printf("잘못된 메뉴 선택\n");
            break;
        }
    }
    return 0;
}
