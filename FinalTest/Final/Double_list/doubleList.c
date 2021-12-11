#include <string.h>
#include <stdio.h>
typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;
int compare(phone a,phone b){
  if(strcmp(a.model,b.model) == 0) return 1;
  else return 0;
}

#include "doubleList.h"

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
  node *head,*cur,*tail,*p;
  initialize(&head,&cur,&tail);
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
      free_List(&head,&cur,&tail);
      ptr = fopen("SmartPhone.txt","r");
      if(ptr == NULL){
	printf("Cannot open the file");
	return 1;
      }
      while( fscanf(ptr,"%s%d%d%s%*c\n",A[0].model,&A[0].size,&A[0].memory,A[0].price) == 4){
	insertAtTail(A[0],&head,&cur,&tail);
      }
      fclose(ptr);
      break;
    case 2:
      traversingList1(head,cur,tail);
      break;
    case 3:
      printf("1.Insert At Head\n"
	     "2.Insert At Position\n"
	     "3.Insert At Tail\n"
	     "-->Choose ");
      scanf("%d",&k);
      if(k == 1) insertAtHead(inputNode(),&head,&cur,&tail);
      if(k == 2) insertAtPosition(inputNode(),2,&head,&cur,&tail);
      if(k == 3) insertAtTail(inputNode(),&head,&cur,&tail);
      if(k != 1 && k != 2 && k != 3) printf("Khong co chuc nang nay");
      break;
    case 4:
      printf("1.Delete At Head\n"
	     "2.Delete At Position\n"
	     "3.Delete At Tail\n"
	     "-->Choose ");
      scanf("%d",&k);
      if(k == 1) deleteFirstElement(&head,&cur,&tail);
      if(k == 2) deleteAtPosition(4,&head,&cur,&tail);
      if(k == 3) deleteLastElement(&head,&cur,&tail);
      if(k != 1 && k != 2 && k != 3) printf("Khong co chuc nang nay");
      break;
    case 5:
      printf("Nhap de tim kiem: ");
      c = getchar();
      gets(A[0].model);
      //searching(head,A[0]);
      break;
    case 6:
      sortList(&head);
      break;
    case 7:
      Reverse_List(&head,&cur,&tail);
      break;
    case 8:
      break;
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
    case 9:
      printf("Quit !");
      free_List(&head,&cur,&tail);
      exit(0);
      break;
      
    }
   
  }
  return 0;
}
