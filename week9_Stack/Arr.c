#include "exx1.h"

int main(){
  int i;
  int a[6] = {1,2,3,4,5,6};
  StackType s;
  initialize(s);
  for( i = 0 ; i < 6 ; i++){
    push(a[i],s);
  }
  printf("Pop all element in stack\n");
  while(!isEmpty(s)){
    printf("%4d\n",pop(s));
  }
  return 0;
}
