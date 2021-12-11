#include <stdio.h>

int TraVeAB(int a,int b){
  if(a == 1)
    return b;
  else
    return (b + TraVeAB(a-1,b));
  
}
int main(){
  printf("%d\n",TraVeAB(3,5));


  return 0;
}
