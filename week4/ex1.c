#incl2ude <stdio.h>
#include <stdlib.h>

int main(){
  int i,n,*p;
  printf("how many number do you want to enter");
  scanf("%d",&n);

  p = (int*)malloc(n * sizeof(int));
  if( p =NULL){
    printf("Memory allocation failed");
    return 1;
  }
  int A[100];
  for(i = 0 ; i < n; i++){
    printf("Nhap A[%d]: ",i);
    scanf("%d",&A[i]);

  }
  for(i = n-1; i>=0; i--){
    printf("A[%d]: %d ",i,A[i]);

  }
  free(p);


  return 0;
}
