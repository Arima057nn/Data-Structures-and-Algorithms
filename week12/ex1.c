#define MAX 10
#include <string.h>
typedef struct Phone{
  char name[30];
  char email[30];
  char tel[10];
} phone;

int TraVe(phone x, phone e){
    if( strcmp(x.email,e.email) == 0) return 0;
    else if( strcmp(x.email,e.email) > 0) return 1;
    else return -1;
}
#include "SearchBinaryTree.h"


int main(){
  tree T;
  phone A[1];
  makeNullTree(&T);
  FILE *ptr = fopen("PhoneBook.dat","rb");
  int i;
  while(fread(A,sizeof(phone),1,ptr) != 0){
    insertNode(A[0],&T);
  }
  preoderprint(T);
  printf("\n");
  inorderprint(T);
  return 0;
}
