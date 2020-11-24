#include <stdio.h>

#define size 5

void linearSearch(int[], int);

int main()
{
  int arr[size], i, ele;

  printf("Simple Linear Search - Array and function \n");
  printf("Enter %d elements for searching: \n", size);

  for (i = 0; i < size; i++)
  {
    scanf("%d", &arr[i]);
  }

  printf("enter element to search: ");
  scanf("%d", &ele);

  linearSearch(arr, ele);
}

void linearSearch(int arr[], int ele)
{
  int i;

  for (i = 0; i < size; i++)
  {
    if (arr[i] == ele)
    {
      printf("linear search: %d is found at %d \n", ele, i + 1);
      break;
    }
  }

  if (i == size)
  {
    printf("\n search element: %d : not found \n", ele);
  }
}