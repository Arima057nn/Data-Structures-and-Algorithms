#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;
#include "libra.h"
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
  phone ele = inputNode();
  root = makeNewNode(ele);
  displayNode(root);
  printf("\n");
  insertAtHead(inputNode());
  traversingList(root);
  printf("\n");
  insertAfterCurrent(inputNode());
  traversingList(root);
  printf("\n");
  insertBeforeCurrent(inputNode());
  traversingList(root);
  printf("\n");
  delFirstElement();
  traversingList(root);
  printf("\n");
  delLastElement();
  traversingList(root);
  printf("\n");
  insertAtTail(inputNode());
  traversingList();
  printf("\n");
  root = list_reverse(root);
  traversingList();
  printf("\n");
  root = insertAtPosition(inputNode(),1);
  traversingList();
  printf("\n");
  printf("\n");
  return 0;
}
