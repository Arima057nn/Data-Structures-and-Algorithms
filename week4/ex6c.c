#include <stdio.h>
#define NUM 10
#include <stdlib.h>
typedef struct PhoneAddress_t{
  char name[25];
  char tel[25];
  char mail[25];
}phone;

int main(){
  FILE *ptr;
  phone A[5];
  int i;
  ptr = fopen("PhoneAddress.dat","r+b");
  fread(A,sizeof(phone),NUM,ptr);
  if(ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  printf("%-20s %-20ss %-20s\n","Name","Tel","Mail");
  for(i=0;i<NUM;i++){
    printf("%-20s %-20s %-20s\n",A[i].name,A[i].tel,A[i].mail);

     
  }
  fclose(ptr);

  return 0;
}
