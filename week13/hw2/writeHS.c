#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Max 10
typedef struct Stduent{
  char name[20];
  char id[10];
  float score;
  char address[20];
} student;

student input(){
  student new;
  char c;
  printf("Name: ");
  gets(new.name);
  printf("ID: ");
  gets(new.id);
  printf("Score: ");
  scanf("%f",&new.score);
    c = getchar();
  printf("Address: ");
  gets(new.address);
  return new;
}
int main(){
  FILE *ptr;
  student A[1];
  int i;
  ptr = fopen("Student.txt","w+");
  if(ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  for(i = 0; i < Max; i++){
      A[0] = input();
    fprintf(ptr,"%-20s %-20s %-20f %-20s\n",A[0].name,A[0].id,A[0].score,A[0].address);
  }
  return 0;
}
