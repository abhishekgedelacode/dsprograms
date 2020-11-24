#include <stdio.h>

struct node
{
  int info;
  struct node *link;
};

typedef struct node *NODE;

NODE push(NODE top)
{
  NODE NewNode;
  int pushed_item;
  NewNode = (NODE)malloc(sizeof(NODE));

  printf("\n enter info: ");
  scanf("%d", &pushed_item);

  NewNode->info = pushed_item;
  NewNode->link =
}