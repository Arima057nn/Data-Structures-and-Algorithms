#include <stdio.h>
#include <stdlib.h>


int main(int n, char *c[]){
  float a,b;
  if(n != 3){
    printf("khong hop li");
    return 1;
  }
  a = atof(c[1]);
  b = atof(c[2]);
  printf("Chu vi: %.2f\nDien tich: %.2f",(a+b)*2,a*b);



  return 0;
}
