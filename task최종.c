#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
    element* data;
    int capacity;
    int top;
} StackType;

void init(StackType* sptr, int ofs) {
    sptr->data = (element*)malloc(sizeof(element) * ofs);
    sptr->top = -1;
    sptr->capacity = ofs;
}

int is_full(StackType* sptr) {
    return sptr->top == sptr->capacity - 1;
}

int is_empty(StackType* sptr) {
    return sptr->top == -1;
}

void push(StackType* sptr, element item) {
    if (is_full(sptr)) {
        fprintf(stderr, "Stack is full\n");
        return;
    }
    sptr->data[++(sptr->top)] = item;
}

element pop(StackType* sptr) {
    if (is_empty(sptr)) {
        fprintf(stderr, "Stack is empty\n");
        return -1;
    }
    return sptr->data[(sptr->top)--];
}

int eval(char* expression) {
    StackType s;
    init(&s, MAX_STACK_SIZE);

    int len = strlen(expression);
    for (int i = 0; i < len; i++) {
        char token = expression[i];
        int value;
        if (token == ' ') continue; // 공백은 무시
        if (token == '+' || token == '-' || token == '*' || token == '/') {
            int op2 = pop(&s);
            int op1 = pop(&s);
            switch (token) {
            case '+': push(&s, op1 + op2); break;
            case '-': push(&s, op1 - op2); break;
            case '*': push(&s, op1 * op2); break;
            case '/': push(&s, op1 / op2); break;
            default: break;
            }
        }
        else {
            value = token - '0'; // 문자를 숫자로 변환
            push(&s, value);
        }
    }
    return pop(&s);
}

int main() {
    char expression[MAX_STACK_SIZE * 4]; // Max size of expression considering each element has maximum 3 digits and a space
    int result;

    printf("Enter postfix Expression: ");
    fgets(expression, sizeof(expression), stdin);
    expression[strcspn(expression, "\n")] = '\0'; // Removing newline character

    result = eval(expression);
    printf("계산 결과는 %d\n", result);

    return 0;
}
