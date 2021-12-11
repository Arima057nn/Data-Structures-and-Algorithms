#include <stdio.h>
#include <stdlib.h>
#define NUM 10
typedef struct PhoneAddress_t{
  char name[25];
  char tel[25];
  char mail[25];
}phone;

int main(){
  FILE *ptr;
  phone *A;
  int n=1,m=2,i;
  if( (ptr = fopen("PhoneAddress.dat","r+b")) == NULL){
    printf("Cannot open the file");
    return ;
  }
  A = (phone*)malloc((m-n+1)*sizeof(phone));
  if(A == NULL){
    printf("memory allocation failed");
    return 1;
  }
  if( (fseek(ptr, 4*sizeof(phone) ,SEEK_SET) ) != NULL){
    printf("fseek");
    return 1;
  }
  fread(A,sizeof(phone),m-n+1,ptr);
  for( i = 0; i<m-n+1;i++){
    printf(" === %d===", i+n);
    printf("Name: ");
    gets(A[i].name);
    printf("tel: ");
    gets(A[i].tel);
    printf("email: ");
    gets(A[i].mail);
    
  }
  if( (fseek(ptr, 4*sizeof(phone) ,SEEK_SET) ) != NULL){
    printf("fseek");
    return 1;   
  }// quay lai de cai moi len cai cu
  fwrite(A,sizeof(phone),m-n+1,ptr);
  free(A);
  fclose(ptr);
  return 0;
}
    
