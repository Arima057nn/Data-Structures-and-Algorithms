#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10
typedef struct Phone{
  char name[30];
  char email[30];
  char tel[10];
} phone;

int main(){
  int j = 0;
  phone A[1];
  FILE *ptr;
  char c;
  ptr = fopen("PhoneBook.dat","w+b");
  if(ptr == NULL){
    printf("Cannot open the file");
    return 1;
  }
  while(j < Max){
    printf("Name: ");
    gets(A[0].name);
    printf("Email: ");
    gets(A[0].email);
    printf("Tel: ");
    gets(A[0].tel);
    fwrite(A,sizeof(phone),1,ptr);
    j++;
  }
  fclose(ptr);
  return 0;
}
