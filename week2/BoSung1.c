#include <stdio.h>

int main(int n,char *m[]){
  if(n != 3){
    printf("wrong syntax");
    return 1;
  }
  FILE *fptr;
  fptr = fopen(m[1],"r");
  if(fptr == NULL){
    printf("Cannot open file");
    return 1;
  }
  

  return 0;
}
