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
  FILE *ptr = fopen("PhoneBook.dat","r+b");
  phone A[1];
  if(ptr == NULL){
    printf("Cannot open the file\n");
    return 1;
  }
  while( fread(A,sizeof(phone),1,ptr) != 0){
    printf("%-20s %-20s %-20s\n", A[0].name, A[0].email, A[0].tel);
  }
  fclose(ptr);
  return 0; 
}
