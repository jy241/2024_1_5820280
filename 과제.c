#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 5

struct Stack {
    int* items;
    int top;
    int size;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
    stack->size = 1; // Initial size
    stack->items = (int*)malloc(stack->size * sizeof(int));
}

int isFull(struct Stack* stack) {
    return stack->top == stack->size - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        stack->size *= 2; // Double the size
        stack->items = (int*)realloc(stack->items, stack->size * sizeof(int));
    }
    stack->top++;
    stack->items[stack->top] = value;
    printf("Pushed %d\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    else {
        int popped = stack->items[stack->top];
        stack->top--;
        printf("Popped %d\n", popped);
        return popped;
    }
}

int main() {
    srand(time(NULL));
    struct Stack stack;
    initialize(&stack);

    for (int i = 0; i < 30; i++) {
        int random_number = rand() % 100 + 1;
        if (random_number % 2 == 0) {
            push(&stack, random_number);
        }
        else {
            pop(&stack);
        }
    }

    free(stack.items); // Free dynamically allocated memory
    return 0;
}
