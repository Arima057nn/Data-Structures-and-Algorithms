#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct bongda
{
  int Id;
  char Tendoibong[30];
  int Diem;
  int Sobanthang;
  int Sobanthua;
} soocer;

typedef struct Vong
{
  char Vong[10];
  soocer A[10];
  soocer B[10];

} vong;

int compare(soocer a, soocer b)
{
  if (a.Id == b.Id)
    return 1;
  else
    return 0;
}
#include "singleList.h"

void displayNode(node *e)
{
  printf("%-10d %-20s  %-10d %-10d %-10d\n", e->data.Id, e->data.Tendoibong, e->data.Diem, e->data.Sobanthang, e->data.Sobanthua);
}
int main()
{
  FILE *ptr;
  int a, b;
  int i = 0, j, n, x, y, z, min, k;
  int luaChon;
  char s[30], c;
  soocer *A, B[1];
  node *T;
  node *p;
  vong *V;
  initialize(&p);
  initialize(&T);
  printf("==================MENU=================\n");
  printf("1.In ra thong tin cac doi bong\n");
  printf("2.In ra lich thi dau\n");
  printf("3.Cap nhat thong tin vong dau\n");
  printf("4.Xoa doi\n");
  printf("5.Quit\n");
  printf("=============");
  while (1)
  {
    printf("\n--->Ban chon? ");
    scanf("%d", &luaChon);
    switch (luaChon)
    {
    case 1:
      freeList(&T);
      ptr = fopen("bongda.txt", "r");
      if (ptr == NULL)
      {
        printf("cannot open the file");
        return 1;
      }
      fscanf(ptr, "%d%*c", &n);
      printf("So doi bong tham gia la: %d\n", n);
      A = (soocer *)malloc(n * sizeof(soocer));
      V = (vong *)malloc(n * sizeof(vong));
      for (i = 0; i < n; i++)
      {
        fscanf(ptr, "%d%*c%[^\n]%*c", &A[i].Id, A[i].Tendoibong);
        A[i].Sobanthang = 0;
        A[i].Sobanthua = 0;
        A[i].Diem = 0;
        //printf("%-20d\t%-20s\n",A[0].Id,A[0].Tendoibong);
        insertAtHead(A[i], &T);
      }
      for (i = 0; i < n - 1; i++)
      {
        fscanf(ptr, "%[^\n]%*c", V[i].Vong);
        for (j = 0; j < n / 2; j++)
        {
          fscanf(ptr, "%d%*c%d%*c", &V[i].A[j].Id, &V[i].B[j].Id);
          for (z = 0; z < n; z++)
          {
            if (A[z].Id == V[i].A[j].Id)
              V[i].A[j] = A[z];
            if (A[z].Id == V[i].B[j].Id)
              V[i].B[j] = A[z];
          }
        }
      }
      traversingList(T);
      fclose(ptr);
      break;
    case 2:
      printf("=== Lich thi dau ===\n");
      for (i = 0; i < n - 1; i++)
      {
        printf("%s\n", V[i].Vong);
        for (j = 0; j < n / 2; j++)
        {
          printf("%-10s%-5s%-7s\n", V[i].A[j].Tendoibong, "-", V[i].B[j].Tendoibong);
        }
      }
      printf("\ncomplete!\n");
      break;
    case 3:
      freeList(&T);
      printf("Giai dau co %d vong dau\n", n - 1);
      printf("Cap nhat ket qua vong: ");
      do
      {
        scanf("%d", &i);
      } while (i > n || i < 1);
      //printf("%d", n);
      i = i - 1;
      for (j = 0; j < n / 2; j++)
      {
        printf("Tran %d: ", j + 1);
        printf("%-10s%-5s%-7s\n", V[i].A[j].Tendoibong, "-", V[i].B[j].Tendoibong);
        scanf("%d %d", &x, &y);
        if (x > y)
        {
          V[i].A[j].Diem = 3;
          V[i].B[j].Diem = 0;
        }
        else if (x < y)
        {
          V[i].A[j].Diem = 0;
          V[i].B[j].Diem = 3;
        }
        else if (x == y)
        {
          V[i].A[j].Diem = 1;
          V[i].B[j].Diem = 1;
        }
        V[i].A[j].Sobanthang = V[i].B[j].Sobanthua = x;
        V[i].B[j].Sobanthang = V[i].A[j].Sobanthua = y;

        for (z = 0; z < n; z++)
        {
          if (A[z].Id == V[i].A[j].Id)
          {
            A[z].Diem += V[i].A[j].Diem;
            A[z].Sobanthang += V[i].A[j].Sobanthang;
            A[z].Sobanthua += V[i].A[j].Sobanthua;
          }
          if (A[z].Id == V[i].B[j].Id)
          {
            A[z].Diem += V[i].B[j].Diem;
            A[z].Sobanthang += V[i].B[j].Sobanthang;
            A[z].Sobanthua += V[i].B[j].Sobanthua;
          }
        }
      }
      for (z = 0; z < n; z++)
      {
        insertAtHead(A[z], &T);
      }
      printf("\nCap nhat Diem: \n");
      traversingList(T);
      break;
    case 4:
      k = 0;
      p = T;
      min = p->data.Diem; 
      while(p != NULL){
        if(min >= p->data.Diem) min = p->data.Diem;  
        p = p->next;
      }
      p = T;
      printf("Cac doi phai xuong hang: ");
      while(p != NULL){
        if(min == p->data.Diem){
          displayNode(p);
          k++;
        }
      }
      if(k == 0)  printf("Khong co doi nao !\n");

      break;

      break;

    case 5:
      printf("Quit !!\n");
      freeList(&T);
      exit(0);
      break;
    default:
      printf("HAY CHON TU 1 - 7");
      break;
    }
  }

  return 0;
}
