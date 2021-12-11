#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct bongda{
  char ID[10];
  int Score;
} soocer;

#include "GenBST.h"
int main(){
  FILE *ptr;
  int a, b;
  int i = 0,j,n,k = 0;
  int luaChon;
  char s[30], c;
  soocer A[20],B[1];
  tree found;
  tree T;
  makeNullTree(&found);
  makeNullTree(&T);
  printf("==================MENU=================\n");
  printf("1.Import data from file text\n");
  printf("2.Diplay\n");
  printf("3.Search\n");
  printf("4.Update\n");
  printf("5.Xuong hang\n");
  printf("6.Import to File\n");
  printf("7.Quit\n");
  printf("=============");
  while (1){
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon){
    case 1:
      ptr = fopen("bongda.txt", "r");
      if (ptr == NULL){
        printf("cannot open the file");
        return 1;
      }
      while (!feof(ptr)){
        fscanf(ptr, "%s%s%d%d%*c", A[i].ID, A[i+1].ID, &a, &b);
        if (a > b){
          A[i].Score = 3;
          A[i+1].Score = 0;
        }
        else if (a == b){
          A[i].Score = 1;
          A[i+1].Score = 1;
        }
        else{
          A[i].Score = 0;
          A[i+1].Score = 3;
        } 
	i = i + 2;
      }
      n = i - 2;
      for(i = 0; i < n-1 ; i++){
	for(j = i + 1; j < n; j++){
	  if(strcmp(A[i].ID , A[j].ID) == 0){
	    strcpy(A[j].ID, "00");
	    A[i].Score += A[j].Score;
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
      printf("Nhap ten :");
      c = getchar();
      k = 0;
      gets(B[0].ID);
      B[0].Score = 0;
      SEARCHING(&k,B[0],T);
      if(k == 0) printf("Khong tim thay");
      break;
    case 4:
      printf("Nhap ten :");
      c = getchar();
      k = 0;
      gets(B[0].ID);
      B[0].Score = 0;
      SEARCHING(&k,B[0],T);
      if(k == 0) printf("Khong tim thay");
      else{
          DeleteNode(B[0],&T);
          insertNode(input(),&T);
      }
      break;
    case 5:
      printf("Nhap so diem toi thieu de tru hang: ");
      scanf("%d",&k);
      printf("Cac doi phai xuong hang: ");
      lower(k,T);
      break;
    case 6:
    if((ptr = fopen("KetQua.txt","w"))==NULL){
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
