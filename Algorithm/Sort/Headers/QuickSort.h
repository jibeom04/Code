#ifndef _QUICKSORT
#define _QUICKSORT

#include "Util.h"

int partition(int A[], int p, int r)
{
  int x = A[r];
  int i = p-1;
  int temp;
  for(int j=p; j<=r-1; j++)
    if(A[j]<=x) SWAP(A[++i], A[j], temp);
  SWAP(A[i+1], A[r], temp);
  
  return i+1;
}

void quickSort(int A[], int  p, int r)
{
  if(p < r)
  {
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

#endif