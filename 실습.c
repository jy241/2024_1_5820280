#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6 //큐

typedef int element;
typedef struct { //struct 사용하면 학생 수, 이름 등 입력 가능
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s", message);
	exit(1);
}
int is_full(QueueType* q) {
	return (q->front == ((q->rear + 1) % MAX_QUEUE_SIZE));
}
int is_empty(QueueType* q) {
	return(q->front == q->rear);
}
void init_queue(QueueType* q) { //초기화
	q->front = q->rear = 0;
}
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("Queue is full\n");
	}
	else { //책과 다름
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //큐가 가리키고 있는 곳에 + 1, MAX_QUEUE_SIZE로 나누면 원형 큐
		q->data[q->rear] = item;
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("Queue is empty\n");
	}
	else { //뺄 때 프론트 증가시킨 후 반환
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; //안 나누면 선형 큐
		return (q->data[q->front]);
	}
}
void print_queue(QueueType* q) {
	int i;
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("[%2d] %2d, ", i, q->data[i]); //마지막 하나는 추가 안됨. 마지막은 바로 빠지기 때문에
	}
	printf("[%2d] %2d\n", i, q->data[i]); //이렇게 해야 큐가 다 출력됨
}

int main() {
	QueueType q;
	int choice;
	init_queue(&q);

	while (1) {
		printf("1. 큐에 원소를 삽입\n");
		printf("2. 큐에서 원소를 삭제\n");
		printf("3. 큐의 원소를 출력\n");
		printf("4. 종료\n");
		printf("메뉴를 선택하세요: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:  
			 if (!is_full(&q)) {
			int item;
			printf("삽입할 원소를 입력하세요: ");
			scanf_s("%d", &item);
			enqueue(&q, item);
			printf("원소 %d를 큐에 삽입했습니다.\n", item);
		} 
			  else {
			printf("큐가 꽉 찼습니다.\n");
		} 
			break;
		case 2:  if (!is_empty(&q)) {
			printf("삭제된 원소: %d\n", dequeue(&q));
		}
			  else {
			printf("큐가 비어 있습니다.\n");
		}
			break;
		case 3:   printf("큐의 원소: ");
			print_queue(&q);
			break;
		case 4:
			exit(0);
		default:
			printf("잘못된 선택입니다. \n");
		}
		
	}
}