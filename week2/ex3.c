#include <stdio.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
  if(argc != 3){
    printf("Wrong syntax,should be replicate <cha> <int>\n");
    return 1;
  }
    int n,i;
    n = atoi(argv[2]);
    for(i = 0;i < n;i++){
      printf("%s",argv[1]);
    }
  

  return 0;
}
