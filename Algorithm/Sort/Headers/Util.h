#ifndef _UTIL
#define _UTIL

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE  10001
#define MAX_NUM 10000
#define MAX_SIZE 10001
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

void makeRandom(int array[], int n)
{
  srand(time(NULL));
  for(int i=1; i<=n; i++)
  {
    array[i] = (rand() % 10000)+1;
  }
}

void printArray(int array[], int n)
{
  printf("========== size : %d\n", n);
  for(int i=1; i<=n; i++)
  {
    printf("%4d, ", array[i]);
    if(i%10 == 0) printf("\n");
  }
  printf("\n===============\n");
}

void reverseArray(int A[], int n)
{
  int start = 1;
  int end = n;

  while(start < end)
  {
    int tmp = A[start];
    A[start] = A[end];
    A[end] = tmp;

    start++;
    end--;
  }
}

#endif