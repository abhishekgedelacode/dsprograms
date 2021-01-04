#include <stdio.h>
#define max 100

int push(int *s, int top, int ele)
{
  int i;
  if (top >= max)
  {
    printf("\n overflow\n");
  }
  else
  {
    s[++top] = ele;
  }
  return top;
}

int pop(int *a, int *top)
{
  if ((*top) >= 0)
  {
    (*top) = (*top) - 1;
    return a[(*top) + 1];
  }
  else
  {
    printf("\n underflow\n");
    return 0;
  }
}

void main()
{
  int n, i, ans = 1, TOP = -1, s[max];

  printf("\n enter number: ");
  scanf("%d", &n);

  if (n < 0)
  {
    printf("\n fact cannot be calculated\n");
  }
  else if (n == 0)
  {
    printf("\n factorial of 0 : 1\n");
  }
  else
  {
    for (i = n; i > 0; i--)
    {
      TOP = push(s, TOP, i);
    }

    while (TOP >= 0)
    {
      ans = ans * pop(s, &TOP);
    }

    printf("\n factorial of %d : %d\n", n, ans);
  }
}