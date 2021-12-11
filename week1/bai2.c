#include <stdio.h>
#include <string.h>
#define MAX 100
/*
1.nhập thông tin sinh viên
2.In danh sách sinh viên
3.sắp xếp theo thứ tự tăng dần của điểm
4.sắp xếp theo tên theo thứ tự a -> z
5.sinh viên có điểm cao nhất
6.

*/

void Nhapn(int *n){
    do{
        printf("nhap n: ");
        scanf("%d",n);
    }while(*n <= 0);
    
}

typedef struct Name{
    char Ho[20];
    char Dem[20];
    char Ten[20];
}   Name;

typedef struct Students{
    float scout;
    Name Name ;
}   SV; 

void Nhap(SV *p){
    char c;
    printf("Nhap Ho: ");
    c = getchar();
    gets(p->Name.Ho); 
    printf("Nhap Dem: ");
    c = getchar();
    gets(p->Name.Dem);  
    printf("Nhap Ten: ");
    c = getchar();
    gets(p->Name.Ten);
    
   
}
void NhapN(SV a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("===Sinh vien %d===\n",i+1);
        Nhap(&a[i]);
    }
}
void Xuat(SV *p){
    printf("%-7s %-7s %-7s \n",p->Name.Ho,p->Name.Dem,p->Name.Ten);
}

void XuatN(SV a[],int n){
    int i;
    printf("%-7s %-7s %-7s \n","Ho","Dem","Ten");
    
    for(i=0;i<n;i++){
        Xuat(&a[i]);
    }

}
void SapXepScout(SV a[],int n){
    int i,j;
    SV b[MAX];
    for(i=0;i<n;i++){
        b[i] = a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(b[i].scout < b[j].scout){
                SV temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    XuatN(b,n);
}
void SapXepName(SV a[],int n){
    int i,j;
    SV b[MAX];
    for(i=0;i<n;i++){
        b[i] = a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(b[i].Name.Ten,b[j].Name.Ten) > 0){
                SV temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    XuatN(b,n);
}
int main(){
    int n;
    SV sv[MAX];
    int i = 0;
    int luaChon;
    printf("==================MENU=================\n");
    printf(" \n");
    printf("1.Nhap so luong va nhap thong tin sinh vien\n");
    printf("2.Xuat danh sach va thong tin sinh vien\n");
    printf("3.Sap xep theo thu tu diem trung binh tu cao den thap\n");
    printf("4.Sap xep thep ten a->z\n");
    printf("5.Thoat\n");
    do{
    printf("\nBan chon? ");
    scanf("%d",&luaChon);
    if(luaChon !=2 && luaChon !=3 && luaChon !=4 && luaChon != 5){
        i=1;
    }
    if((luaChon ==2 || luaChon ==3 || luaChon ==4 || luaChon == 5) && i == 0 ){
        do{
            printf("bam 1 de nhap thong tin: ");
            scanf("%d",&luaChon);
        }while(luaChon ==2 || luaChon ==3 || luaChon ==4 || luaChon == 5 );
        

    }
    switch (luaChon){
    case 1:
        Nhapn(&n);
        NhapN(sv,n);
        break;
    case 2:
        XuatN(sv,n);
        break;
    case 3:
        SapXepScout(sv,n);
        
        break;
    case 4:
        SapXepName(sv,n);
        break;
    case 5:
    
        
        break;
    case 6: 
        printf("Da thoat chuong trinh");
    default:
        printf("Khong co chuc nang nay");
        break;
    }
    }while(luaChon != 6);






    return 0;
}