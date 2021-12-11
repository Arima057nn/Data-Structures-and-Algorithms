#include <stdio.h>
#include <string.h>
#define Max 500
#define MaxL 10
int main(int n,char *m[]){
  if( n != 3 && n != 2){
    printf("Syntax error");
    return 1;
  }
  char buff[Max];
  FILE *ptr;
  int count = 1, i = 0;
  if( n == 2 ){
    ptr = fopen(m[1],"r");
    if(ptr == NULL){
      printf("cannot open the file");
      return 1;
    }
    else{
      while( fgets(buff,Max,ptr) != NULL){
        printf("%s",buff);
      }
    }
  }
  if( n == 3){
    if( strcmp(m[2],"-p") != 0){
      printf("syntax error");
      return 1;
    }
    else{
      ptr = fopen(m[1],"r");
      if(ptr == NULL){
        printf("cannot open the file");
        return 1;
      }
      else{
        while( fgets(buff,Max,ptr) != NULL){
          count ++;
          printf("%s",buff);
          if(count == MaxL){
            count = 0;
	    i++;
            printf("%45d\n",i);
	    getchar();
          }
      }
        if(count < MaxL){
          for(;count < MaxL;count++){
            printf("\n");
          }
        }
        printf("%45d\n",i+1);
      }
  }
  }
  return 0;
}
