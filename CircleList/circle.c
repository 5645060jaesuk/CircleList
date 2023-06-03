#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}

ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head->link == head)
	{
		ListNode* head = NULL;
		printf("First node has been deleted\n");
		printf("\n");
		return head;
	}
	else
	{

		removed = head->link;
		head->link = removed->link;
		free(removed);
		printf("First node has been deleted\n");
		printf("\n");
		return head;
	}

}

ListNode* delete_last(ListNode* head)
{
	ListNode* p = head;
	ListNode* removed = head;

	if (head->link == head)
	{
		ListNode* head = NULL;
		free(head);
		return head;
		printf("Last node has been deleted\n");
		printf("\n");

	}
	else
	{

		do {
			p = p->link;
		} while (p->link != removed);

		p->link = head->link;
		head = p;
		free(removed);
		printf("Last node has been deleted\n");
		printf("\n");
		return head;
	}

}

void print_list(ListNode* head)
{
	ListNode* p;

	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head->link);
}


void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}



int main(void)
{
	int n = 0;
	int num = 0;
	ListNode* head = NULL;
	while (1)
	{
		printf("***** MENU *****\n");
		printf("(1) Insert Frist\n");
		printf("(2) Insert last\n");
		printf("(3) Delete First\n");
		printf("(4) Delete Last\n");
		printf("(5) Print List\n");
		printf("(0) exit\n");

		printf("Enter the menu : ");
		scanf_s("%d", &n);
		if (n == 1)
		{
			printf("Input a number : ");
			scanf_s("%d", &num);
			head = insert_first(head, num);
			printf("\n");
		}
		else if (n == 2)
		{
			printf("Input a number : ");
			scanf_s("%d", &num);
			head = insert_last(head, num);
			printf("\n");
		}
		if (n == 3)
		{
			if (head == NULL)
			{
				printf("비어있습니다.\n");
			}
			else
			{
				head = delete_first(head);
			}

		}
		if (n == 4)
		{
			if (head == NULL)
			{
				printf("비어있습니다.\n");
			}
			else
			{
				head = delete_last(head);
			}

		}
		if (n == 5)
		{
			print_list(head);
			printf("\n");
		}
		if (n == 0)
		{
			break;
		}
		;
	}
}