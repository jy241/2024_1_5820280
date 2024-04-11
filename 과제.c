#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 5

typedef int element;

typedef struct {
    element* data;
    int capacity;
    int top;
} Stack;

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->data = (element*)malloc(MAX_STACK_SIZE * sizeof(element));
    if (stack->data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    stack->capacity = MAX_STACK_SIZE;
    stack->top = -1;
    return stack;
}

void free_stack(Stack* stack) {
    free(stack->data);
    free(stack);
}

int is_full(Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

int is_empty(Stack* stack) {
    return (stack->top == -1);
}

void push(Stack* stack, element item) {
    if (is_full(stack)) {
        // ½ºÅÃÀÌ °¡µæ Ã¡À» ¶§, capacity¸¦ µÎ ¹è·Î ´Ã¸²
        stack->capacity *= 2;
        stack->data = (element*)realloc(stack->data, stack->capacity * sizeof(element));
        if (stack->data == NULL) {
            fprintf(stderr, "Memory reallocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    stack->data[++(stack->top)] = item;
}

element pop(Stack* stack) {
    if (is_empty(stack)) {
        fprintf(stderr, "Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[(stack->top)--];
}

void print_stack(Stack* stack) {
    printf("Current Stack elements: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Stack* stack = create_stack();

    for (int i = 0; i < 30; i++) {
        int rand_num = rand() % 100 + 1;
        if ((rand_num % 2) == 0) {
            push(stack, rand_num);
            printf("Pushed %d\n", rand_num);
        }
        else {
            element data = pop(stack);
            printf("Popped %d\n", data);
        }
        print_stack(stack);
    }

    free_stack(stack);
    return 0;
}
