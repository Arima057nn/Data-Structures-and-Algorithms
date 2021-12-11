#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phone{
  char model[25];
  char size[5];
  char memory[5];
  char price[10];
} phone;

int main(){
  FILE *ptr;
  phone A[1];
  ptr = fopen("SmartPhone.dat","r+b");
  if(ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  while( fread(A,sizeof(phone),1,ptr) != 0){
    printf("%-20s %-15s %-20s %-20s\n",A[0].model,A[0].size,A[0].memory,A[0].price);
  }
  fclose(ptr);
  return 0;
}
