#include "string.h"
#define Max 100
typedef struct{
  char ID[5];
  int size;
} process;
#include "libra.h"
#include "QueueList.h"
process input(){
  process d;
  printf("ID: ");
  scanf("%s%*c",d.ID);
  printf("SIZE: ");
  scanf("%d",&d.size);
  return d;
}
void displayNode(NODE *p){
  if(p == NULL){
    printf("Error Pointer");
  }else{
    printf("%-20s %-20d\n",p->data.ID,p->data.size);      
  }  
}
int main(){
  int choose;
  int i = 0,j,NUMBER, MEMORY,k;
  Queue Q,QQ;
  process d;
  makeNullQueue(&Q);
  makeNullQueue(&QQ);
  int S,Sum = 0;
  NODE *p;
  char c,s[20];
  printf("\n====Congfiguration Input===\n");
  printf("Number of parallel process it can run: ");
  scanf("%d",&NUMBER);
  printf("\nMemory capacity: ");
  scanf("%d",&MEMORY);
  int n = NUMBER;
  while(1){
    printf("\n========MENU========\n"
	   "1. Create new program\n"
	   "2. Kill a program\n"
	   "3. Show the status of running and waiting process\n"
	   "4. Exit\n");
    printf("-->Choose: ");
    scanf("%d",&choose);
    switch(choose){
    case 1:
      d = input();
      S = Sum;
      Sum = Sum + d.size;
      if( Sum <= MEMORY && i < n ){
	insertAtTail(d);
	i++;
      }else{
	EnQueue(d,&Q);
	Sum = S;
      }
      break;
    case 2:
      k = 0;
      printf("Nhap ID de tim kiem: ");
      c = getchar();
      gets(s);
      p = root;
      while( p != NULL ){
	if( strcmp(p->data.ID , s) == 0){
	  Sum = Sum - p->data.size;
	  delCurrentElement();
	  k++;
	  printf("\nSuccees!\n");
	}
	p = p->next;
	
      }
      i = i - 1;
      
      if(k == 0){
	printf("\nCannot find!\n");
	break;
      }
      if( !isEmpty(Q)){
	d = Q.Front->data;
	S = Sum;
	Sum = Sum + d.size;
	if(Sum <= MEMORY){
	  i++;
	  d = DeQueue(&Q);
	  insertAtTail(d);
	}else{
	  Sum = S;
	}
      }
    	
      break;
    case 3:
      printf("\n%-20s %-20s %-20s\n","ID","Memory","Queue");
      traversingList();
      while( !isEmpty(Q)){
	d = DeQueue(&Q);
	printf("%-20s %-20s %-20d\n",d.ID," ",d.size);
	EnQueue(d,&QQ);
      }
      while( !isEmpty(QQ)){
	d = DeQueue(&QQ);
	EnQueue(d,&Q);
      }
      printf("\n-----------Sum = %d, i = %d\n", Sum,i);
      break;
    case 4:
      printf("Exit !");
      exit(0);
      break;
    }
  }
  return 0;
}
