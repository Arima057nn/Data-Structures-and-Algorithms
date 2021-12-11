#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char *str;
  str = (char*)malloc(15);
  strcpy(str,"PhamTienDung");
  printf(" %s\tDia chi: %u\n",str,str);
  str = (char*)realloc(str,25);
  strcat(str,".com");
  printf(" %s\tDia chi: %u",str,str);
  free(str);
  return 0;
}
