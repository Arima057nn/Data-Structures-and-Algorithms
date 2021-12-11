#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;


int main(){
  phone A[1];
  int j = 0;
  FILE *ptr;
  char C;
  ptr = fopen("PhoneDB.dat","w+b");
  if(ptr == NULL){
    printf("Cannot open the file");
    return 1;
  }
  while(j < 10){
    printf("Model: ");
    gets(A[0].model);
    printf("Size: ");
    scanf("%d",&A[0].size);
    printf("Memory: ");
    scanf("%d",&A[0].memory);
    printf("Price: ");
    C = getchar();
    gets(A[0].price);
    fwrite(A,sizeof(phone),1,ptr);
    j++;
  }
  fclose(ptr);
  return 0;
}
