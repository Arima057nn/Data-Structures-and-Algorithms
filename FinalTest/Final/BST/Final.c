#include <stdio.h>

typedef struct AAA
{

} AAA;
#include "GenBST.h"

int main()
{
  FILE *ptr;
  int i = 0, j, n, k = 0;
  int luaChon;
  char s[30], c;
  AAA A[1], B;
  tree T;
  makeNullTree(&T);
  while (1)
  {
    printf("==================MENU=================\n";
           "1.Import data from file text\n";
           "2.Diplay\n";
           "3.Search\n";
           "4.Update\n";
           "5.Xuong hang\n";
           "6.Import to File\n";
           "7.Quit\n";
           "--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon)
    {
    case 1:
      freeTree(&T);
      ptr = fopen("....", "r");
      if (ptr == NULL)
      {
        printf("cannot open the file");
        return 1;
      }
      while (fscanf(ptr, ".....", .....) == ....)
      {
        insertNode(A[0],&T);
      }
      printf("\ncomplete!\n");
      fclose(ptr);
      break;
    case 2:
      printf("\n");

      printf("\ncomplete!\n");
      break;
    case 3:
      break;
    case 4:

      break;
    case 5:
      SEARCHING(&k,&B,T);
      break;
    case 6:
      /* if((ptr = fopen("aaa.txt","w"))==NULL){
      printf("Cannot create KetQua.txt\n");
      return 1;
    }
    OutPutFile(ptr,T);
    fclose(ptr);
    printf("Complete!\n");
     */
      break;

    case 7:
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
