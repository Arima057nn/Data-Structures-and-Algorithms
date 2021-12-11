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

/*phone fscanfNode(FILE *ptr){
  phone A;
  fscanf("%*c%s%d%d%s%*c",A.model,&A.size,&A.memory,A.price);
  return A;

  }*/
int main(){
  FILE *ptr;
  phone A[1];
  int i = 0,j,k,n,m;
  int luaChon;
  char s[30],c;
  node *p;
  do{
    printf("==================MENU=================\n");
    printf("1.Import from file .dat\n");
    printf("2.Display\n");
    printf("3.Insert new node\n");
    printf("4.Insert At Position\n");
    printf("5.Delete At Position\n");
    printf("6.Delete current\n");
    printf("7.Delete first\n");
    printf("8.Search and Update\n");
    printf("9.\n");
    printf("10.Reverse List\n");
    printf("11.Save to File\n");
    printf("12.Quit\n");
    printf("=============");
    printf("\nBan chon? ");
    scanf("%d",&luaChon);
    if(luaChon == 1){
      i=1;
    }
    if((luaChon == 2 ||luaChon == 3 ||luaChon == 4 ||luaChon == 5 ||luaChon == 6 ||luaChon == 7 ||luaChon == 8 ||luaChon == 9 ||luaChon == 10 ||luaChon == 11) && i == 0 ){
      do{
	printf("Chon 1 de doc du lieu tu file .dat sang danh sach lien ket: ");
	printf("Chon 1: ");
	scanf("%d",&luaChon);
      }while(luaChon != 1 && luaChon != 12);
      i = 1;
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
      traversingList(root);
      break;
    case 3:
      printf("\n1.insert after current\n2.insert before current\n");
      do{
	printf("chosse: ");
	scanf("%d",&j);
      }while(j != 1 && j != 2);
      if( j == 1 ){
	insertAfterCurrent(inputNode());
      }
      if( j == 2 ){
	insertBeforeCurrent(inputNode());
      }
      break;
    case 4:
      insertAtPosition(inputNode(),3);
      break;
    case 5:
      delAtPosition(3);
      
      break;
    case 6: 
      delCurrentElement();
      break;
    
    case 7:
      delFirstElement();
      
      break;
    case 8:
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
    case 9:
      printf("Input position and number of node");
      scanf("%d%d",&n,&m);
      p = root;
      
      break;
    case 10:
      root = list_reverse(root);
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
      printf("Quit !!\n");
	 
      break;
    default:
      printf("HAY CHON TU 1 - 12");
      break;
    }
  }while(luaChon != 12);
  
   return 0;
}
