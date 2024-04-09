#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element; // 데이터의 자료형
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void int_stack(StackType* s) {
    s->top = -1;
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1)); // if(top == MAX_STACK_SIZE - 1) return -1;, else return 0;
}

int is_empty(StackType* s) {
    return (s->top == -1); // 위와 같은 문장
}

// push :
void push(StackType* s, element item) {
    if (is_full(s)) {
        printf("Stack is full\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType* s) {
   
    if (is_empty(s)) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}
void print_stack(StackType* s) {
    printf("Current Stack elements: ");
    for (int i = s->top; i >= 0; i--) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}
int main() {
    StackType s;
    int_stack(&s);

    srand(time(NULL)); // 프로그램 전체에서 한 번만 호출

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        int data; 

        if ((rand_num % 2) == 0) { // 짝수
            push(&s, rand_num);
            printf("Random number: %d\n", rand_num);
            printf("Push %d\n", rand_num);
            print_stack(&s);
        }
        else { // 홀수
            data = pop(&s);
            printf("Random number: %d\n", rand_num);
            printf("Pop %d\n", data);
        }

        return 0;
    }
}
