typedef int element;
#include "ListStack.h"
#include <string.h>

int main(){
  int carry = 0,a,b;
  int A = 0,B = 0;
  char M[50];
  node *T1, *T2, *T3;
  printf("Nhap so thu nhat: ");
  scanf("%s%*c", M);
  initialize(&T1);
  for(int i = 0; i < strlen(M); i++) {
    Push(M[i] - '0',&T1);
    A = A * 10 + (M[i] - '0');
  }
  printf("Nhap so thu hai: ");
  scanf("%s%*c", M);
  initialize(&T2);
  for(int i = 0; i < strlen(M); i++) {
    Push(M[i] - '0',&T2);
    B = B * 10 + (M[i] - '0');
  }
  initialize(&T3);

    while(!isEmpty(T1) || !isEmpty(T2)){
    if((a = Pop(&T1)) == -9999) a = 0;
    if((b = Pop(&T2)) == -9999) b = 0;
    
    if(a + b + carry > 10){
      Push(a + b + carry - 10,&T3);
      carry = 1;
    }
    else{
      Push( a + b + carry,&T3);
      carry = 0;
    }
    
    if(carry == 1) Push(carry,&T3);
    }
    printf("\nSum = ");
    while(!isEmpty(T3)) printf("%d", Pop(&T3));
    
  /*
  
  if(A >= B){
  while(!isEmpty(T1) || !isEmpty(T2)){
    if((a = Pop(&T1)) == -9999) a = 0;
    if((b = Pop(&T2)) == -9999) b = 0;
    if(a + carry < b){
      Push(a + 10 - b + carry,&T3);
      carry = -1;
    }else{
      Push(a + carry - b,&T3);
      carry = 0;
    } 
  }
  printf("\n");
  while(!isEmpty(T3)) printf("%d", Pop(&T3));
  }else{
    while(!isEmpty(T1) || !isEmpty(T2)){
      if((a = Pop(&T2)) == -9999) a = 0;
      if((b = Pop(&T1)) == -9999) b = 0;
      if(a + carry < b){
	Push(a + 10 - b + carry,&T3);
	carry = -1;
      }else{
	Push(a + carry - b,&T3);
	carry = 0;
      } 
    }
    printf("\n-");
    while(!isEmpty(T3)) printf("%d", Pop(&T3));
    
  }
  
  */
  return 0;
}
