#include <stdio.h>

typedef struct AAA
{
    int maSP;
    char ten[30];
    int SL;
    int gia;
} sanPham;
#include "GenDll.h"

int main()
{
    FILE *ptr;
    sanPham A[1];
    node *head, *cur, *tail;
    initialize(&head, &cur, &tail);
    int choose;
    int i, k;
    char s[100], c;
    while (1)
    {
        printf("========MENU=========\n"
               "1.Import from file text\n"
               "2.Display\n"
               "3.Insert\n"
               "4.Delete\n"
               "5.Searching\n"
               "6.Quit\n"
               "---->Choose ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            freeList(&head, &cur, &tail);
            ptr = fopen("sanpham.txt", "r");
            if (ptr == NULL)
            {
                printf("Cannot open the file");
                return 1;
            }
            while (fscanf(ptr, "%d%d%d%[^\n]%*c", &A[0].maSP, &A[0].gia, &A[0].SL, A[0].ten) == 4)
            {
                insertAtHead(A[0], &head, &cur, &tail);
            }
            fclose(ptr);
            printf("Complete !");
            break;
        case 2:
            traversingList1(head, cur, tail);
            break;
        case 3:
            sortList(&head, &tail);
            break;
        case 4:
            printf("Nhap gia: ");
            scanf("%s%*c", A[0].ten);
            searching(head, A[0]);
            break;
        case 5:
            ptr = fopen("new.txt", "w");
            if (ptr == NULL)
            {
                printf("cannot open the file");
                return 1;
            }
            outPutFile(head,tail,ptr);
            printf("\nComplete!\n");
            fclose(ptr);
            break;
        case 6:
            printf("Quit !");
            freeList(&head, &cur, &tail);
            exit(0);
            break;
        }
    }
    return 0;
}
