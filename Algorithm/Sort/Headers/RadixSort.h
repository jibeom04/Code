#ifndef _RADIXSORT
#define _RADIXSORT

#include "Queue.h"

void initBuckets(QUEUE q[], int k)
{
  for(int i=0; i<k; i++) initQueue(&q[i]);
}

void sorting(int A[], int n, int k)
{
  QUEUE buckets[10];
  int j = 1;
  int position;
  initBuckets(buckets, 10);
  for(int i=1; i<=n; i++)
  {
    position = (A[i]/(int)pow(10, k-1)) % 10;
    enQueue(&buckets[position], A[i]);
  }
  for(int i=0; i<10; i++)
  {
    int num;
    while((num=deQueue(&buckets[i])) != -1) A[j++] = num;
  }
}

void radixSort(int A[], int n, int k)
{
  for(int i=1; i<=k; i++) sorting(A, n, i);
}

#endif