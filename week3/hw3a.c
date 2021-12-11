#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
  char Name[20];
  int MSSV;
  int SDT;
  int STT;
  
  
} SV;

void NhapN(int *n){  
  do{
    printf("Nhap n: ");
    scanf("%d",n);
  }while(*n <= 0 || *n > 10);
}

void InName(SV *p){
  char c;
  printf("Name: ");
  c = getchar();
  gets(p->Name);
  printf("MSSV: ");
  scanf("%d",&p->MSSV);
  printf("STT: ");
  scanf("%d",&p->STT);
  printf("SDT : ");
  scanf("%d",&p->SDT);
}

void InnName(SV a[],int n){
  int i;
  for(i=0;i<n;i++){
    printf("Sinh vien %d: ",i);
    InName(&a[i]);
}
}

void OutFILE(SV a[],int n){
  int i;
  FILE *fptr;
  fptr = fopen("SinhVien.txt","w");
  if(fptr == NULL){
    printf("Cannot open the file");
    exit(1);
}
  fprintf(fptr,"%-10s %-20s %-10s %-10s\n","STT","Name","MSSV","SDT");
  for(i = 0;i<n;i++){
    fprintf(fptr,"%-10d %-20s %-10d %-10d\n",a[i].STT,a[i].Name,a[i].MSSV,a[i].SDT);
    
  }
  fclose(fptr);
}

int main(){
  SV sv[100];
  int n;
  NhapN(&n);
  InnName(sv,n);
  OutFILE(sv,n);

  return 0;
  
}
