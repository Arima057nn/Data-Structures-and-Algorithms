#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 60
typedef char Eltype;
typedef struct StackRec{
  Eltype storage[Max];
  int top;
} StackType;

void initialize(StackType *stack){
  (*stack).top = 0;
}

int isEmpty(StackType stack){
  return stack.top == 0;
}

int isFull(StackType stack){
  return stack.top == Max;
}

void push(Eltype el, StackType *stack){
  if(isFull(*stack)) printf("stack overflow");
  else (*stack).storage[(*stack).top++] = el;
}

Eltype pop(StackType *stack){
  if(isEmpty(*stack)){
    return 0;
  }
  else return (*stack).storage[--(*stack).top];
}

Eltype peek(StackType stack){
  if(isEmpty(stack)){
    return 0;
  }
  else return stack.storage[stack.top - 1];
}
