/* #include <stdio.h>
#include <stdlib.h>
#define MAX_LIST_SIZE 100

typedef int element;
typedef struct {
	element array[MAX_LIST_SIZE];
	int size;
}ArrayListType;
void  error(char* message) {
	fprintf(stderr, "%s\n", message);
}

init(ArrayListType* L) {
	L->size = 0;
}

int is_full(ArrayListType* L) {
	return (L->size == MAX_LIST_SIZE);
}

void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
		for (int i = L->size - 1; i >= pos; i = i - 1) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item; 
		L->size = L->size + 1;
	}
}

void insert_last(ArrayListType* L, element item) {
	if (L->size == MAX_LIST_SIZE) {
		error("����Ʈ �����÷ο�");
	}
	L->array[L->size++] = item;
}

void insert_first(ArrayListType* L, element item) {
	insert(L, 0, item);
}

void clear(ArrayListType* L) {
	init(L);
}

element get_entry(ArrayListType* L, int pos) {
	if (pos > 0 && pos < L->size)
		return L->array[pos];
	else
		error("��ġ ����");
}

int get_length(ArrayListType* L) {
	return L->size;
}

int is_empty(ArrayListType* L) {
	return (L->size == 0);
}
void print_list(ArrayListType* L) {
	int i;
	for (i = 0; i < L->size; i++) {
		printf("%d - > ", L->array[i]);
	}
	printf("NULL\n");
}
element delete(ArrayListType* L, int pos) {
	if (pos < 0 || pos >= L->size)
		error("��ġ ����");
	else {
		element item = L->array[pos];
		for (int i = pos; i < (L->size - 1); i++) {
			L->array[i] = L->array[i + 1];
		}
		L->size = L->size - 1;
		return item;
	}
}

int main() {

	ArrayListType list;

	while (1) {
		printf("\n�޴�: \n");
		printf("1. ����Ʈ�� �߰�\n");
		printf("2. ����Ʈ���� ����\n");
		printf("3. ����Ʈ ���\n");
		printf("0. ���α׷� ����\n");
		scanf_s("%d", &choice);

		switch (choice) {
		case 1:
			if (is_full(&list)) {
				printf("����Ʈ�� �� á���ϴ�. \n");
			else {

			}
			break;
		case 2:
			if (is_empty(&list)) {
				printf("����Ʈ�� ����ֽ��ϴ�.\n");
			else {

			}
			break;
		case 3:
			break;
		case 0:
			printf("���α׷� ����\n");
			return 0;
		default:
			printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���\n");
			}
			}
		}
	}
} */