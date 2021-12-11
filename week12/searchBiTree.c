#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phone{
  char name[25];
  char sdt[15];
} phone;
	   
#include "Tree.h"	   
int main(){
  tree T;
  makeNullTree(&T);
  phone a[1];
  FILE *ptr = fopen("grade.dat","rb");
  if(ptr == NULL){
    printf("Cannot open the file\n");
    return 1;
  }
  while(fread(a,sizeof(phone),1,ptr) != 0){
    insertNode(a[0],&T);
  }
  fclose(ptr);
  
  return 0;
}
