#define MAX 100
typedef int element;
#include "Int_ListStack.h"
int main(){
  element c;
  node *top,*undo;
  initialize(&top);
  initialize(&undo);
  int x;
  int choose;
  int i=0,A[MAX];
  A[i] = 0;
  
    printf("---MENU---\n"
	   "1. Add 1 integer to the stack\n"
	   "2. Remove from the stack\n"
	   "3. View top\n"
	   "4. Undo\n"
	   "5. Exit\n");
    do{
      printf("--> Choose: ");
      scanf("%d", &choose);
      if( A[0] == 0 && (choose == 2 || choose == 3)){
	printf("Danh sach trong. Chon 1 de them truoc.\n-->Choose: ");
	scanf("%d",&choose);
      }
      
      if( choose == 4 && A[0] == 0){
	printf("\nKhong co gi de undo\n");
      }
      if(choose == 1){
	A[i] = 1;
	i++;
      }
      if(choose == 2 && A[0] != 0){
	A[i] = 2;
	i++;
      }
      
      switch(choose){
      case 1:
	printf("Input x: ");
	scanf("%d",&x);
	Push(x,&top);
	printf("Complete\n");
	break;
      case 2:
	c = Pop(&top);
	Push(c,&undo);
	printf("Complete\n");
	break;
      case 3:
	printf("top = %d\n",Peek(top));
	printf("Complete\n");
	break;
      case 4:
	if(A[i-1] == 1){
	  Pop(&top);
	  
	}
	if(A[i-1] == 2){
	  c = Pop(&undo);
	  Push(c,&top);
	}
	i = i - 1;
	printf("Complete\n");
	break;
      case 5:
	printf(" Exit !\n");
	break;
      default:
	printf("\nKhong co chuc nang nay. Vui long chon 1-5\n");
	break;
      }
    }while(choose != 5);
    return 0;
}
