#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *ptr;
} * top, *temp, *top1;

int topelement();
void push(int);
void pop();
void empty();
void display();
void elecount();
void create();

int count = 0;

void main()
{
  int data, ch;

  printf("\n 1.push \n 2.pop \n 3.top element \n 4.display \n 5.count \n 6.exit \n");

  create();

  while (1)
  {
    printf("\n enter your choice: ");
    scanf("%d", &ch);

    if (ch == 1)
    {
      printf("enter data: ");
      scanf("%d", &data);

      push(data);
    }
    else if (ch == 2)
    {
      pop();
    }
    else if (ch == 3)
    {
      if (top == NULL)
      {
        printf("\n stack is empty \n ");
      }
      else
      {
        printf("\n top element: %d \n", topelement());
      }
    }
    else if (ch == 4)
    {
      display();
    }
    else if (ch == 5)
    {
      elecount();
    }
    else if (ch == 6)
    {
      exit(0);
    }
    else
    {
      printf("\n invalid choice \n");
    }
  }
}

void create()
{
  top = NULL;
}

void push(int data)
{
  if (top == NULL)
  {
    top = (struct node *)malloc(sizeof(struct node));
    top->ptr = NULL;
    top->data = data;
  }
  else
  {
    temp = (struct node *)malloc(sizeof(struct node));
    temp->ptr = top;
    temp->data = data;
    top = temp;
  }
  count++;
}

void pop()
{
  top1 = top;

  if (top1 == NULL)
  {
    printf("\n stack empty \n");
  }
  else
  {
    top1 = top1->ptr;
    printf("\n popped data: %d \n", top->data);
    free(top);
    top = top1;
    count--;
  }
}

int topelement()
{
  return top->data;
}

void display()
{
  top1 = top;

  if (top1 == NULL)
  {
    printf("\n stack is empty \n");
    return;
  }

  while (top1 != NULL)
  {
    printf(" %d -> ", top1->data);
    top1 = top1->ptr;
  }
}

void elecount()
{
  printf("\n stack size: %d\n", count);
}
