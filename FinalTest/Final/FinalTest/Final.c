#include <stdio.h>

typedef struct GPS
{
    char tenDiaDiem[40];
    int gio;
    int phut;
} diaDiem;
#include "GenSLL.h"

int main()
{
    FILE *ptr;
    diaDiem A[1],B[1];
    node *head;
    initialize(&head);
    int choose;
    int i, k;
    char s[100], c;
    while (1)
    {
        printf("\n============MENU===========\n"
               "1.Nap du lieu log lich su di chuyen\n"
               "2.In ra lich su di chuyen \n"
               "3.Tim kiem lich su di chuyen theo dia diem\n"
               "4.Tim kiem thong tin di chuyen theo thoi gian\n"
               "5.Kiem tra truy vet moi nhat\n"
               "6.Thoat\n"
               "---->Ban chon: ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            freeList(&head);
            ptr = fopen("log.txt", "r");
            if (ptr == NULL)
            {
                printf("Cannot open the file");
                return 1;
            }
            while (fscanf(ptr, "%s%d%d%*c", A[0].tenDiaDiem, &A[0].gio, &A[0].phut) == 3)
            {
                insertAtTail(A[0], &head);
            }
            printf("Complete !\n");
            fclose(ptr);
            break;
        case 2:
            printf("---- Lich su di chuyen ----\n");
            traversingList(head);
            break;
        case 3:
            printf("Nhap dia diem de tim kiem: ");
            scanf("%s%*c", A[0].tenDiaDiem);
            searching(head, A[0]);
            break;
        case 4:
            strcmp(B[0].tenDiaDiem,"Nha_rieng");
            B[0].gio = 23;
            B[0].phut = 59;
            insertAtTail(B[0],&head);
            do
            {
                printf("Nhap gio ( 0 <= gio < 24 ): ");
                scanf("%d", &A[0].gio);
            } while (A[0].gio >= 24 || A[0].gio < 0);
            do
            {
                printf("Nhap phut ( 0 <= phut < 60 ): ");
                scanf("%d", &A[0].phut);
            } while (A[0].phut >= 60 || A[0].phut < 0);
            searching2(head,A[0]);
            delLastElement(&head);
            break;
        case 5:
            B[0] = input();
            searching3(head,B[0]);
            break;
            
            break;
        case 6:
            printf("Quit !");
            freeList(&head);
            exit(0);
            break;
        }
    }
    return 0;
}