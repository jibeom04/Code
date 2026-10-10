// selection sort

#include <time.h>

#include "Headers\Util.h"
#include "Headers\SelectionSort.h"
#include "Headers\InsertionSort.h"
#include "Headers\BubbleSort.h"
#include "Headers\MergeSort.h"
#include "Headers\QuickSort.h"
#include "Headers\HeapSort.h"

#define SIZE  101

int main()
{
  int start, end;
  int array[SIZE] = {0, };
  makeRandom(array, SIZE-1);
  start = clock();
  // selectionSort(array, SIZE-1);
  // insertionSort(array, SIZE-1);
  // bubbleSort(array, SIZE-1);
  // mergeSort(array, 1, SIZE-1);
  // quickSort(array, 1, SIZE-1);
  heapSort(array, SIZE-1);
  end = clock();
  printArray(array, SIZE-1);
  printf("MS = %lf\n", (double)(end-start)/CLOCKS_PER_SEC);

  return 0;
}