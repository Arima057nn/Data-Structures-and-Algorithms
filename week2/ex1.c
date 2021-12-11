#include <stdio.h>
#include <string.h>
void replace_char(char *str,char c1,char c2){
  int i=0;
  for(i=0;i<strlen(str);i++){
    if(str[i]==c1){
      str[i]=c2;
    }
  }
}
int main(){
  char A[100],c1,c2;
  printf("\nNhap chuoi, chu cai thay the, chu cai muon thay the:\n");
  fgets(A,100,stdin);
  __fpurge(stdin);
  c1=getchar();
  __fpurge(stdin);
  c2=getchar();
  replace_char(A,c1,c2);
  printf("Result: \n");
  puts(A);
  return 0;
}
