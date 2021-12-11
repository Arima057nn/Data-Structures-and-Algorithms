typedef int element;

#include "structStack.h"
int main(){
  value STACK;
  initialize(&STACK);
  int i, X[10] = {1,2,3,4,5,6,7,8,9,0};
  for(i = 0; i < 10;i++){
    Push(X[i],&STACK);
  }
  while(!isEmpty(STACK)){
    printf("%d\t",Pop(&STACK));
  }
  

  return 0;
}
