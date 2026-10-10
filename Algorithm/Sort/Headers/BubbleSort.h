#ifndef _BUBBLESORT
#define _BUBBLESORT

void bubbleSort(int A[], int n)
{
  int temp = 0;
  for(int last=n; last>=2; last--)
  {
    for(int i=1; i<=last-1; i++)
    {
      if(A[i] > A[i+1])
      {
        temp = A[i];
        A[i] = A[i+1];
        A[i+1] = temp;
      }
    }
  }
}

#endif