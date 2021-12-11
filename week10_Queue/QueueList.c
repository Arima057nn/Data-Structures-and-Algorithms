
typedef int element;
#include "QueueList.h"

int main(){
  Queue A;
  makeNullQueue(&A);
  int X[6] = {1,2,3,4,5,6};
  int i;
  for(i = 0;i<6;i++){
    EnQueue(X[i],&A);
  }
  while(!isEmpty(A)){
    printf("%d\t",DeQueue(&A));
  }
  return 0;
}
