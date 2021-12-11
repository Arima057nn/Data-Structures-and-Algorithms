#include <stdio.h>
typedef int ElementType;

#include "QueueArr.h"
int main(){
  Queue A;
  makeNull_Queue(&A);
  int X[6] = {1,2,3,4,5,6};
  int i;
  for(i = 0;i<6;i++){
    Enqueue(X[i],&A);
  }
  while(!Empty_Queue(A)){
    printf("%d\t",Dequeue(&A));
  }
  
  return 0;
}
