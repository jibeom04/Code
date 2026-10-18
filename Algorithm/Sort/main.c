// selection sort

#include <time.h>

#include "Headers\Util.h"
#include "Headers\SelectionSort.h"
#include "Headers\InsertionSort.h"
#include "Headers\BubbleSort.h"
#include "Headers\MergeSort.h"
#include "Headers\QuickSort.h"
#include "Headers\HeapSort.h"
#include "Headers\RadixSort.h"
#include "Headers\CountingSort.h"

int main()
{
  int start, end;
  // int array[SIZE] = {0, };
  // makeRandom(array, SIZE-1);
  // start = clock();
  // selectionSort(array, SIZE-1);
  // insertionSort(array, SIZE-1);
  // bubbleSort(array, SIZE-1);
  // mergeSort(array, 1, SIZE-1);
  // quickSort(array, 1, SIZE-1);
  // heapSort(array, SIZE-1);
  // radixSort(array, SIZE-1, 4);

  int array[MAX_SIZE];
  int sortedArray[MAX_SIZE] = {0, };
  makeRandom(array, MAX_SIZE-1);
  start = clock();
  countingSort(array, sortedArray, MAX_SIZE-1);
  printArray(sortedArray, MAX_SIZE-1);

  // printArray(array, SIZE-1);
  end = clock();
  
  printf("MS = %lf\n", (double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}