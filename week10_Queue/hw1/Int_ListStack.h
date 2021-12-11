#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
  element data;
  struct Node *next;
} node;

node *makeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->next = NULL;
  new->data = e;
  return new;
}

void initialize(node **stack){
  *stack = NULL;
}

int isEmpty(node *stack){
  return stack == NULL;
}

void Push(element e,node **stack){
  node *new = makeNewNode(e);
  if(*stack == NULL){
    *stack = new;
  }else{
    new->next = *stack;
    *stack = new;
  }
}

element Pop(node **stack){
  element A;
  node *tmp;
  if( isEmpty(*stack)){
    printf("Stack is empty\n");
    return -99999;
  }else{
    A = (*stack)->data;
    tmp = *stack;
    *stack = (*stack)->next;
    free(tmp);
    return A;
  }
}
element Peek(node *stack){
  if( isEmpty(stack)){
    printf("Stack is empty\n");
      return -99999;
  }else{
    return stack->data;
  }
}
