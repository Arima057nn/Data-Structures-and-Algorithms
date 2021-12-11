#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char My_strcat(char *str1,char *str2){
  int len1,len2;
  len1 = strlen(str1);
  len2 = strlen(str2);
  char *resuft;
  resuft = (char*)malloc((len1 + len2 + 1) *sizeof(char));
  if(resuft == NULL){
    printf("Allocation failed! check memory");
    return NULL;
  }
  strcpy(resuft,str1);
  strcpy(resuft + len1,str2);

  return resuft;
}
int main(){
  char str1[100], str2[100];
  char *cat_str;

  printf("Please enter to string\n");
  scanf("%100s",str1);
  scanf("%100s",str2);
  cat_str = My_strcat(str1,str2);
  if(cat_str == NULL){
    printf("Problem allocating momory");
    return 1;

  }

  printf("The concatenation of %s and %s is %s",str1,str2,cat_str);
  free(cat_str);
  return 0;
}
