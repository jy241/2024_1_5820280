/* #include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5 //ť

typedef int element;
typedef struct { //struct ����ϸ� �л� ��, �̸� �� �Է� ����
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
void init_queue(QueueType* q) { //�ʱ�ȭ
	q->front = q->rear = 0;
}
void enqueue(QueueType* q, int item) {
	if (is_full(q)) {
		error("Queue is full\n");
	}
	else { //å�� �ٸ�
		q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //ť�� ����Ű�� �ִ� ���� + 1, MAX_QUEUE_SIZE�� ������ ���� ť
		q->data[q->rear] = item;
	}
}
element dequeue(QueueType* q) {
	if (is_empty(q)) {
		error("Queue is empty\n");
	}
	else { //�� �� ����Ʈ ������Ų �� ��ȯ
		q->front = (q->front + 1) % MAX_QUEUE_SIZE; //�� ������ ���� ť
		return (q->data[q->front]);
	}
}
void print_queue(QueueType* q) {
	int i;
	for (i = (q->front + 1) % MAX_QUEUE_SIZE; i != q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
		printf("[%2d] %2d, ", i, q->data[i]); //������ �ϳ��� �߰� �ȵ�. �������� �ٷ� ������ ������
	}
	printf("[%2d] %2d\n", i, q->data[i]); //�̷��� �ؾ� ť�� �� ��µ�
}

main() {
	QueueType queue; //crate
	element e;
	init_queue(&queue); //ť�� ���� ��ġ �Ѱ��ֱ�, �ʱ�ȭ

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	enqueue(&queue, 4); print_queue(&queue);
	enqueue(&queue, 5); print_queue(&queue);
	enqueue(&queue, 6); print_queue(&queue); //4�� ������ full
	e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
	e = dequeue(&queue); printf("<%2d>", e); print_queue(&queue);
} */