#ifndef _COUNTSORT
#define _COUNTSORT

#include "Util.h"

void countingSort(int A[], int B[], int n)
{
  int C[MAX_SIZE] = {0, };
  for(int j=1; j<=n; j++) C[A[j]]++;
  for(int i=2; i<=MAX_NUM; i++) C[i] = C[i] + C[i-1];
  for(int j=n; j>=1; j--)
  {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
}

#endif