#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct hahi
{
  char mssv[10];
  char name[30];
  int age;
  float score;
  char address[30];
} hihi;

int main(){
  hihi A[1];
  FILE *ptr = fopen("hihi.txt", "r");
  if(ptr == NULL){
    printf("Cannot open the file\n");
    return 1;
  }
  while( fscanf(ptr,"%[^-] %*c %d %*c %[^-] %*c %f %*c %[^\n]%*c\n",A[0].mssv,&A[0].age,A[0].name,&A[0].score,A[0].address) == 5){
    printf("%-10s %-10d %-20s %-15g  %-20s\n",A[0].mssv,A[0].age,A[0].name,A[0].score,A[0].address);
  }
  fclose(ptr);


    return 0;
}
