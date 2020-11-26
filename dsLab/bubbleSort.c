#include <stdio.h>

int main()
{
  int i, j, temp, arr[5];

  printf("enter elements: \n");
  for (i = 0; i < 5; i++)
  {
    scanf("%d", &arr[i]);
  }

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < 4 - i; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  printf("\n array after sort: ");
  for (i = 0; i < 5; i++)
    printf("%d ", arr[i]);

  printf("\n");

  return 0;
}