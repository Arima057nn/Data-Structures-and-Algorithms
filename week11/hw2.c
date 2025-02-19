#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 2000000

int LinearSearch(int A[],int k){
  int i = 0;
  while(i < Max && A[i] != k){
    i++;
  }
  if(i < Max) return i;
  else return -1;
}

int LinearSentinelSearch(int A[],int k){
  int i = 0;
  A[Max] = k;
  while(A[i] != k){
    i++;
  }
  if(i < Max) return i;
  else return -1;
}

int BinarySearch(int A[],int first,int last,int k){
  int mid =( first + last)/2;
  if(first == last) return -1;
  if(A[mid] < k) return BinarySearch(A,mid+1,last,k);
  else if(A[mid] > k) return BinarySearch(A,first,mid,k);
  else return mid;
}

int main(){
  int A[Max],k;
  clock_t start, end;
  int i = 0, choose;
  for(i = 0; i < Max; i++){
    A[i] = 2*i + 3;
  }
  printf("Entet key: ");
  scanf("%d",&k);
  while(1){
    printf("=========MENU=========\n");
    printf("1. Sequentail search\n");
    printf("2. Sequentail search using Sentinel\n");
    printf("3. Binary search\n");
    printf("4. Exit...\n");
    printf("--> Choose: ");
    scanf("%d",&choose);
    switch (choose){
    case 1:
      start = clock();
      printf("\n%d\n",LinearSearch(A,k));
      end = clock();
      printf("tieu ton thoi gian la: %f\n", (float)(end - start)/CLOCKS_PER_SEC);
      break;
    case 2:
      start = clock();
      printf("\n%d\n",LinearSentinelSearch(A,k));
      end = clock();
      printf("tieu ton thoi gian la: %f\n", (float)(end - start)/CLOCKS_PER_SEC );
      break;
    case 3:
      start = clock();
      printf("\n%d\n",BinarySearch(A,0,Max - 1,k));
      end = clock();
      printf("tieu ton thoi gian la: %f\n",(float)(end - start)/CLOCKS_PER_SEC);
      break;
    case 4:
      printf("\nExit !");
      exit(0);
    default:
      break;
    }
  }
  return 0;
}
