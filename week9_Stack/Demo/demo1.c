#include <stdio.h>
#define Max 50
typedef int Element;
typedef Element StackType[Max];
int top;
// Tao mot ngan xep stack
void initialze(StackType stack){
  top = 0;
}
//kiem tra xem stack co phan tu nao khong
int isEmpty(StackType stack){
  return top == 0;
}
//kiem tra xem stack co day khong
int isFull(StackType stack){
  return top == Max;
}
// Dat phan tu e len cung cua ngan xep
void push(Element e,StackType stack){
  if(isFull(stack)){
    printf("stack overflow");
    return ;
  }else{
    stack[top++] = e;
  }
}
// lay phan tu tren cung cua ngan xep
Element pop(StackType stack){
  if(isEmpty(stack)){
    printf("stack underflow");
    return -9999999;
  }else{
    top = top - 1;
    return stack[top];
  }
}
//Xem gia tri cua phan tu dau tien
Element peek(StackType stack){
  if(isEmpty(stack)){
    printf("stack underflow");
    return -9999999;
  }else{
    //top = top - 1;
    return stack[--top];
  }
}

int main(){
  int A[6] = {1,2,3,4,5,6};
  int i;
  StackType s;
  initialze(s);
  // printf("\n%d\n",isFull(s));
  //printf("%d\n",isEmpty(s));
  for(i = 0;i < 6; i++){
    push(A[i], s);
  }
  //while(!isEmpty(s)){
  //printf("%4d\n",pop(s));
  //}
  printf("%d\n",peek(s));
 
  return 0;
}
