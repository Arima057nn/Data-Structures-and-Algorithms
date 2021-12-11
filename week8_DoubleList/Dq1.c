#include <stdio.h>
int displayInt(int n){
  if(n<=50){
    printf("%d\t",n);
    displayInt(n+1);
  }
}
int main(){
  int i = 1;
  displayInt(10);
  
  return 0;
}
