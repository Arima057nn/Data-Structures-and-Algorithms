#include <stdio.h>

int sum(int n){
  if(n == 1)
    return 1;
  else return sum(n-1) +n;
}
int main(){
  int S = sum(10);
  printf("%d\n",S);


  return 0;
}
