#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TuDien{
  char stt[10];
  char ND[50]; 
} TD;
int main(){
  FILE *ptr,*fp;
  TD *a,*b;
  int i = 0,k = 0,num = 0;
  ptr = fopen("vnedict.txt","r");
  fp = fopen("vnedict.dat","w+b");
  if(ptr == NULL || fp == NULL){
    printf("Cannot open the file");
    return 1;
  }
  char buff[100];
  while( fgets(buff,100,ptr) != NULL){
    num ++;
  }
  printf("%d",num);
  a = (TD*)malloc( num * sizeof(TD));
  b = (TD*)malloc( num * sizeof(TD));
  rewind(ptr);
  
  while( fgets(a[i].ND,100,ptr) != NULL){
    strcpy(a[i].stt , (char)i);
    i++;
  }
  num = i - 1;
  
  for(i = 0 ; i < num ; i++){
    strcpy(b[i].stt , a[i].stt);
    strcpy(b[i].ND , a[i].ND);
  }
  fwrite(b,sizeof(TD),num,fp);
  //In ra toan bo noi dung trong file .dat
  fread(b,sizeof(TD),num,fp);
  for(i = 0; i <  num ; i++){
    printf("%s\t%s\n",b[i].stt,b[i].ND);
  }
  
  free(a);
  free(b);
  fclose(ptr);
  fclose(fp);

  return 0;
}
