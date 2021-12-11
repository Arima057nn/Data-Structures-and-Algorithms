#include <string.h>
#include <stdio.h>
#define Max 50
typedef struct Student{
  char ten[10];
  char dem[10];
  char ho[10];
} student;

int TraVe(student x,student e){
  if( strcmp(x.ten, e.ten) < 0) return 1;
  if( strcmp(x.ten , e.ten) > 0) return -1;
  if( strcmp(x.ten, e.ten) == 0){
    if(strcmp(x.dem, e.dem) < 0) return 1;
    if( strcmp(x.dem , e.dem) > 0) return -1;
    if( strcmp(x.dem, e.dem) == 0){
      if(strcmp(x.ho, e.ho) < 0) return 1;
      if( strcmp(x.ho , e.ho) > 0) return -1;
      if( strcmp(x.ho, e.ho) ==  0) return 0;
  }
  }
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

#include "SearchBinaryTree2.h"

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
   // printf("%s\t%s\t%s\n",A[0].ho,A[0].dem,A[0].ten);
  }
  fclose(ptr);
  printf("\n== Danh sach lop ==\n");
  printf("\n");
  //printf("Searching: \n");
  
  inorderprint(T);
  printf("Searching: \n");
  if(Searching(inputName(),&T) == 1){
  printf("Tim thay !\n");
  }else printf("Khong tim thay\n");
  return 0;
}
