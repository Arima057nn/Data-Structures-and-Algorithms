#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Phone{
  char name[25];
  char sdt[15];

} phone;

int main(int n,char *m[]){
  if(n != 4){
    printf("Syntax error");
    return 1;
  }
  FILE *ptr,*fp1,*fp2;
  phone a[1];
  ptr = fopen(m[3],"r+b");
  fp1 = fopen(m[1],"r+b");
  fp2 = fopen(m[2],"r+b");
  if( ptr == NULL || fp1 == NULL || fp2 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  printf("Danh sach 1:\n");
  while(fread(a,sizeof(phone),1,fp1) != 0){
    printf("%-20s %-20s\n",a[0].name,a[0].sdt);
  }
  printf("Danh sach 2:\n");
  while(fread(a,sizeof(phone),1,fp2) != 0){
    printf("%-20s %-20s\n",a[0].name,a[0].sdt);
  }
  printf("Danh sach chung:\n");
  while(fread(a,sizeof(phone),1,ptr) != 0){
    printf("%-20s %-20s\n",a[0].name,a[0].sdt);
  }
  fclose(ptr);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
