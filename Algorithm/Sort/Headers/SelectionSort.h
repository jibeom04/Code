#ifndef _SELECTIONSORT
#define _SELECTIONSORT

#include "Util.h"

int theLargest(int A[], int last)
{
  int largest = 1;
  for(int i=2; i<=last; i++)
  {
    if(A[i] > A[largest]) largest = i;
  }
  return largest;
}

void selectionSort(int A[], int n)
{
  int k, temp;
  for(int last=n; last>1; last--)
  {
    k = theLargest(A, last);
    SWAP(A[k], A[last], temp);
  }
}

#endif