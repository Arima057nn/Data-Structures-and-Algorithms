#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct Dic
{
  char Aa[100];
  char Vv[100];
} AV;
#include "GenBSThw1.h"
int main()
{
  FILE *fptr, *ptr;
  AV A[1], B[1];
  int i = 0, k;
  int luaChon;
  char s[30], c;
  tree T, found;
  makeNullTree(&found);
  makeNullTree(&T);
  printf("==================MENU=================\n");
  printf("1.Import data from file text\n");
  printf("2.Diplay\n");
  printf("3.Insert\n");
  printf("4.Delete\n");
  printf("5.Search\n");
  printf("6.Save to File\n");
  printf("7.Quit\n");
  printf("=============");
  while (1)
  {
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon)
    {
    case 1:
      ptr = fopen("anhViet.txt", "r");
      if (ptr == NULL)
      {
        printf("cannot open the file");
        return 1;
      }
      while (!feof(ptr))
      {
        fscanf(ptr, "%[^:]%*c%[^\n]%*c", A[0].Aa, A[0].Vv);
        insertNode(A[0], &T);
      }
      printf("\ncomplete!\n");
      fclose(ptr);
      break;
    case 2:
      printf("\n--> Left - Node - Right\n");
      inorderprint(T);
      printf("\ncomplete!\n");
      break;
    case 3:
      insertNode(input(), &T);
      printf("\ncomplete!\n");
      break;
    case 4:
      printf("Nhap ten muon xoa\n");
      gets(A[0].Aa);
      DeleteNode(A[0], &T);
      printf("\ncomplete!\n");
      break;
    case 5:
      printf("Nhap ten de tim kiem: ");
      scanf("%s%*c", B[0].Aa);
      found = Searching(B[0], T);
      if (found == NULL)
        printf("Khong tim thay\n");
      else
        displayElement(found->data);
      break;
    case 6:
      /*
      //Doc vao file dat
      fptr = fopen("Student.dat","wb");
      if(fptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      OutPutFile2(fptr,T);
      printf("\ncomplete!\n");
      fclose(fptr);
      break;
      */
    case 7:
      printf("Quit !!\n");
      freeTree(T);
      exit(0);
      break;
    default:
      printf("HAY CHON TU 1 - 9");
      break;
    }
  }
  return 0;
}
