#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;

#include "doubleList.h"

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
  FILE *ptr;
  phone A[1];
  int i = 0,j,k,n,m;
  int luaChon;
  char s[30],c;
  node *p;
  printf("==================MENU=================\n");
  printf("1.Import from file .dat\n");
  printf("2.Display\n");
  printf("3.Insert new node\n");
  printf("4.Insert At Position\n");
  printf("5.Delete At Position\n");
  printf("6.Delete current\n");
  printf("7.Delete first\n");
  printf("8.Delete last\n");
  printf("9.Search and Update\n");
  printf("10.Reverse List\n");
  printf("11.Save to File\n");
  printf("12.Search and Transpose\n");
  printf("13.Quit\n");
  printf("=============");
  do{
    printf("\n-->Choose? ");
    scanf("%d",&luaChon);
    if(luaChon == 1){
      i=1;
    }
    if((luaChon == 2 ||luaChon == 3 ||luaChon == 4 ||luaChon == 5 ||luaChon == 6 ||luaChon == 7 ||luaChon == 8 ||luaChon == 9 ||luaChon == 10 ||luaChon == 11 ||luaChon == 12) && i == 0 ){
      do{
	printf("Chon 1 de doc du lieu tu file .dat sang danh sach lien ket: ");
	printf("Chon 1: ");
	scanf("%d",&luaChon);
      }while(luaChon != 1 && luaChon != 13);
      i = 1;
    }
    if(luaChon == 1 && i == 1){
      i = 2;
    }
    switch (luaChon){
    case 1:
     
      ptr = fopen("PhoneDB.dat","rb");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      while( fread(A,sizeof(phone),1,ptr) != 0){
	insertAtTail(A[0]);
      }
      printf("\nComplete!\n");
      fclose(ptr);
      break;
    case 2:
      traversingList();
      break;
    case 3:
      printf("\n1.insert after current\n2.insert before current\n3.insertAtHead\n4.insertAtTail");
      do{
	printf("chosse: ");
	scanf("%d",&j);
      }while(j != 1 && j != 2 && j != 3 && j != 4);
      if( j == 1 )
	insertAfterCurrent(inputNode());
      if( j == 2 )
	insertBeforeCurrent(inputNode());
      if( j == 3 )
	insertAtHead(inputNode());
      if( j == 4 )
	insertAtTail(inputNode());
	
      break;
    case 4:
      do{
	printf("Chon vi tri muon chen: ");
	scanf("%d",&k);
      }while(k < 0);
      insertAtPosition(inputNode(),k);
      break;
    case 5:
      do{
	printf("Chon vi tri muon xoa: ");
	scanf("%d",&k);
      }while(k < 0);
      deleteAtPosition(k);
      printf("\ncomplete!\n");
      break;
    case 6: 
      deleteCurrentElement();
      printf("\ncomplete!\n");
      break;
    
    case 7:
      deleteFirstElement();
      printf("\ncomplete!\n");
      break;
    case 8:
      deleteLastElement();
      printf("\ncomplete!\n");
      break;
    case 9:
      k = 0;
      printf("Nhap Model de tim kiem: ");
      c = getchar();
      gets(s);
      p = root;
      while( p != NULL ){
	if( strcmp(p->data.model , s) == 0){
	  printf("\n%-15s %-15d %-20d %-20s\n",p->data.model,p->data.size,p->data.memory,p->data.price);
	  printf("Update the node: \n");
	  p->data = inputNode();
	  k++;
	}
	p = p->next; 
      }
      if(k == 0){
	printf("\nCannot open\n");
      }
      break;
    case 10:
      Reverse_List();
      break;
    case 11:
      p = root;
      ptr = fopen("PhoneDB.dat","w+b");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      while(p != NULL){
	A[0] = p->data;
	fwrite(A,sizeof(phone),1,ptr);
	p = p->next;
      }
      printf("\nComplete!\n");
      fclose(ptr);
      break;
    case 12:
      k = 0;
      printf("Nhap Model de tim kiem: ");
      c = getchar();
      gets(s);
      p = root;
      while( p != NULL ){
	if( strcmp(p->data.model , s) == 0){
	  printf("\n%-15s %-15d %-20d %-20s\n",p->data.model,p->data.size,p->data.memory,p->data.price);	  
	  k = 1;
	  if(k == 1){
	    A[0] = p->data;
	    p->data = p->prev->data;
	    p->prev->data = A[0];
	    printf("\nComplete\n");
	    break;
	  }
	}
	p = p->next; 
      } 
      if(k == 0){
	printf("\nCannot open\n");
	break;
      }
      break;
    case 13:
      printf("\nQuit !");
      break;
    default:
      printf("HAY CHON TU 1 - 13");
      break;
    }
  }while(luaChon != 13);
 
  return 0;
}
