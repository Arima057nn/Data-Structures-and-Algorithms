#include <stdio.h>

int main(){
  int num = 0;
  FILE *ifp,*ofp;
  ifp = fopen("exx1.txt","r");
  ofp = fopen("Haiku.txt","w");
  if(ifp == NULL || ofp == NULL){
    printf("cannot open the file");
    return 1;
  } 
  char c[255];
  while( fgets(c,255,ifp) != NULL){
    fputs(c,ofp);
    fputc('\n',ofp);
      num ++;

  }
  fclose(ifp);
  fclose(ofp);
  printf("Complete\n");
  printf("this file has %d lines\n",num);

  return 0;
}
