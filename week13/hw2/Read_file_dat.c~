#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hs{
  char ten[10];
  char dem[10];
  char ho[10];
} HS;
typedef struct Stduent{
  HS name;
  char id[10];
  float score;
  char address[20];
} student;


int main(){
  FILE *ptr;
  phone A[1];
  ptr = fopen("Student.dat","r+b");
  if(ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  while( fread(A,sizeof(phone),1,ptr) != 0){
    printf("%-6s %-6s %-6s %-15s %-15g %-15s\n",A[0].name.ho,A[0].name.dem,A[0].name.ten,A[0].id,A[0].score,A[0].address); 
      }
  fclose(ptr);
  return 0;
}
