#include <stdio.h>
#define Max 50

typedef int EleType;
typedef EleType StackType[Max];
int top
void initialize(StackType stack){ 
  top = 0;
}
int isEmpty(StackType stack){
  return top == 0;
}
int isFull(StackType stack){
  return top == Max;
}
void push(EleType ele,StackType stack){
  if(isFull(stack)){
    printf("stack overflow");
  }
  else{
    stack[top] = ele;
    top++;
  }
  return;
}
EleType pop(StackType stack){
  if(isEmpty(stack)){
    printf("stack underflow");
    return -999999;
  }else{
    top = top - 1;
    return stack[top];
  }
}
//lay gia tri dau tien
EleType peek(StackType stack){
  if(isEmpty(stack)){
    printf("stack underflow");
    return -99999;
  }
  else return stack[top-1];
}
