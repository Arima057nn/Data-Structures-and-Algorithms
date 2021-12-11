#include <stdio.h>
#include <string.h>

typedef struct computer
{
    int id;
    char CPU[5];
    int RAM;
} computer;

#include "GenSLL.h"

int main()
{
    FILE *ptr;
    computer A[0];
    node *head, *p;
    initialize(&head);
    //cd  initialize(&p);
    int choose, luaChon;
    int i = 1, N, n, id, k;
    char s[100], c, file[50];
    while (1)
    {
        printf("\n========MENU=========\n"
               "1.Load Data Files\n"
               "2.Update CPU info\n"
               "3.Update RAM info\n"
               "4.Search\n"
               "5.Quit\n"
               "---->Choose ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            printf("Nhap ten file de the du lieu: ");
            scanf("%s%*c", file);
            ptr = fopen(file, "r");
            if (ptr == NULL)
            {
                printf("File khong ton tai !\n");
            }
            else
            {

                fscanf(ptr, "%d%*c", &n);
                while (fscanf(ptr, "%s%d%*c", A[0].CPU, &A[0].RAM) == 2)
                {
                    A[0].id = i;
                    insertAtTail(A[0], &head);
                    i++;
                    if (i == 21)
                    {
                        break;
                    }
                }
                N = i - 1;
                fclose(ptr);
                printf("Complete !\n");
                if (i > 20)
                    printf("Bo nho da day. Khong them duoc !");
            }

            break;
        case 2:
            k = 0;
            printf("Nhap ID: ");
            scanf("%d", &A[0].id);
            updateCPU(&k,&head, A[0]);
            traversingList(head);
            id = A[0].id;
            do
            {
                k = 0;
                printf("Nhap lai cho may co ID lon hon %d: ", id);
                scanf("%d", &A[0].id);
                
                if (A[0].id > id && A[0].id <= N)
                {
                    updateCPU(&k,&head, A[0]);
                    if(k == 1) break;
                    id = A[0].id;
                    traversingList(head);
                }
                if(k == 1) break;
                if (A[0].id == N)
                    break;
            } while (A[0].id <= id || A[0].id > N);
            break;

        case 3:
            k = 0;
            printf("Nhap ID: ");
            scanf("%d", &A[0].id);
            updateRAM(&head, A[0]);
            traversingList(head);
            id = A[0].id;
            do
            {
                printf("Nhap lai cho may co ID lon hon %d: ", id);
                scanf("%d", &A[0].id);
                if (A[0].id > id && A[0].id <= N)
                {
                    updateRAM(&head, A[0]);
                    //k = 1;
                    id = A[0].id;
                    traversingList(head);
                }
                if (A[0].id == N)
                    break;
            } while (A[0].id <= id || A[0].id > N);
            break;
        case 4:
            printf("1.Tim kiem theo CP\n"
                   "2.Tim tim theo RAM\n");
            printf("-->Ban chon: ");
            scanf("%d", &luaChon);
            switch (luaChon)
            {
            case 1:
                printf("Nhap ten CPU: ");
                scanf("%s%*c", A[0].CPU);
                if (dinhDang1(A[0].CPU) == 1)
                {
                    searching(head, A[0]);
                }
                else if (dinhDang1(A[0].CPU) == 0)
                {
                    printf("Xau nhap khong trung voi bat ki ten CPU nao !");
                }
                break;
            case 2:
                printf("Nhap RAM: ");
                scanf("%d", &A[0].RAM);
                if (dinhDang2(A[0].RAM) == 1)
                {
                    searching2(head, A[0]);
                }
                else if (dinhDang2(A[0].RAM) == 0)
                {
                    printf("Xau nhap khong trung voi bat ki ten RAM nao !");
                }
                break;
                break;
            default:
                printf("Khong co chuc nang nay !\n");
                break;
            }
            break;
        case 5:
            printf("Quit !");
            freeList(&head);
            exit(0);
            break;
        }
    }
    return 0;
}
