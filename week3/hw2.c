#include <stdio.h>

int main(int n,char *m[]){
  if(n != 2){
    printf("Error syntax");
    return 1;
  }
  FILE *fptr;
  fptr = fopen(m[1],"r");
  char c[255];
  while( fgets(c,255,(FILE*)fptr) != NULL){
    printf("%s",c);
  }
  return 0;
}
