//책보고 다시 해보기
/* #include <stdio.h>
#define MAX_LIST_SIZE 100

typedef int element; //항목 정의
typedef struct {
	element array[MAX_LIST_SIZE]; //배열 정의
	int size; //현재 리스트에 저장된 항목들의 개수
}ArrayListType;

void init(ArrayListType* L) { //초기화
	L->size = 0;
}
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
int is_empty(ArrayListType* L) {
	return L->size == 0;
}
int is_full(ArrayListType* L) {
	return L->size == MAX_LIST_SIZE;
}

void insert(ArrayListType* L, int pos, element item) {
	if (!is_full(L) && pos >= 0 && (pos <= L->size)) {
		for (int i = (L->size - 1); i > pos; i--) {
			L->array[i + 1] = L->array[i];
		}
		L->array[pos] = item; //중요
		L->size++;
	}
}
void insert_last(ArrayListType* L, element item) {
	if (L->size >= MAX_LIST_SIZE) {
		error("list overflow");
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
		error("위치 오류");
}
int get_length(ArrayListType* L) {
	return L->size;
}

void print_list(ArrayListType* L) {
	printf("[List]");
	for (int i = 0; i < L->size; i++)
		printf("<%2d>", L->array[i]);
	printf("\n");
}
element delete(ArrayListType* L, int pos) {
	element item;
	if (pos < 0 || pos >= L->size) {
		error("위치 오류");
	}
	item = L->array[pos];
	for (int i = pos; i < (L->size - 1); i++) {//중요
		L->array[i] = L->array[i + 1]; //중요
	}
	L->size--;
	return item;
}

int main() {
	ArrayListType list;
	init(&list); //초기화

	insert(&list, 0, 10); print_list(&list);
	insert(&list, 0, 20); print_list(&list);
	insert(&list, 0, 30); print_list(&list);
	insert_last(&list, 40); print_list(&list);
	delete(&list, 0); print_list(&list);
	return 0;
} */