#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Num 20
typedef struct Phone{
  char name[25];
  char sdt[15];

} phone;

int main(){
  
  int i,j;
  FILE *ptr,*fp1,*fp2;
  phone *a,*b,*c;
  ptr = fopen("grade.dat","r+b");
  fp1 = fopen("phone1.dat","w+b");
  fp2 = fopen("phone2.dat","w+b");
  
  a = (phone*)malloc(20 * sizeof(phone));
  b = (phone*)malloc(10 * sizeof(phone));
  c = (phone*)malloc(10 * sizeof(phone));
  fread(a,sizeof(phone),20,ptr);
  
  for(i=0;i<10;i++){
    strcpy(b[i].name,a[i].name);
    strcpy(b[i].sdt,a[i].sdt);
  }
  fwrite(b,sizeof(phone),10,fp1);
  if( (fseek(ptr, 10*sizeof(phone) ,SEEK_SET) ) != NULL){
    printf("fseek");
    return 1;
  }
  for(i=0;i<10;i++){
    strcpy(c[i].name,a[i+10].name);
    strcpy(c[i].sdt,a[i+10].sdt);
  }
  fwrite(c,sizeof(phone),10,fp2);
  free(a);
  free(b);
  free(c);
  fclose(ptr);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
