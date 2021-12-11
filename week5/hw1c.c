#include <stdio.h>
#include <stdlib.h>

typedef struct Phone{
  char name[25];
  char sdt[15];

} phone;
int main(){
  FILE *fp1, *fp2;
  phone b[10],c[10];
  int i;
  fp1 = fopen("phone1.dat","r+b");
  fp2 = fopen("phone2.dat","r+b");
  if(fp1 == NULL || fp2 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  fread(b,sizeof(phone),10,fp1); 
  printf("Danh sach phone1: \n");
  printf("%-20s %-20s\n","Name","SDT");
  for(i=0;i<10;i++){
    printf("%-20s %-20s\n",b[i].name,b[i].sdt);
     
  }
  printf("\n");
  
  fread(c,sizeof(phone),10,fp2); 
  printf("Danh sach phone2: \n");
  printf("%-20s %-20s\n","Name","SDT");
  for(i=0;i<10;i++){
    printf("%-20s %-20s\n",c[i].name,c[i].sdt);
     
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
