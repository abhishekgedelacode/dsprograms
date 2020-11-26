#include <stdio.h>

int main()
{
  int i, beg, end, mid, ele;
  int arr[5] = {1, 2, 3, 4, 5};

  printf("enter element: "), scanf("%d", &ele);

  beg = 0;
  end = 4;

  while (beg <= end)
  {
    mid = (beg + end) / 2;

    if (arr[mid] == ele)
    {
      printf("%d found at %d\n", ele, mid + 1);
      return 0;
    }
    else if (arr[mid] > ele)
    {
      end = mid - 1;
    }
    else
    {
      beg = mid + 1;
    }
  }

  if (beg > end)
  {
    printf("\n element not found\n");
  }

  return 0;
}