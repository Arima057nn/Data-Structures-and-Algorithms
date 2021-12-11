#include <stdio.h>
#define Max 100
typedef struct {
  ElementType Element[Max];
  int Front,Rear;
} Queue;

void makeNull_Queue(Queue *Q){
  Q->Front = -1;
  Q->Rear = -1;
  
}
int Empty_Queue(Queue Q){
  return Q.Front == -1;
}

int Full_Queue(Queue Q){
  return (Q.Rear - Q.Front + 1) % Max == 0;
}

void Enqueue(ElementType X, Queue *Q){
  if( !Full_Queue(*Q)){
    if(Empty_Queue(*Q)){
      Q->Front = 0;
    }
    Q->Rear = (Q->Rear + 1) % Max;
    Q->Element[Q->Rear] = X;
  }else printf("Queue is full");
}

ElementType Dequeue(Queue *Q){
  ElementType e;
  if( !Empty_Queue(*Q)){
    e = Q->Element[Q->Front];
    if(Q->Front == Q->Rear)
      makeNull_Queue(Q);
    else Q->Front = (Q->Front + 1) % Max;
    return e;
  }else printf("Queue is emoty");
}

