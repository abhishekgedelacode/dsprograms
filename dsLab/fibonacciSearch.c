#include <stdio.h>

/* Find min of given number */
int min(int x, int y)
{
  return (x <= y) ? x : y;
}
/* Returns index of x if present,  else returns -1 */
int fibonaccianSearch(int arr[], int x, int n)
{
  /* Initialize fibonacci numbers */
  int fbM2 = 0;          // (m-2)'th Fibonacci number
  int fbM1 = 1;          // (m-1)'th Fibonacci number
  int fbM = fbM2 + fbM1; // m'th Fibonacci
  // Marks the eliminated range from front
  int offset = -1;
  /* fbM is going to store the smallest Fibonacci
       number greater than or equal to n */
  while (fbM < n)
  {
    fbM2 = fbM1;
    fbM1 = fbM;
    fbM = fbM2 + fbM1;
  }
  /* while there are elements to be inspected. Note that
       we compare arr[fibM2] with x. When fbM becomes 1,
       fbM2 becomes 0 */
  while (fbM > 1)
  {
    // Check if fbM2 is a valid location
    int i = min(offset + fbM2, n - 1);
    /* If x is greater than the value at index fbM2,
       cut the subarray array from offset to i */
    if (arr[i] < x)
    {
      fbM = fbM1;
      fbM1 = fbM2;
      fbM2 = fbM - fbM1;
      offset = i;
    }
    /* If x is greater than the value at index fbMm2,
       cut the subarray after i+1  */
    else if (arr[i] > x)
    {
      fbM = fbM2;
      fbM1 = fbM1 - fbM2;
      fbM2 = fbM - fbM1;
    }
    /* element found. return index */
    else
      return i;
  }
  /* comparing the last element with x */
  if (fbM1 && arr[offset + 1] == x)
    return offset + 1;
  /*element not found. return -1 */
  return -1;
}
/* main function */
int main()
{
  int l;
  printf("\nEnter the number of elements in array which should be less than 10");
  scanf("%d", &l);
  int arr[10];
  printf("Enter elements in array");
  for (int i = 0; i < l; i++)
  {
    scanf("%d", &arr[i]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);
  int x;
  printf("\nEnter element to be searched :");
  scanf("%d", &x);
  printf("Found at index: %d \n", fibonaccianSearch(arr, x, n));
  return 0;
}