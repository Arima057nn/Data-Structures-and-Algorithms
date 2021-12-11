#include <stdio.h>
#define MAX 80

int main(){
  FILE *ptr1,*ptr2;
  ptr1 = fopen("lab1.txt","r");
  ptr2 = fopen("lab2.txt","w");
  if( ptr1 == NULL || ptr2 == NULL){
    printf("Cannot open the file");
    return 1;
    
  }
  int num;
  char buff[100];
  while(!feof(ptr1)){
    num = fread(buff,sizeof(char),101,ptr1);
    fwrite(buff,sizeof(char),num,ptr2);
  }
  printf("%s",buff);
  return 0;
}
