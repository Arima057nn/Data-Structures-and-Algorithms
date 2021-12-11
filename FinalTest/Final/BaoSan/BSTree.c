#include <string.h>
#include <stdio.h>
#include <string.h>
typedef struct nhatki{
  int ngay,thang,nam;
  char thoiTiet[30];
  float nhietDo;
  char ND[500];
} nhatki;

#include "GenBST.h"
int main(){
  FILE *ptr;
  int a, b;
  int i = 0,j,n,k = 0;
  int luaChon;
  char s[30], c,z[3];
  nhatki A[1],B[1];
  tree found;
  tree T;
  makeNullTree(&found);
  makeNullTree(&T);
  while (1){
    printf("==================MENU=================\n");
    printf( "1.Nap noi dung\n");
    printf("2.In noi dung nhat ki\n");
    printf("3.Them hoac Sua\n");
    printf("4.Viet nhat o dang doan van\n");
    printf("5.In ra nhat ki theo thoi gian ngau nhien\n");
    printf("6.Quit\n");
    printf("=============");
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon){
    case 1:
      ptr = fopen("bao.txt", "r");
      if (ptr == NULL){
	printf("cannot open the file");
	return 1;
    }
      while(fscanf(ptr,"%d%*c%d%*c%d%[^0123456789]%f%[^\n]%*c", &A[0].ngay,&A[0].thang,&A[0].nam, A[0].thoiTiet,&A[0].nhietDo,A[0].ND) == 6){
	insertNode(A[0],&T);
      }
      printf("\ncomplete!\n");
      fclose(ptr);
      break;
    case 2:
      printf("\n--> Left - Node - Right\n");
      InOrderPrint(T);
      printf("\ncomplete!\n");
      break;
    case 3:
      printf("Nhap ngay thang nam :");
      k = 0;
      scanf("%d%d%d",&B[0].ngay,&B[0].thang,&B[0].nam);
      // gets(B[0].ID);
      //B[0].Score = 0;
      SEARCHING(&k,B[0],T);
      if(k == 0){
	printf("Nhap noi dung moi: ");
	c =getchar();
	gets(B[0].thoiTiet);
	printf("Nhiet do:");
	scanf("%f",&B[0].nhietDo);
	printf("Noi dung: ");
	c = getchar();
	gets(B[0].ND);
	insertNode(B[0],&T);
      }
      if(k == 1){
	printf("Tim thay.Ban co muon chinh sua noi dung khong(y/n)");
	c = getchar();
	gets(z);
	if(strcmp(z,"y") == 0){
	  DeleteNode(B[0],&T);
	  printf("Sua lai noi dung:\nThoi tiet: ");
	  c =getchar();
	  gets(B[0].thoiTiet);
	  printf("Nhiet do:");
	  scanf("%f",&B[0].nhietDo);
	  printf("Noi dung: ");
	  c = getchar();
	  gets(B[0].ND);
	  insertNode(B[0],&T);
	}
      }
      if((ptr = fopen("newdiary.txt","w"))==NULL){
	 printf("Cannot create newdiary.txt\n");
	 return 1;
	 }
	 OutPutFile(ptr,T);
	 fclose(ptr);
	 printf("Complete!\n");
      break;
    case 4:
        InOrderPrint2(T);
      break;
   
    case 5:
      
      break;
      
    case 6:
      printf("Quit !!\n");
      freeTree(&T);
      exit(0);
      break;
    default:
      printf("HAY CHON TU 1 - 7");
      break;
    }
  }
  
  return 0;
}
