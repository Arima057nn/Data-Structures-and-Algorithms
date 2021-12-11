#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Num 10
typedef struct SmartPhone{
  char model[25];
  char GB[5];//Dung luong bo nho
  char inches[5];//Kich thuoc man hinh
  char price[10];
} phone;

int main(){
  int i;
  phone a[Num],*b;
  char buff[500];
  FILE *fp1,*fp2;
  b = (phone*)malloc(Num * sizeof(phone));
  fp1 = fopen("SmartPhone.txt","r");
  fp2 = fopen("SmartPhone.dat","w+b");
  if( fp1 == NULL|| fp2 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  for(i=0;i<Num;i++){
    fscanf(fp1,"%s%s%s%s%*c",a[i].model,a[i].GB,a[i].inches,a[i].price);
    strcpy(b[i].model , a[i].model);
    strcpy(b[i].GB , a[i].GB);
    strcpy(b[i].inches , a[i].inches);
    strcpy(b[i].price , a[i].price);
  }
  fwrite(b,sizeof(phone),Num,fp2);
  fread(b,sizeof(phone),Num,fp2);
  for(i=0;i<Num;i++){
    printf("%-25s %-15s %-20s %-20s\n",b[i].model,b[i].GB,b[i].inches,b[i].price);
  }
  free(b);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
  
