/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef int element; //데이터의 자료형
element stack[MAX_STACK_SIZE]; //1차원 배열
int top = -1; //책 참고 (저장?), -1은 비어있다는 초기값 저장

// create : 이미 만들었음
//delete : 할 수 없음

//is_full
int is_full() {
	return(top == (MAX_STACK_SIZE - 1)); //if(top == MAX_STACK_SIZE - 1) return -1;, else return 0;
}

int is_empty() {
	//if (top == -1) return 1;
	//else return;
	return(top == -1); //위와 같은 문장
}

//push : 
void push(element item) {
	if (is_full()){
		printf("Stack is full\n");
		return;
	}
	else {
		top = top + 1; //증가시키고 넣어야함. 뺄 땐 감소시키기
		stack[top] = item; //item 삽입
	}
}

element pop() {
	srand(time(NULL)); //
	element r;
	if (is_empty()) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		//r = stack[top];
		//top = top - 1;
		//return r;
		return (stack[top--]);

	}
}

element peek() {
	element r;
	if (is_empty(r)) {
		fprintf(stderr, "Stack is empty\n");
		exit(1);
	}
	else {
		//r = stack[top];
		//top = top - 1;
		//return r;
		return (stack[top]); //pop의 --만 빼면 됨

	}
}

int main() {
	element e;
	srand(time(NULL));
	e = (rand() % 100) + 1;

	if (e % 2 == 0) {
		push(e);
		printf("Push %d", e);
	}
	else {
		e = pop();
		printf("Pop %d\n", e);
	}
	
} */