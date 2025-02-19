#include <string.h>
#include <stdio.h>
#define Max 50 
typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;
int TraVe(phone x, phone e){
  if( strcmp(x.model,e.model) == 0) return 0;
  else if( strcmp(x.model,e.model) > 0) return 1;
  else return -1;
}
#include "SearchBinaryTree.h"
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
void inorderprintSave(tree T, FILE *fptr){
  if(T != NULL){
    inorderprintSave(T->left,fptr);
    fwrite(&(T->data),sizeof(phone),1,fptr);
    inorderprintSave(T->right,fptr);
  }
}
phone inputNODE(){
  phone new;
  printf("Model: ");
  scanf("%s",new.model);
  new.size = 0;
  new.memory = 0;
  gets(new.price,' ');
  return new;
}
void displayNode(tree T){
  if(T == NULL){
    printf("Error Pointer\n");
  }else{
    printf("%-20s %-20d %-20d %-20s\n",T->data.model,T->data.size,T->data.memory,T->data.price);      
  }  
}


int main(){
  FILE *ptr;
  phone A[1],B[Max];
  int i = 0;
  int luaChon;
  char s[30],c;
  tree T;
  makeNullTree(&T);
  printf("==================MENU=================\n");
  printf("1.Import data from file dat\n");
  printf("2.Import data from file text\n");
  printf("3.Insert\n");
  printf("4.Delete\n");
  printf("5.Search\n");
  printf("6.Update\n");
  printf("7.Display\n");
  printf("8.Save to File\n");
  printf("9.Quit\n");
  printf("=============");
  while(1){
    printf("\n--->Ban chon? ");
    scanf("%d",&luaChon);
    switch (luaChon){
    case 1:
      ptr = fopen("PhoneDB.dat","rb");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      while( fread(A,sizeof(phone),1,ptr) != 0){
	insertNode(A[0],&T);
      }
      printf("\nComplete!\n");
      fclose(ptr);
      break;
    case 2:
      ptr = fopen("PhoneDB.txt","r");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      while(!feof(ptr)){
	fscanf(ptr,"%s%d%d%s%*c",A[0].model,&A[0].size,&A[0].memory,A[0].price);
	insertNode(A[0],&T);
      }
      printf("\ncomplete!\n");
      fclose(ptr);
      break;
    case 3:
      insertNode(inputNode(),&T);
      printf("\ncomplete!\n");
      break;  
    case 4:
      DeleteNode(inputNODE(),&T);
      printf("\ncomplete!\n");
      break;
    case 5:
      A[0] = inputNODE();
      if(Searching(A[0],&T ) == 1){
	printf("Tim thay !\n");
	//printf("%-20s %-20d %-20d %-20s\n",A[0].model,A[0].size,A[0].memory,A[0].price); 
      }
      else printf("Khong tim thay!\n");
      break;
    case 6:
      A[0] = inputNODE();
      if(Searching(A[0],&T ) == 1){
	printf("Tim thay !\n");
	DeleteNode(A[0],&T);
	printf("Update: ");
	insertNode(inputNode(),&T);
      }
      else printf("Khong tim thay!\n");
      
      break;
    case 7: 
      printf("--> Node - Left - Right\n");
      preoderprint(T);
      printf("\n--> Left - Node - Right\n");
      inorderprint(T);
      printf("\ncomplete!\n");
      break;
    case 8:
      ptr = fopen("PhongDB.dat","wb");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      inorderprintSave(T,ptr);
      printf("\ncomplete!\n");
      fclose(ptr);
      break;
      
    case 9:
      printf("Quit !!\n");
      exit(0);
      break;
    default:
      printf("HAY CHON TU 1 - 9");
      break;
    }
  }
  
  return 0;
}
