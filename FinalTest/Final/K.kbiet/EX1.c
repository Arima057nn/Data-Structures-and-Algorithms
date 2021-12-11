#include <string.h>
#include <stdio.h>
#include <string.h>
typedef struct nhatki
{
  char userName[20];
  char passWord[20];
  float score;
} student;

#include "GenBST.h"

int main()
{
  FILE *ptr;
  int i = 0, j, k;
  int luaChon, choose;
  char s[20], c;
  student A[1], B;
  tree found;
  tree T;
  makeNullTree(&found);
  makeNullTree(&T);
  while (1)
  {
    printf("==================MENU=================\n");
    printf("1.Dang nhap\n");
    printf("2.Thoat\n");
    printf("=============");
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon)
    {
    case 1:
      freeTree(&T);
      k = j = 0;
      ptr = fopen("sinhvien.txt", "r");
      if (ptr == NULL)
      {
        printf("cannot open the file");
        return 1;
      }
      while (fscanf(ptr, "%s%*c%s%*c%f%*c", A[0].userName, A[0].passWord, &A[0].score) == 3)
      {
        insertNode(A[0], &T);
      }
      fclose(ptr);
      do
      {
        printf("\nNhap UserName: ");
        c = getchar();
        gets(B.userName);
        SEARCHING(&k, &B, T);
        printf("Nhap passWord: ");
        gets(s);
        if (strcmp(s, B.passWord) == 0 && k == 1)
        {
          j = 5;
          printf("=== Dang nhap thanh cong! ===\n");
        }
        else
        {
          j++;

          if (j <= 3)
            printf("Nhap sai %d lan", j);
        }
      } while (j <= 3);
      if (j == 4)
      {
        printf("Nhap sai quan 3 lan.Da thoat !\n");
        return 1;
      }
      if (strcmp(B.userName, "Admin") == 0)
      {
        do
        {
          printf("---menu---\n");
          printf("1.Them sinh vien\n"
                 "2.In danh sach sinh vien\n"
                 "3.Xoa sinh vien\n"
                 "4.Luu file va thoat\n"
                 "Choose: ");
          scanf("%d", &choose);
          switch (choose)
          {
          case 1:
            do
            {
              k = 0;
              printf("UserName :");
              scanf("%s%*c", B.userName);
              SEARCHING(&k, &B, T);
              if (k == 1)
                printf("Tai khoan nay da ton tai. Nhap lai: ");
            } while (k == 1);
            printf("PassWord: ");
            scanf("%s%*c", B.passWord);
            printf("Score: ");
            scanf("%f", &B.score);
            insertNode(B, &T);
            break;
          case 2:
            inorderprint(T);
            break;
          case 3:
            k = 0;
            printf("Nhap tai khoan can xoa: ");
            scanf("%s%*c", B.userName);
            SEARCHING(&k, &B, T);
            if (k == 0)
              printf("Khong tim thay sinh vien");
            if (k == 1)
              displayElement(B);
            if (strcmp(B.userName, "Admin") == 0)
            {
              printf("Khong the xoa Admin\n");
            }
            else
              DeleteNode(B, &T);
            break;
          case 4:
            j = 0;
            ptr = fopen("sinhvien.txt", "w");
            if (ptr == NULL)
            {
              printf("Cannot open the file");
              return 1;
            }
            OutPutFile(ptr, T);

            fclose(ptr);
            break;
          default:
            printf("Khong co chuc nang nay");
            break;
          }

        } while (choose != 4);
      }
      else
      {
        do
        {
          printf("---menu---\n");
          printf("1.Xem diem\n"
                 "2.Thay doi mat khau\n"
                 "3.Luu file va thoat\n"
                 "Choose: ");
          scanf("%d", &choose);
          switch (choose)
          {
          case 1:
            printf("--> Score: %g\n", B.score);
            break;
          case 2:
            printf("Nhap pass moi: ");
            c = getchar();
            gets(B.passWord);
            printf("Nhap lai pass: ");
            gets(s);
            if (strcmp(s, B.passWord) == 0)
            {
              printf("Thay doi thanh cong");
              DeleteNode(B, &T);
              insertNode(B, &T);
            }
            else
            {

              printf("Thay doi khong thanh cong");
            }
            break;
          case 3:
            ptr = fopen("sinhvien.txt", "w");
            if (ptr == NULL)
            {
              printf("Cannot open the file");
              return 1;
            }
            OutPutFile(ptr, T);
            fclose(ptr);

            break;
          default:
            printf("Khong co chuc nang nay");
            break;
          }

        } while (choose != 3);
      }
      break;
    case 2:
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
