#include <stdio.h>
#include <stdlib.h>

int main(){
  int num;
  FILE *ptr;
  ptr = fopen("demo.txt","r");
  char buff[200];
  if(ptr == NULL){
    printf("Cannot open the file");
    return 1;
  }
  num = fread(buff,sizoef(char),200,
  return 0;
}
