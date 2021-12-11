#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;
int compare(phone a,phone b){
  if(strcmp(a.model,b.model) > 0) return 1;
  else return 0;
}

#include "final.h"

void displayNode(node *p){
  if(p == NULL){
    printf("Error Pointer");
  }else{
    printf("%-20s %-20d %-20d %-20s\n",p->data.model,p->data.size,p->data.memory,p->data.price);      
  }  
}
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
  FILE *ptr;
  phone A[1];
  node *head,*p;
  initialize(&head);
  //cd  initialize(&p);
  int choose;
  int i,k;
  char s[100],c;
  while(1){
    printf("========MENU=========\n"
	   "1.Import from file text\n"
	   "2.Display\n"
	   "3.Insert\n"
	   "4.Delete\n"
	   "5.Searching\n"
	   "6.Sorting\n"
	   "7.Reverse list\n"
	   ""
	   "8.Save to file\n"
	   "9.Quit\n"
	   ""
	   "---->Choose ");
    scanf("%d",&choose);
    switch(choose){
    case 1:
      ptr = fopen("PhoneDB.txt","r");
      if(ptr == NULL){
	printf("Cannot open the file");
	return 1;
      }
      while( fscanf(ptr,"%s%d%d%s%*c\n",A[0].model,&A[0].size,&A[0].memory,A[0].price) == 4){
	insertAtTail(A[0],&head);
      }
      fclose(ptr);
      break;
    case 2:
      traversingList(head);
      break;
    case 3:
      printf("1.Insert At Head\n"
	     "2.Insert At Position\n"
	     "3.Insert At Tail\n"
	     "-->Choose ");
      scanf("%d",&k);
      if(k == 1) insertAtHead(inputNode(),&head);
      if(k == 2) insertAtPosition(inputNode(),2,&head);
      if(k == 3) insertAtTail(inputNode(),&head);
      if(k != 1 && k != 2 && k != 3) printf("Khong co chuc nang nay");
      break;
    case 4:
      printf("1.Delete At Head\n"
	     "2.Delete At Position\n"
	     "3.Delete At Tail\n"
	     "-->Choose ");
      scanf("%d",&k);
      if(k == 1) delFirstElement(&head);
      if(k == 2) delAtPosition(4,&head);
      if(k == 3) delLastElement(&head);
      if(k != 1 && k != 2 && k != 3) printf("Khong co chuc nang nay");
      break;
    case 5:
      printf("Nhap de tim kiem: ");
      c = getchar();
      gets(A[0].model);
      searching(head,A[0]);
      break;
    case 6:
      sortList(&head);
      break;
    case 7:
      head = list_reverse(&head);
      break;
    case 8:
      p = head;
      ptr = fopen("PhoneDB.txt","w");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      while(p != NULL){
	A[0] = p->data;
	fprintf(ptr,"%s\t%d\t%d\t%s\n",A[0].model,A[0].size,A[0].memory,A[0].price);
	p = p->next;
      }
      printf("\nComplete!\n");
      fclose(ptr);
      break;
    case 9:
      printf("Quit !");
      freeList(&head);
      exit(0);
      break;
      
    }
   
  }
  return 0;
}
