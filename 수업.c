//시험에 나올 수 있음
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


ListNode* insert_first(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data; //<2>
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link; //<3>
		tail->link = node; //<4>

	}
	return tail; //<5>
}
void print_list(ListNode* tail) {
	ListNode* p;

	if (tail == NULL) return;
	p = tail->link;
	do {
		printf("[%2d] ", p->data);
		p = p->link;
	} while (p != tail->link);
}

ListNode* insert_last(ListNode* tail, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (tail == NULL) {
		tail = node;
		node->link = tail;
	}
	else {
		node->link = tail->link;
		tail->link = node;
		tail = node;
	}
	return tail;
}

ListNode delete_first(ListNode* tail_pointer, element* data_pointer) {
	ListNode* first_pointer;

	if (first_pointer == NULL) { //Error
		fprintf(stderr, "No dat to be deleted in delete_first()\n");
		*data_pointer = -1;
		return NULL;
	}
	else {
		first_pointer = tail_pointer->link; //<1>
		tail_pointer->link = first_pointer; //<2>
		*data_pointer = first_pointer->data; //<3> //사용법 인지하기, 중요
		free(first_pointer); //<4>
		if (tail_pointer == first_pointer) {
			return NULL; //<5>
		}
		else {
			return *tail_pointer; //<5>
		}	
	}
}

int main() {
	ListNode* tail = NULL;

	tail = insert_first(tail, 10);
	tail = insert_first(tail, 20);
	tail = insert_last(tail, 30);
	//print_list(fail);

	element poped_data;
	tail = delete_first(tail, &poped_data ); //tail값이 바뀔 수도 있으니 tail = 추가하기?
	if (poped_data != -1) printf("Deleted Data=%d\n", poped_data);
	print_list(tail);
}