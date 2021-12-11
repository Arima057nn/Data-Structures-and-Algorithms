#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct TuDien{
  int stt;
  char ND[100]; 
} TD;
int main(){
  FILE *ptr,*fp;
  TD *a;
  int i = 0,num = 0;
  int n, m;
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
  if(( a = (TD*)malloc( num * sizeof(TD))) == NULL){
    printf("Error");
    return 1;
  }
  rewind(ptr);
  
  while( fgets(a[i].ND,500,ptr) != NULL){
    i++;
  }
  num = i;
  fwrite(a,sizeof(TD),num,fp);
  fread(a,sizeof(TD),num,fp);
  //In ra toan bo noi dung trong file .dat
  printf("The begin and end number you want to display?\n");
  scanf("%d%d",&n,&m);
  printf("=========\n");
  for(i = n - 1; i <  m ; i++){
    printf("%d\t%s\n",i+1,a[i].ND);
  }
  
  free(a);
  fclose(ptr);
  fclose(fp);

  return 0;
}
