#include <stdio.h>


int main(int n, char *m[]){
  if(n != 3){
    printf("Khong hop le");
    return 1;
  }
  int a,i;
  a = atoi(m[2]);
  if(m[1] != NULL){
    for(i=0;i<a;i++){
      printf("%s",m[1]);
    }
  }

  return 0;
}
