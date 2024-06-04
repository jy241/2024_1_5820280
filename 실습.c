/* #include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

//리스트 초기화 함수
void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

//리스트 출력 함수
void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		printf(" %d ->", p->data);
	}
	printf("\n");
}

int main() {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head); //헤드 노드 초기화
	int choice, data;

	while (1) {
		printf("\n메뉴\n");
		printf("1. 숫자 입력 받아서 리스트 처음에 추가\n");
		printf("2. 숫자 입력 받아서 리스트 마지막에 추가\n");
		printf("3. 리스트 처음 노드 삭제\n");
		printf("4. 리스트 마지막 노드 삭제\n");
		printf("5. 리스트 프린트\n");
		printf("6. 종료\n");
		printf("선택: ");
		scanf_s("%d", &choice); //사용자 입력

		switch (choice) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			printf("프로그램 종료\n");
			return 0;
		default:
			printf("잘못된 선택입니다. 다시 입력해주세요.\n");
		}
	}
	return 0;
} */