#include <stdio.h>

typedef struct AAA
{

} AAA;
#include "GenSLL.h"
int main()
{
    FILE *ptr;
    AAA A[1];
    node *head, *p;
    initialize(&head);
    //cd  initialize(&p);
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
               ""
               "---->Choose ");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            ptr = fopen(".....", "r");
            if (ptr == NULL)
            {
                printf("Cannot open the file");
                return 1;
            }
            while (fscanf(ptr, "\n",) == 4)
            {
                //insertAtTail(A[0], &head);
            }
            fclose(ptr);
            break;
        case 2:
            traversingList(head);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            printf("Nhap de tim kiem: ");
            c = getchar();
            gets(A[0].model);
            searching(head, A[0]);
            break;
        case 6:
            sortList(&head);
            break;
        case 7:

            break;
        case 8:
            p = head;
            ptr = fopen("PhoneDB.txt", "w");
            if (ptr == NULL)
            {
                printf("cannot open the file");
                return 1;
            }
            while (p != NULL)
            {
                A[0] = p->data;
                fprintf(ptr, "%s\t%d\t%d\t%s\n", A[0].model, A[0].size, A[0].memory, A[0].price);
                p = p->next;
            }
            printf("\nComplete!\n");
            fclose(ptr);
            break;
        case 9:
            printf("Quit !");
            freeList(&head);
            exit(0);
            break;
        }
    }
    return 0;
}
