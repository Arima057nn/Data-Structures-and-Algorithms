#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Phone{
  char name[25];
  char sdt[15];

} phone;

int main(int n,char *m[]){
  if(n != 5){
    printf("Syntax error");
    return 1;
  }
  FILE *ptr,*fp1,*fp2;
  phone a[20],*b,*c;
  int i,j;
  j = atoi(m[2]);
  ptr = fopen(m[1],"r+b");
  fp1 = fopen(m[3],"w+b");
  fp2 = fopen(m[4],"w+b");
  if(ptr == NULL || fp1 == NULL ||fp2 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  b = (phone*)malloc(j*sizeof(phone));
  c = (phone*)malloc((20-j)*sizeof(phone));
  fread(a,sizeof(phone),20,ptr);
  for(i=0;i<j;i++){
    strcpy(b[i].name,a[i].name);
    strcpy(b[i].sdt,a[i].sdt);
  }
  fwrite(b,sizeof(phone),j,fp1);
  if(fseek(ptr,j*sizeof(phone),SEEK_SET) != 0){
        printf("Fseek failed!\n");
        return 1;
    }
  for(i=0;i<20-j;i++){
    strcpy(c[i].name,a[j+i].name);
    strcpy(c[i].sdt,a[j+i].sdt);
  }
  fwrite(c,sizeof(phone),20-j,fp2);
  free(b);
  free(c);
  fclose(ptr);
  fclose(fp1);
  fclose(fp2);
  return 0;
}
