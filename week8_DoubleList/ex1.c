#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;

#include "dir.h"
//Ham nhap vao phone
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
void displayNode(node *p){
  if(p == NULL){
    printf("Error Pointer");
  }else{
    printf("%-20s %-20d %-20d %-20s\n",p->data.model,p->data.size,p->data.memory,p->data.price);      
  }  
}


int main(){
  int i,n;
  root = makeNewNode(inputNode());
  displayNode(root);



  return 0;
}

