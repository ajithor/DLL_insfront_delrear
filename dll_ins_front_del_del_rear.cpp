// dll_ins_front_del_rear.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node * rlink, * llink;
};
struct node * display(struct node * head);
struct node * ins_front(struct node * head, int item);
struct node * del_rear(struct node * head);
int main()
{
	int ch, item;
	struct node * head;
	head = (struct node *)malloc(sizeof(node));
	head->info = 10;
	head->rlink = head->llink = NULL;

	printf("Enter Choice\n1 Insert\n2 Dlelete\n3 Display\n4 Exit\n>");
	scanf_s("%d", &ch);
	switch (ch)
	{
	case 1: printf_s("Enter the element : ");
		scanf_s("%d", &item);
		ins_front(head, item);
		break;
	case 2:	del_rear(head);
		break;
	case 3:	display(head);
		break;
	case 4: exit(0);
	}

	return 0;
}

void display(struct node * head)
{
	struct node * temp;
	if (head->rlink == NULL)
		printf_s("Empty list\n");
	else
	{

		temp = head->rlink;
		while (temp != NULL)
		{
			printf_s("%d ", temp->info);
			temp = temp->rlink;
		}
	}
}
struct node * ins_front(struct node * head, int item)
{
	struct node * temp,* cur;
	cur = head->rlink;
	temp = (struct node *) malloc(sizeof(node));
	temp->info = item;
	temp->llink = head;
	cur->llink = temp;
	temp->rlink = cur;
	head->rlink = temp;
	printf_s("Successful");
	return head;
}
struct node * del_rear(struct node * head)
{
	if (head->rlink = NULL)
		printf_s("Empty list.Nothing to delete.\n");
	else
	{
		struct node * temp, *cur;
		temp = head->rlink;
		while (temp->rlink != NULL)
		{
			temp = temp->rlink;
		}
		cur = temp->llink;
		cur->rlink = NULL;
		printf_s("Deleted %d \n", temp->info);
		free(temp);
	}
	return head;
}
