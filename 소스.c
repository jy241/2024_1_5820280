/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_full() {
    return (top == (MAX_STACK_SIZE - 1));
}

int is_empty() {
    return (top == -1);
}

void push(element item) {
    if (is_full()) {
        printf("Stack is full\n");
        return;
    }
    else {
        stack[++top] = item;
    }
}

element pop() {
    if (is_empty()) {
        fprintf(stderr, "Stack is empty\n");
        exit(1);
    }
    else {
        return stack[top--];
    }
}

void print_stack() {
    printf("Current Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int rand_num = 0;

    for (int i = 0; i < 30; i++) {
        rand_num = rand() % 100 + 1;
        int data;

        if ((rand_num % 2) == 0) {
            push(rand_num);
            printf("Pushed %d\n", rand_num);
        }
        else {
            data = pop();
            printf("Popped %d\n", data);
        }
        print_stack();
    }

    return 0;
} */
