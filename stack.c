/* #include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 10

typedef int element; //�������� �ڷ���
element stack[MAX_STACK_SIZE]; //1���� �迭
int top = -1; //å ���� (����?), -1�� ����ִٴ� �ʱⰪ ����

// create : �̹� �������
//delete : �� �� ����

//is_full
int is_full() {
	return(top == (MAX_STACK_SIZE - 1)); //if(top == MAX_STACK_SIZE - 1) return -1;, else return 0;
}

int is_empty() {
	//if (top == -1) return 1;
	//else return;
	return(top == -1); //���� ���� ����
}

//push : 
void push(element item) {
	if (is_full()){
		printf("Stack is full\n");
		return;
	}
	else {
		top = top + 1; //������Ű�� �־����. �� �� ���ҽ�Ű��
		stack[top] = item; //item ����
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
		return (stack[top]); //pop�� --�� ���� ��

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