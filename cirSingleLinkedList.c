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
void begin_delete();
void last_delete();
void display();
void search();

void main()
{
  int chioce = 0;

  while (choice != 7)
  {
    printf("\n *** MAIN MENU *** \n");
    printf("\n 1.insert ai beg \n 2.insert at last ");
    printf("\n 3.delete at beg \n 4.delete at last ");
    printf("\n 5.search \n 6.display \n 7.exit ");

    printf("\n enter your chioce: ");
    scanf("%d", &chioce);

    switch (choice)
    {
    case 1:
      beginsert();
      break : case 2 : lastinsert();
      break : case 3 : begin_delete();
      break;
    case 4:
      last_delete();
      break;
    case 5:
      search();
      break;
    case 6:
      display();
      break;
    case 7:
      exit(0);
      break;
    default:
      printf("\n please enter valid choice \n");
    }
  }
}

void beginsert()
{
  struct node *ptr, *temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node));

  if (ptr == NULL)
  {
    printf("\n overflow \n");
  }
  else
  {
    printf("\n enter data: ");
    scanf("%d", &item);

    ptr->data = item;

    if (head == NULL)
    {
      head = ptr;
      ptr->next = head;
    }
    else
    {
      temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      ptr->next = head;
      temp->next = ptr;
      head = ptr;
    }
    printf("\n node inserted \n");
  }
}

void lastinsert()
{
  struct node *ptr, *temp;
  int item;
  ptr = (struct node *)malloc(sizeof(struct node));

  if (ptr == NULL)
  {
    printf("\n overflow \n");
  }
  else
  {
    printf("\n enter data: ");
    scanf("%d", &item);

    ptr->data = item;

    if (head == NULL)
    {
      head = ptr;
      ptr->next = head;
    }
    else
    {
      temp = head;
      while (temp->next != head)
      {
        temp = temp->next;
      }
      temp->next = ptr;
      ptr->next = head;
    }
    printf("\n node inserted \n");
  }
}

void begin_delete()
{
  struct node *ptr;

  if (head == NULL)
  {
    printf("\n underflow \n");
  }
  else if (head->next == head)
  {
    head = NULL;
    free(head);
    printf("\n node deleted \n");
  }
  else
  {
    ptr = head;
    while (ptr->next != head)
    {
      ptr = ptr->next;
    }
    ptr->next = head->next;
    free(head);
    head = ptr->next;
    printf("\n node deleted \n");
  }
}

void last_delete()
{
  struct node *ptr, *preptr;

  if (head == NULL)
  {
    printf("\n underflow \n");
  }
  else if (head->next == head)
  {
    head = NULL;
    free(head);
    printf("\n node deleted \n");
  }
  else
  {
    ptr = head;
    while (ptr->next != head)
    {
      preptr = ptr;
      ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    printf("\n node deleted \n");
  }
}

void search()
{
  struct node *ptr;
  int item, flag = 1, i = 0;
  ptr = head;

  if (ptr == NULL)
  {
    printf("\n empty list \n");
  }
  else
  {
    printf("\n enter item to search: ");
    scanf("%d", &item);

    if (head->data == item)
    {
      printf("\n item found at loc %d \n", i + 1);
      flagg = 0;
    }
    else
    {
      while (ptr->next != head)
      {
        if (ptr->data == item)
        {
          printf("\n item found at loc %d \n", i + 1);
          flag = 0;
          break;
        }
        else
        {
          flag = 1;
        }
        i++;
        ptr = ptr->next;
      }
    }
    if (flag != 0)
    {
      printf("\n item not found \n");
    }
  }
}

void display()
{
  struct node *ptr;
  ptr = head;

  if (had == NULL)
  {
    printf("\n nothing to print \n");
  }
  else
  {
    printf("\n printing values:  \n ");

    while (ptr->next != head)
    {
      printf("%d \n", ptr->data);
      ptr = ptr->next;
    }
    printf("%d \n", ptr->data);
  }
}