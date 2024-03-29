#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // 노드 타입
	element data;
	struct ListNode* link;
} ListNode;
void print_list(ListNode* head) // 틀림(수정해야)
{
	ListNode* p;
	if (head == NULL) return;

	if (head->link == head)
		printf("%d->", head->data);
	else {
		p = head->link;
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p != head);
		printf("%d->", p->data); // 마지막 노드 출력
	}
	printf("리스트의 끝");
	printf("\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}

	return head;
}// 변경된 헤드 포인터를 반환한다. }
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}

	return head;
}// 변경된 헤드 포인터를 반환한다. }
ListNode* delete_first(ListNode* head)
{
	ListNode* temp;

	if (head == NULL) {
		printf("리스트가 비어 삭제를 못함\n");
		return NULL;
	}
	else if (head == head->link) { // 즉 하나의 노드가 남았을때
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* temp;
	ListNode* p;
	ListNode* q;

	temp = head;

	if (head == NULL)
		head = NULL;
	else if (temp->link = head)
	{
		free(temp);
		head = NULL;
	}

	temp = temp->link;

	do {
        
		p = temp;
		temp = temp->link;
		
	} while (temp != head);
	
	p->link = head->link;
	head = p;
	free(temp);

	return head;
}

int get_size(ListNode* head)
{
	int total = 0;

	ListNode* p;

	p = head;

	if (p == NULL)
		total = 0;
	else if (p->link == head)
		total = 1;
	else
	{
		p = head->link; //처음을 가르키게 하는 포인터임 
		
		do {
			total++;
			p = p->link;
		} while (p != head);

		total++;
	
	}
	return total;

}

ListNode* search(ListNode* head, element data)
{
	ListNode* p;

	if (head == NULL)
		return NULL;
	if (head->data == data)
		return head;
	else
	{
		p = head->link;
		do {
			if (p->data == data)
				return p;
			p = p->link;
		} while (p != head);
		if (p->data == data)
			return p;
	}
	return NULL;
}

// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;
	ListNode* p;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);

	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);

	
	head = delete_last(head);
	print_list(head);
	
	printf("길이는 %d\n", get_size(head));

	
	p = search(head, 30);
	if (p != NULL)
		printf("%d", p->data);
	else
		printf("원하시는 data가 없습니다\n");
		
	

}