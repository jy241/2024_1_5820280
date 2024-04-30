/* #include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5 //큐

typedef int element;
typedef struct { //struct 사용하면 학생 수, 이름 등 입력 가능
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void error(char* message) {
	fprintf(stderr, "%s", message);
	return -1; //exit(1);
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

main() {
	QueueType queue; //crate
	element e;
	init_queue(&queue); //큐에 대한 위치 넘겨주기, 초기화

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	enqueue(&queue, 4); print_queue(&queue);
	enqueue(&queue, 5); print_queue(&queue);
	enqueue(&queue, 6); print_queue(&queue); //4개 넣으면 full
	e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
} */