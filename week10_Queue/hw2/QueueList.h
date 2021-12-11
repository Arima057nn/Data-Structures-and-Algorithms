#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  element data;
  struct Node *next;
} node;

typedef struct{
  node *Front,*Rear;
} Queue;

node *MakeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->next = NULL;
  new->data = e;
  return new;
}

void makeNullQueue(Queue *Q){
  Q->Front = NULL;
  Q->Rear = NULL;
}

int isEmpty(Queue Q){
  return Q.Front == NULL;
}

void EnQueue(element e, Queue *Q){
  node *new = MakeNewNode(e);
  if(isEmpty(*Q)){
    Q->Rear = new;
    Q->Front = new;
    return;
  }
  Q->Rear->next = new;
  Q->Rear = new;
}

element DeQueue(Queue *Q){
  node *tmp;
  element A;
  if(!isEmpty(*Q)){
    A = Q->Front->data;
    tmp = Q->Front;
    Q->Front = Q->Front->next;
    free(tmp);
    return A;
  }else printf("Queue is empty");
}
