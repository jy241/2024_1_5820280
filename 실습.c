#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 6 //ť

typedef int element;
typedef struct { //struct ����ϸ� �л� ��, �̸� �� �Է� ����
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

int main() {
	QueueType q;
	int choice;
	init_queue(&q);

	while (1) {
		printf("1. ť�� ���Ҹ� ����\n");
		printf("2. ť���� ���Ҹ� ����\n");
		printf("3. ť�� ���Ҹ� ���\n");
		printf("4. ����\n");
		printf("�޴��� �����ϼ���: ");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:  
			 if (!is_full(&q)) {
			int item;
			printf("������ ���Ҹ� �Է��ϼ���: ");
			scanf_s("%d", &item);
			enqueue(&q, item);
			printf("���� %d�� ť�� �����߽��ϴ�.\n", item);
		} 
			  else {
			printf("ť�� �� á���ϴ�.\n");
		} 
			break;
		case 2:  if (!is_empty(&q)) {
			printf("������ ����: %d\n", dequeue(&q));
		}
			  else {
			printf("ť�� ��� �ֽ��ϴ�.\n");
		}
			break;
		case 3:   printf("ť�� ����: ");
			print_queue(&q);
			break;
		case 4:
			exit(0);
		default:
			printf("�߸��� �����Դϴ�. \n");
		}
		
	}
}