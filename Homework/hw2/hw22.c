#include <string.h>
#include <stdio.h>
#define Max 50


typedef struct Student{
  char ten[10];
  char dem[10];
  char ho[10];
} student;

int TraVe(student x,student e){
  if( strcmp(x.ten, e.ten) == 0){
    if( strcmp(x.dem, e.dem) == 0){
      if( strcmp(x.ho, e.ho) > 0) return -1;
      else if( strcmp(x.dem, e.dem) < 0) return 1;

    }
  }else if( strcmp(x.ten, e.ten) > 0) return -1;
  else return 1;
}
student inputName(){
    student new;
    printf("Ten: ");
    gets(new.ten);
    printf("Dem: ");
    gets(new.dem);
    printf("Ho: ");
    gets(new.ho);
    return new;
}
#include "SearchBinaryTree.h"
int main(){
  tree T;
  makeNullTree(&T);
  student A[1];
  FILE *ptr = fopen("studentList.txt","r");
  if(ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  while(!feof(ptr)){
    fscanf(ptr,"%s%s%s%*c",A[0].ho,A[0].dem,A[0].ten);
    insertNode(A[0],&T);
  }
  fclose(ptr);
  printf("\n== Danh sach lop ==\n");
  inorderprint(T);
  return 0;
}
