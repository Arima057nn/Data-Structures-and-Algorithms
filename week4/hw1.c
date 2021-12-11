#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char *subStr(char *s1,int offset, int number){
  int i,j=0,n;
  char *ptr,a[MAX];
  if( offset < 0 || offset > (strlen(s1)-1)){
    printf("offset value srong");
    return NULL;
  }
  n = strlen(s1) - offset;
  if( number < n){
    n = number;
  }
  ptr = (char *)malloc(n * sizeof(char));
  if( ptr == NULL){
    printf("memory alocaion error");
    return NULL;
  }
  for( i = offset; i < offset + n ; i++){
    ptr[j] = s1[i];
    j++;
  }
 
  
  return ptr;
}
int main(){
  char *PTR,a[MAX];
  int offset,number;
  printf("Input string ptr: ");
  gets(a);
  printf("Input offset: ");
  scanf("%d",&offset);
  printf("\nInput number: ");
  scanf("%d",&number);
  PTR = subStr(a,offset,number);
  puts(PTR);
  free(PTR);
  return 0;
}
