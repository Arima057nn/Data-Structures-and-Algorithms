#include <stdio.h>

int main(){
  
  FILE *ifp,*ofp;
  ifp = fopen("exx1.txt","r");
  ofp = fopen("class1EF.txt","w");
  if(ifp == NULL || ofp == NULL){
    printf("cannot open the file");
    return 1;
  } 
  char c;
  while( (c=fgetc(ifp)) != EOF){
    fputc(c,ofp);
    if(c == '\n'){
      fputc('\n',ofp);
    }
  }
  fclose(ifp);
  fclose(ofp);


  return 0;
}
