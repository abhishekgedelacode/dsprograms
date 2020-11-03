#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head;

void beginsert();
void lastinsert();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();

void main()
{
	int choice = 0;

	while (choice != 9)
	{
		printf("\n\n *** MAIN MENU *** \n");
		printf("\n 1.insert in begining  \n 2.insert at end \n 3.insert at random positon \n 4.delete from beg \n 5.delete from last \n 6.delete specified loc \n 7.search \n 8.display \n 9.exit \n");
		printf("enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			beginsert();
			break;
		case 2:
			lastinsert();
			break;
		case 3:
			randominsert();
			break;
		case 4:
			begin_delete();
			break;
		case 5:
			last_delete();
			break;
		case 6:
			random_delete();
			break;
		case 7:
			search();
			break;
		case 8:
			display();
			break;
		case 9:
			exit(0);
		default:
			printf("\n please enter valid choice \n");
		}
	}
}

void beginsert()
{
	struct node *ptr;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node *));

	if (ptr == NULL)
	{
		printf("\n overflow \n");
	}
	else
	{
		printf("\n enter value: "), scanf("%d", &item);
		ptr->data = item;
		ptr->next = head;
		head = ptr;
		printf("\n node inserted beg \n");
	}
}

void lastinsert()
{
	struct node *ptr, *temp;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node *));

	if (ptr == NULL)
	{
		printf("\n overflow \n");
	}
	else
	{
		printf("\n enter value: "), scanf("%d", &item);
		ptr->data = item;

		if (head == NULL)
		{
			ptr->next = NULL;
			head = ptr;
			printf("\n node inserted last \n");
		}
		else
		{
			temp = head;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = ptr;
			ptr->next = NULL;
			printf("\n node inserted last \n");
		}
	}
}

void randominsert()
{
	int i, loc, item;
	struct node *ptr, *temp;
	ptr = (struct node *)malloc(sizeof(struct node *));

	if (ptr == NULL)
	{
		printf("\n overflow \n");
	}
	else
	{
		printf("\n enter value: "), scanf("%d", &item);
		ptr->data = item;
		printf("\n enter the location: "), scanf("%d", &loc);
		temp = head;

		for (i = 0; i < loc; i++)
		{
			temp = temp->next;
			if (temp == NULL)
			{
				printf("\n cannot insert \n");
				return;
			}
		}
		ptr->next = temp->next;
		temp->next = ptr;
		printf("\n node inserted random \n");
	}
}

void begin_delete()
{
	struct node *ptr;

	if (head == NULL)
	{
		printf("\n list empty \n");
	}
	else
	{
		ptr = head;
		head = ptr->next;
		free(ptr);
		printf("\n node deleted from beg \n");
	}
}

void last_delete()
{
	struct node *ptr, *ptr1;

	if (head == NULL)
	{
		printf("\n list is empty \n");
	}
	else if (head->next == NULL)
	{
		head = NULL;
		free(head);
		printf("\n only node of the deleted \n");
	}
	else
	{
		ptr = head;
		while (ptr->next != NULL)
		{
			ptr1 = ptr;
			ptr = ptr->next;
		}
		ptr1->next = NULL;
		free(ptr);
		printf("\n node deleted from last \n");
	}
}

void random_delete()
{
	struct node *ptr, *ptr1;
	int loc, i;

	printf("\n enter the loc of node: "), scanf("%d", &loc);
	ptr = head;

	for (i = 0; i < loc; i++)
	{
		ptr1 = ptr;
		ptr = ptr->next;

		if (ptr == NULL)
		{
			printf("\n cannot delete \n");
			return;
		}
	}
	ptr1->next = ptr->next;
	free(ptr);
	printf("\n node deleted %d", loc + 1);
}

void search()
{
	struct node *ptr;
	int item, flag, i = 0;
	ptr = head;

	if (ptr == NULL)
	{
		printf("\n empty list \n");
	}
	else
	{
		printf("\n enter item to search: ");
		scanf("%d", &item);
		while (ptr != NULL)
		{
			if (ptr->data == item)
			{
				printf("\n item found at location %d", i + 1);
				flag = 0;
			}
			else
			{
				flag = 1;
			}
			i++;
			ptr = ptr->next;
		}
		if (flag == 1)
		{
			printf("\n item not found \n");
		}
	}
}

void display()
{
	struct node *ptr;
	ptr = head;

	if (ptr == NULL)
	{
		printf("\n nothing to print empty \n");
	}
	else
	{
		printf("\n printing values \n");
		while (ptr != NULL)
		{
			printf("\n %d", ptr->data);
			ptr = ptr->next;
		}
	}
}
