#include "Tree.h"

int main(){
  int i;
  tree Tree;
  int A[10] = {1,2,3,4,5,6,7,8,9,10};
  makeNullTree(&Tree);
  for(i = 0; i < 10; i++){
    insertNode(A[i],&Tree);
  }
  printf("\n");
  inorderprint(Tree);
  return 0;
}
