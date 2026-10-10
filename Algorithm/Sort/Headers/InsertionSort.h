#ifndef _INSERTIONSORT
#define _INSERTIONSORT

void insertionSort(int A[], int n)
{
  int loc = 0;
  for(int i=2; i<=n; i++)
  {
    loc = i - 1;
    int newItem = A[i];
    while(loc>=1 && newItem<A[loc])
    {
      A[loc+1] = A[loc];
      loc--;
    }
    A[loc+1] = newItem;
  }
}

#endif