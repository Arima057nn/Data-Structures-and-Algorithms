#include <stdio.h>


int main(int a,char *n[]){
  if(a != 3){
    printf("wrong syntax");
    return 1;
  }
  FILE *fp1,*fp2;
  char A[100];
  fp1 = fopen(n[1],"r");
  fp2 = fopen(n[2],"w");

  if(fp1 == NULL){
    printf("khong ton tai");
    return 1;
  }
  if(fp2 == NULL){
    printf("khong ton tai");
    return 1;
  }
  while( fgets(A,100,fp1) != NULL){
    fputs(A,fp2);
  }
  printf("complete");
  fclose(fp1);
  fclose(fp2);

  return 0;
}
