#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Customer{
    char ID[15];
    char Name[30];
    int money;
    int TP,DT,MM;
} customers;

#include "GenBST.h"
int main(){
  FILE *ptr;
  int luaChon;
  int a,b,c;
  int i,j,k,n;
  char s[30],d;
  customers A[20],B[1];
  tree found;
  tree T;
  makeNullTree(&found);
  makeNullTree(&T);
  printf("==================MENU=================\n");
  printf("1.Import data from file text\n");
  printf("2.Diplay\n");
  printf("3.Search\n");
  printf("4.\n");
  printf("5.\n");
  printf("6.Import to File\n");
  printf("7.Quit\n");
  printf("=============");
  while (1){
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon){
    case 1:
      ptr = fopen("market.txt", "r");
      if (ptr == NULL){
        printf("cannot open the file");
        return 1;
      }
      while (!feof(ptr)){
        fscanf(ptr, "%s%[^-]%*c%d%d%d%*c", A[i].ID, A[i].Name, &a, &b, &c);
        if (a == 0){
          A[i].TP = 0;
        }else A[i].TP = 1;
       if (b == 0){
          A[i].DT = 0;
        }else A[i].DT = 1;
        if (c == 0){
          A[i].MM = 0;
        }else A[i].MM = 1;
        A[i].money = a + b + c;
	i = i + 1;
      }
      n = i - 1;
      for(i = 0; i < n-1 ; i++){
	for(j = i + 1; j < n; j++){
	  if(strcmp(A[i].ID , A[j].ID) == 0){
	    strcpy(A[j].ID, "00");
	    A[i].money += A[j].money;
        A[i].TP += A[j].TP;
        A[i].DT += A[j].DT;
        A[i].MM += A[j].MM;
	  }
	}
      }
     //   for(i = 0;i < n; i++){
      //printf("%s\t%d\n",A[i].ID,A[i].Score);
     // }
      for(i = 0;i < n; i++){
	if(strcmp(A[i].ID,"00") != 0){
	  insertNode(A[i],&T);
	}
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
      k = 0;
      printf("Nhap ten :");
      d = getchar();
      gets(B[0].Name);
      SEARCHING(&k,B[0],T);
      if(k == 0) printf("Khong tim thay");
      break;
    case 4:
     /* printf("Nhap ten :");
      c = getchar();
      k = 0;
      gets(B[0].ID);
      B[0].Score = 0;
      SEARCHING(&k,B[0],T);
      if(k == 0) printf("Khong tim thay");
      else{
          DeleteNode(B[0],&T);
          insertNode(input(),&T);
      }*/
      break;
    case 5:
      /*printf("Nhap so diem toi thieu de tru hang: ");
      scanf("%d",&k);
      printf("Cac doi phai xuong hang: ");
      lower(k,T);*/
      break;
    case 6:
    if((ptr = fopen("DanhSach.txt","w"))==NULL){
	printf("Cannot create KetQua.txt\n");
	return 1;
      }
      OutPutFile(ptr,T);
      fclose(ptr);
      printf("Complete!\n");
      
      break;

    case 7:
      printf("Quit !!\n");
      freeTree(T);
      exit(0);
      break;
    default:
        printf("HAY CHON TU 1 - 7");
        break;
    }
  }

 
  
  return 0;
}