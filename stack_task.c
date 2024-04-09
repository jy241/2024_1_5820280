/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element; //데이터의 자료형
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void int_stack(StackType* s) {
	s->top = -1;
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1)); //if(top == MAX_STACK_SIZE - 1) return -1;, else return 0;
}

int is_empty(StackType *s) {
	//if (top == -1) return 1;
	//else return;
	return(s->top == -1); //위와 같은 문장
}

//push : 
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
	srand(time(NULL)); //
	element r;
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];

	}
}

/* element peek() {
	element r;
	if (is_empty(r)) {
		printf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		//r = stack[top];
		//top = top - 1;
		//return r;
		return (stack[top]); //pop의 --만 빼면 됨

	}
} */
/*
int main() {
	StackType s;
	int_stack(&s);

	srand(time(NULL));
	int rand_num= rand() % 100 + 1;
	int data;

	if ((rand_num%2) == 0) { //짝수
		push(rand_num);
		printf("Push %d", rand_num);
	}
	else { //홀수
		data = pop();
		printf("Pop %d\n", rand_num);
	}
	return 0;
} */