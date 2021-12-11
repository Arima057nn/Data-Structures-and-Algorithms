#include <stdio.h>
#include <string.h>
void tower(int num, char frompeg,char topeg,char auxpeg){
  if(num == 1){
    printf("Move disk 1 from peg %c to peg %c\n",frompeg,topeg);
    return ;
  }
  tower(num-1,frompeg,topeg,auxpeg);
  printf("Move disk %d from peg %c to peg %c\n",num,frompeg,topeg);
  tower(num - 1,auxpeg,topeg,frompeg);
}

int main(){
  int num;
  printf("NUM:");
  scanf("%d",&num);
  printf("\n");
  tower(num,'A','B','C');

  return 0;
}
