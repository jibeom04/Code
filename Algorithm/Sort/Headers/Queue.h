#ifndef _QUEUE
#define _QUEUE

#include "Util.h"

typedef struct _queue {
  int head;
  int tail;
  int data[SIZE];
} QUEUE;

int isEmptyQueue(QUEUE* q)
{
  if(q->head == q->tail) return -1;
  else return 0;
}

void enQueue(QUEUE* q, int num)
{
  q->data[q->head++] = num;
  q->head = q->head % SIZE;
}

int deQueue(QUEUE* q)
{
  int num;
  if(!isEmptyQueue(q)) num = q->data[q->tail++];
  else return -1;
  q->tail = q->tail % SIZE;
  return num;
}

void initQueue(QUEUE* q)
{
  q->head = q->tail = 0;
  for(int i=0; i<SIZE; i++) q->data[i] = 0;
}

#endif