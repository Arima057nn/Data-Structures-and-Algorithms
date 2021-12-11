#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *str1,char *str2){
  int len1,len2;
  len1 = strlen(str1);
  len2 = strlen(str2);
  char *resuft;
  resuft = (char*)malloc((len1 + len2 + 1)*sizeof(char));
  if(resuft == NULL){
    printf("Allocation failed");
    return NULL;
  }
  strcpy(resuft,str1);
  strcpy(resuft + len1, str2);
  return resuft;
}

int main(){
  char str1[100],str2[100];
  char *cat_str;
  printf("Enter to string\n");
  gets(str1);
  gets(str2);
  cat_str = my_strcat(str1,str2);
  if(cat_str == NULL){
    printf("problem allocating memory");
    return 1;
  }
  printf("\n%s",cat_str);
  free(cat_str);

  return 0;
}
