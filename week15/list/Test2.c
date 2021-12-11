#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 100
typedef struct phoneDB{
  int maSP;
  char ten[20];
  int gia;
  int soluong;
} phone;
#include "dirr.h"
void displayNode(node *p){
  if(p == NULL){
    printf("Error Pointer");
  }else{
    printf("%-20d %-20s %-20d %-20d\n",p->data.maSP,p->data.ten,p->data.gia,p->data.soluong);      
  }  
}
int main(){
  FILE *ptr;
  phone A[10],B[1];
  int i = 0,j,n;
  int sum = 0;
  int luaChon;
  char s[30],c;
  node *p;
  printf("==================MENU=================\n");
  printf("1.Nhap thong tin san pham va luu vao file text\n");
  printf("2.doc tu file text do va in ra \n");
  printf("3.Sap xep theo gia san pham\n");
  printf("4.Tong so tien co trong cua hang\n");
  printf("5.\n");
  printf("6.Thoat\n");
  
  printf("=============");
   
    while(1){
      printf("\nBan chon? ");
      scanf("%d",&luaChon);
      switch (luaChon){
      case 1:
	ptr = fopen("sanpham.txt","w");
	 if(ptr == NULL){
	   printf("cannot open the file");
	   return 1;
	   }
	while(1){
	  printf("Nhap thong tin nguoi dung: \n");
	  do{ 
	    printf("Ma san pham: ");
	    scanf("%d",&A[i].maSP);
	  }while(A[i].maSP < 0);
	  if(A[i].maSP == 0) break;
	  printf("Ten san pham: ");
	  c = getchar();
	  gets(A[i].ten);

	  do{
	    printf("Gia: ");
	    scanf("%d",&A[i].gia);
	  }while(A[i].gia < 0);
	  do{
	    printf("So luong: ");
	    scanf("%d",&A[i].soluong);
	  }while(A[i].soluong < 0);
	   fprintf(ptr,"%d %s %d %d\n",A[i].maSP,A[i].ten,A[i].gia,A[i].soluong);
	   i++;
	}
	 fclose(ptr);
	break;
      case 2:
	ptr = fopen("sanpham.txt","r");
	if(ptr == NULL){
	  printf("cannot open the file");
	  return 1;
	}
	while( fscanf(ptr, "%d%s%d%d%*c", &B[0].maSP, B[0].ten, &B[0].gia, &B[0].soluong)
 == 4){
	  insertAtTail(B[0]);
	}
	traversingList();
	printf("\nComplete!\n");
	fclose(ptr);
	//traversingList();
	break;

      case 3:
	
	break;
      case 4:
	p = root;
	while(p != NULL){
	  sum += p->data.gia * p->data.soluong;
	  p = p->next;
	}
	printf("\nTong so tien cac sap pham co trong cua hang: %d",sum);
	break;
      case 5:

	break;
      case 6:
	
	printf("exit!!");
	exit(0);
      default:
	printf("Khong co");
	break;
      }
    }
    return 0;
}

