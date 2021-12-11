#include <stdio.h>
#include <string.h>
#define MAX 100
void Nhapn(int *n){
    do{
        printf("nhap n: ");
        scanf("%d",n);
    }while(*n <= 0);
    
}

typedef struct Name{
    char Ten[20];
}   SV;


void Nhap(SV *p){
    fflush(stdin);
    printf("Nhap Ho: ");
    gets(p->Ten);
   
}
void XuatN(SV a[],int n){
    int i;
    printf("%-7s\n","Ten");
    
    for(i=0;i<n;i++){
        Xuat(&a[i]);
    }

}
void SapXepName(SV a[],int n){
    int i,j;
    SV b[MAX];
    for(i=0;i<n;i++){
        b[i] = a[i];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(strcmp(b[i].Ten,b[j].Ten) > 0){
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
    char sv[MAX];
    Nhapn(&n);
    Nhap(sv,n);


    return 0;
}