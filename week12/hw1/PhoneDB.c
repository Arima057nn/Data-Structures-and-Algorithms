#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10

typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;

phone inputNode(){
  phone new;
  printf("Model: ");
  scanf("%s",new.model);
  printf("Size: ");
  scanf("%d",&new.size);
  printf("Memory: ");
  scanf("%d",&new.memory);
  printf("Price: ");
  scanf("%s",new.price);
  return new;
}

int main(){
  FILE *ptr = fopen("PhoneDB.txt","w+");
  int i;
  phone A[1];
  if(ptr == NULL){
    printf("Cannot open the file");
    return 1;
  }
  for(i = 0; i<Max ;i++){
    A[0] = inputNode();
    fprintf(ptr,"%-20s %-10d %-10d %-20s\n",A[0].model,A[0].size,A[0].memory,A[0].price);
  }
  fclose(ptr);

  return 0;
}
