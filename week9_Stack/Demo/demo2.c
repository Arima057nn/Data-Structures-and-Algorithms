#include <stdio.h>
#define Max 50
typedef int Element;
typedef struct StackRec{
  int top;
  Element stronge[Max];
} StackType;
int top;
//Tao mot ngan xep stack
void initialze(StackType *stack){
  stack->top = 0; 
}
//kiem tra xem ngan xep co day hay khong
int isFull(StackType stack){
  return stack.top == Max;
}
//kiem tra xem ngan xep co phan tu nao khong
int isEmpty(StackType stack){
  return stack.top == 0;
}
//Dat phan tu e len cung cua ngan xep
void Push(Element e,StackType *stack){
  if(isFull(*stack)){
    printf("stack overflow");
    return;
  }else{
    stack->stronge[stack->top++] = e;
  }
}
//lay phan tren cung ra khoi ngan xep
Element pop(StackType *stack){
  if(isEmpty(*stack)){
    printf("stack underflow");
    return -999999;
  }else{
    stack->top = stack->top - 1;
    return stack->stronge[stack->top];
  }
}

Element peek(StackType stack){
  if(isEmpty(stack)){
    printf("stack underflow");
    return -999999;
  }else{
    return stack.stronge[--stack.top];
  }
}
int main(){
  int A[6] = {1,2,3,4,5,6};
  int i;
  StackType s;
  initialze(&s);
  for(i = 0;i < 6;i++){
    Push(A[i],&s);
  }
  while(!isEmpty(s)){
    printf("%d\n",pop(&s));
  }
  return 0;
}
