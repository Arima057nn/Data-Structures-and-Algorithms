#include <stdio.h>

#define Notfound -1
typedef int Element;

int BinarySearch(Element A[],Element X, int N){
  int Low,Mid,High;
  Low = 0; High = N - 1;
  while( Low <= High){
    Mid = (Low + High) / 2;
    if(A[Mid] < X)
      Low = Mid + 1;
    else if(A[Mid] > X)
      High = Mid - 1;
    else return Mid;
  }
  return Notfound;
}

int main(){
  static int A[] = {1,3,5,7,13,17};
  int SizeofA = sizeof(A) / sizeof(A[0]);
  int i;
  for(i = 0; i <20 ; i++)
    printf("BinarySearch of %d return %d\n",i,BinarySearch(A,i,SizeofA));
  return 0;
}
