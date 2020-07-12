#include <stdio.h>
#include <stdlib.h>

struct queue{
  int rear;
  int front;
  int size;
  int *Q;
};

void create(struct queue *q, int size)
{
  q->size = size;
  q->front = q->rear = 0;
  q->Q = (int*) malloc(q->size * sizeof(int));
}

void enqueue(struct queue *q,int x)
{
  if(q->rear == q->size-1)
    printf("Queue is full\n");
  else{
    q->rear++;
    q->Q[q->rear] = x;
  }
}

int dequeue(struct queue *q)
{
  int x =-1;
  if(q->rear == q->front)
    printf("Queue is empty\n");
  else{
    q->front++;
    x = q->Q[q->front];
    return x;
  }
}
void Display(struct queue q)
{
  int i = (q.front+1)%q.size;
  while(i!=(q.rear + 1)%q.size){
    printf("%d ",q.Q[i]);
    i = (i+1)%q.size;
  }
  printf("\n");
}

void circular_enqueue(struct queue *q, int x)
{
  if((q->rear+1)%q->size == q->front)
    printf("Queue is full\n");
  else{
    q->rear = (q->rear+1)%q->size;
    q->Q[q->rear] = x;
  }
}

int circular_dequeue(struct queue *q)
{
  int x=-1;
  if(q->rear == q->front)
    printf("Queue is empty\n");
  else{
    q->front = (q->front+1)%q->size;
    x = q->Q[q->front];
  }
  return x;
}
int main()
{
  struct queue q;
  create(&q,5);
  circular_enqueue(&q,10);
  circular_enqueue(&q,20);
  circular_enqueue(&q,30);
  circular_enqueue(&q,40);
  Display(q);
  printf("%d\n",circular_dequeue(&q));
  printf("%d\n",circular_dequeue(&q));
  printf("%d\n",circular_dequeue(&q));
  return 0;
}