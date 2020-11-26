#include <stdio.h>
#define size 5

int main()
{
  int i, j, temp, a[5];

  printf("enter %d elemets: ", size);
  for (i = 0; i < size; i++)
  {
    scanf("%d", &a[i]);
  }

  for (i = 1; i < size; i++)
  {
    temp = a[i];
    j = i - 1;

    while ((temp < a[j]) && (j >= 0))
    {
      a[j + 1] = a[j];
      j = j - 1;
    }
    a[j + 1] = temp;
  }
  printf("sorted array: ");
  for (i = 0; i < size; i++)
  {
    printf("%d \n", a[i]);
  }

  return 0;
}