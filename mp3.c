/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink, * rlink;
} DListNode;

void init(DListNode* phead) {
	phead->llink = phead->rlink = phead;
}

void dinsert(DListNode* before, element data) {

	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));  //<1>
	strcpy newnode->data = data;  // <1>
	newnode->llink = before;  // <2>
	newnode->rlink = before->rlink; // <3>
	//	before->rlink->llink = newnode; // <5>
	//	before->rlink = newnode; // <4>
	before->rlink = newnode; // <4>
	newnode->rlink->llink = newnode; // <5>
}

void print_dlist(DListNode* head, DListNode*current) {
	DListNode* p;
	for (p = head->rlink; p != head; p = p->rlink) {
		printf(" [%s] ", p->data);
		if (p == current) printf("<==== ");
			printf("\n");
	}
	printf("\n");
}

element ddelete(DListNode* head, DListNode* removed) {
	element r;
	if (removed == head) return;
	r = (char*)malloc(sizeof element);
	strcpy (r = removed->data);

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	return r;
}

main()
{
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	dinsert(head, "¹ã¾ç°»");
	dinsert(head, "¿À¸£¸·±æ");
	dinsert(head->rlink->rlink, "³Ê¹« ¾ÆÇÂ »ç¶ûÀº...");
	dinsert(head->llink, "¼­¸¥ÂêÀ½¿¡");
	print_dlist(head);

	element deleted;
	deleted = ddelete(head, head->rlink);
	printf(" Deleted = %s\n", deleted);
	deleted = ddelete(head, head->llink);
	printf(" Deleted = %s\n", deleted);


	print_dlist(head);

} */
