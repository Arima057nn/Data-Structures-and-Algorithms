typedef int element;
#include "ListStack.h"

int main(){
  node *STACK;
  initialize(&STACK);
  int A[10] = {0,1,2,3,4,5,6,7,8,0};
  int i;
  for(i = 0;i<10;i++){
    Push(A[i],&STACK);
  }
  while(!isEmpty(STACK)){
    printf("%d\t\n",Pop(&STACK));
  }
  return 0;
}
