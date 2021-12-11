#include <stdio.h>
#include <stdlib.h>

typedef struct undo{
  elementType data;
  struct undo *next;
} undo;

undo *makeNewNode2(elementType e){
  undo *new = (undo*)malloc(sizeof(undo));
  new->next = NULL;
  new->data = e;
  return new;
}

void initialize2(undo **STACK){
  *STACK = NULL;
}

int isEmpty2(undo *STACK){
  return STACK == NULL;
}

void Push2(elementType e,undo **STACK){
  undo *new = makeNewNode2(e);
  if(*STACK == NULL){
    *STACK = new;
  }else{
    new->next = *STACK;
    *STACK = new;
  }
}

elementType Pop2(undo **STACK){
  elementType A;
  undo *tmp;
  if( isEmpty2(*STACK)){
    printf("STACK is empty\n");
    return -99999;
  }else{
    A = (*STACK)->data;
    tmp = *STACK;
    *STACK = (*STACK)->next;
    free(tmp);
    return A;
  }
}
elementType Peek2(undo *STACK){
  if( isEmpty2(STACK)){
    printf("STACK is empty\n");
      return -99999;
  }else{
    return STACK->data;
  }
}
