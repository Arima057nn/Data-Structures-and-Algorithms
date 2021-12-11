#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 1000000
typedef int element;
int randome(int min,int max){
    return min + rand()%(max + 1 - min);
}
void display(element A[],int n){
  int i;
  for(i = 1; i < n; i++){
    printf("%d\t",A[i]);      
  }
}
void insertion_sort(element list[], int n){ // Chen
  int i,j;
  element next;
  for( i = 1; i<n;i++){
    next = list[i];
    for( j = i - 1; j>=0 && next < list[j];j--)
      list[j+1] = list[j];
    list[j+1] = next;
  }
}

void selection_sort(element a[], int n){ // lua c
  int i,j,min,tmp;
  for(i = 0; i < n -1;i++){
    min = i;
    for(j = i+1;j <= n - 1;j++)
      if(a[j] < a[min])
	  min = j;
    tmp = a[i];
    a[i] = a[min];
    a[min] = tmp;
  }
}
void adjust(element list[],int root, int n){
  int child, rootkey;
  element temp;
  temp = list[root];
  rootkey = list[root];
  child = 2*root;
  while( child <= n){
      if((child < n) && (list[child] < list[child + 1]))
	child++;
      if(rootkey > list[child]) break;
      else{
	list[child/2] = list[child];
	child *= 2;
      }
  }
  list[child/2] = temp; 
}

void heapSort(element list[],int n){
  int i,j;
  element temp;
  for(i = n/2 ; i>0 ; i--) adjust(list,i,n);
  for(i = n - 1; i>0 ; i--){
    temp = list[1];
    list[1] = list[i+1];
    list[i+1] = temp;
    adjust(list,1,i);
  }

}
void quickSort(element list [],int left,int right){
  int pivot,i,j;
  element temp;
  if(left < right){
    i = left;
    j = right + 1;
    pivot = list[left];
    do{
      do{
	i++;
      }while(list[i] < pivot);
      do{
	j--;
      }while(list[j] > pivot);

    }while(i<j);
    temp = list[left];
    list[left] = list[j];
    list[j] = temp;
    quickSort(list,left,j-1);
    quickSort(list,j+1,right);
  }
}
void Merge(element A[],element B[],int a,int b,element E[]){
  int i = 0,j = 0,k = 0;
  while(k < a+b){
    if(A[i] < B[j]){
      E[k] = A[i];
      i++;
    }else{
      E[k] = B[j];
      j++;
    }
    k++;
  }
}
void mergeSort(element list[],int left,int right){
  int i,k;
  k = (right + left)/2;
  element A[k],B[right - k];
  for(i = 0;i < k;i++){
    A[i] = list[i];
  }
  for(i = 0;i < right - k; i++){
    B[i] = list[k+1+i];
  }
  mergeSort(A,left,k);
  mergeSort(B,k+1,right);
  Merge(A,B,k,right - k,list);
}
int main(){
  int i,n;
  int A[Max];
  clock_t start, end;
  srand((int)time(0));
  printf("nhap n: ");
  scanf("%d",&n);
   
  start = clock();
  for(i = 0; i < n;i++){
    A[i] = randome(0,n);
  }
  insertion_sort(A,n);
  end = clock();
  printf("insertion sort: %f\n", (float)(end - start)/CLOCKS_PER_SEC);
  
  start = clock();
  for(i = 0; i < n;i++){
    A[i] = randome(0,n);
  }
  selection_sort(A,n);
  end = clock();
  printf("selection sort: %f\n", (float)(end - start)/CLOCKS_PER_SEC);
  
  start = clock();
  for(i = 1; i < n;i++){
    A[i] = randome(0,n);
  }
  heapSort(A,n);
  end = clock();
  printf("heap sort: %f\n", (float)(end - start)/CLOCKS_PER_SEC);
  
  start = clock();
  for(i = 0; i < n;i++){
    A[i] = randome(0,n);
  }
  quickSort(A,0,n);
  end = clock();
  printf("quick sort: %f\n", (float)(end - start)/CLOCKS_PER_SEC);

  //start = clock();
  for(i = 0; i < n;i++){
    A[i] = randome(0,n);
  }
  //mergeSort(A,0,n);
  //end = clock();
  //printf("merge sort: %f\n", (float)(end - start)/CLOCKS_PER_SEC);
  //display(A,n);
  return 0;
}
