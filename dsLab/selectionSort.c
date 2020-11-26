#include <stdio.h>
#define size 5

int main()
{
  int a[size], n, c, d, pos, t;

  printf("enter 5 numbers: ");
  for (c = 0; c < size; c++)
  {
    scanf("%d", &a[c]);
  }

  for (c = 0; c < size - 1; c++)
  {
    pos = c;

    for (d = c + 1; d < size; d++)
    {
      if (a[pos] > a[d])
      {
        pos = d;
      }
    }

    if (pos != c)
    {
      t = a[c];
      a[c] = a[pos];
      a[pos] = t;
    }
  }

  printf("\n sorted array: ");
  for (c = 0; c < size; c++)
  {
    printf("%d \n", a[c]);
  }

  return 0;
}
