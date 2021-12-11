#include <stdio.h>

int main(int n,char *m[]){
  if(n != 4){
    printf("wrong syntax");
    return 1;
  }
  FILE *fp1,*fp2,*fp3;
  fp1 = fopen(m[1],"r");
  fp2 = fopen(m[2],"r");
  fp3 = fopen(m[3],"w");
  char a[255], b[255];
  if(fp1 == NULL || fp2 == NULL || fp3 == NULL){
    printf("cannot open the file");
    return 1;
  }
  while( (fgets(a,255,fp1) != NULL) && (fgets(b,255,fp2) != NULL)){
    fputs(a,fp3);
    fputs(b,fp3);
    

    
}
  if(a != NULL){
    fputs(a,fp3);
  }
  if(b != NULL){
    fputs(b,fp3);
  }
  while( fgets(a,255,fp1) != NULL){
    fputs(a,fp3);
  }
  while( fgets(b,255,fp1) != NULL){
    fputs(b,fp3);
  }


  return 0;
}
