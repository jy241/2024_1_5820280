/* #include <stdio.h>
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
void print_list(ListNode * tail){
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

int main() {
	ListNode* tail = NULL;

	tail = insert_first(tail, 20);
	tail = insert_first(tail, 10);
	tail = insert_last(tail, 40);
	tail = insert_last(tail, 50);
	print_list(tail);
} */