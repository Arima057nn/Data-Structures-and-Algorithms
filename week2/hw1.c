#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int n,char *m[]){
  float a,b,c,delta;
  if(n != 4){
    printf("khong hop le");
    return 1;
  }
  a = atof(m[1]);
  b = atof(m[2]);
  c = atof(m[3]);
  delta = b*b - 4*a*c;
  if(a == 0){
    if(b == 0 && c != 0)
      printf("PT vo nghiem");
    else if(b == 0 && c == 0)
      printf("PT vo so nghiem");
    else printf("phuong trinh co nghiem: %f", (-c/b));
  }
 
  else{
    if(delta < 0)
      printf("PT vo nghiem");
    else if(delta == 0)
      printf("PT co nghiem kep bang: %f",(-b / 2*a));
    else
      printf("x1=%.2f\nx2=%.2f\n",(-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
    }


  return 0;
}
