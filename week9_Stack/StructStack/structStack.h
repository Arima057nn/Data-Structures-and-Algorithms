#include <stdio.h>

#define Max 50
typedef struct Value{
  element A[Max];
  int top;
} value;

void initialize(value *stack){
  stack->top = 0;
}
int isEmpty(value stack){
  return stack.top == 0;
}
int isFull(value stack){
  return stack.top == Max;
}
void Push(element e,value *stack){
  if( isFull(*stack) ) printf("Stack overflow");
  else stack->A[stack->top ++] = e;
  // Tuong duong voi stack
  // stack->A[stack->top] = e;
  // stack->top ++
  
}
element Pop(value *stack){
  if( isEmpty(*stack)){
    printf("Stack is empty");
      return -99999;
  }else{
    return stack->A[--stack->top];
  }
}
element Peek(value stack){
  if( isEmpty(stack)){
    printf("Stack is empty");
    return -99999;
  }else{
    return stack.A[stack.top - 1];
  }
}
