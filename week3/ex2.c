#include <stdio.h>
#include <stdlib.h>

void charReadWrite(FILE *fin,FILE *fout){
  char c[255];
  fin = fopen("exx2a.txt","r");
  fout = fopen("exx2b.txt","w");
  if( fin == NULL || fout == NULL){
    printf("cannot open the file ");
    exit(1);
  }
  while( (fgets(c,255,fin)) != NULL){
    fputs(c,fout);
  }
  fclose(fin);
  fclose(fout);
  printf("Complete\n");
  

}
int main(){
  FILE *fin,*fout;
  charReadWrite(fin,fout);

  return 0;

}
