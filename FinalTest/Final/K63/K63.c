#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct tudien
{
  char tu[50];
  char nghia[50];
} tudien;
typedef struct sau
{
  char sau[10];
} sau;
#include "GenBST.h"
char *to_lower(char s[])
{
  for (int i = 0; s[i] != '\0'; i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
    {
      s[i] = s[i] + 32;
    }
  }
  return s;
}
int main()
{
  FILE *ptr;
  int a, b;
  int i = 0, j, n, k = 0, h;
  int luaChon;
  char s[30], c, z[3];
  tudien A[1], B[1];
  tree found;
  tree T;
  sau C[10];
  makeNullTree(&found);
  makeNullTree(&T);
  while (1)
  {
    printf("==================MENU=================\n");
    printf("1.Nap tu dien\n");
    printf("2.Noi dung tu dien\n");
    printf("3.Tim kiem va chinh sua\n");
    printf("4.Dich cau Anh-Viet\n");
    printf("5.Thoat\n");
    printf("=============");
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon)
    {
    case 1:
      ptr = fopen("tudien.txt", "r");
      if (ptr == NULL)
      {
        printf("cannot open the file");
        return 1;
      }
      while (fscanf(ptr, "%s%s%*c", A[0].tu, A[0].nghia) == 2)
      {
        insertNode(A[0], &T);
        displayElement(A[0]);
      }

      printf("\ncomplete!\n\n");
      fclose(ptr);
      break;
    case 2:
      printf("\n--> Left - Node - Right\n");
      InOrderPrint(T);
      break;
    case 3:
      k = 0;
      printf("Nhap tu khoa de tim kiem va sua doi: ");
      c = getchar();
      gets(B[0].tu);
      SEARCHING(&k, B[0], T);
      if (k == 1)
      {
        printf("Ban co muon sua doi nghia cho tu nay khong (y/n): ");
        gets(s);
        if (strcmp(s, "y") == 0)
        {
          DeleteNode(B[0], &T);
          printf("Nhap noi dung moi: ");
          gets(B[0].nghia);
          insertNode(B[0], &T);
        }
      }
      if (k == 0)
      {
        printf("Khong co trong tu dien. Nhap tu giai nghia moi cho tu do: ");
        gets(B[0].nghia);
        insertNode(B[0], &T);
      }

      printf("Complete!\n\n");
      break;
    case 4:
      k = 0;
      printf("Nhap cau van can dich: ");
      c = getchar();
      gets(s);
      printf("\n---> ")
      char *token = strtok(s, " ");
      while (token != NULL)
      {
        strcpy(C[h].sau, to_lower(token));
        strcpy(A[0].tu, C[h].sau);
        SEARCHING2(&k,A[0],T);
        //printf("%s",A[0].tu);
        if(k == 0) printf("<thieu tu> ");
        h++;
        token = strtok(NULL, " ");
      }
      printf("\nComplete!\n");
      break;

    case 5:
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