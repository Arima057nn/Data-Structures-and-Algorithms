#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 1000000
typedef phone element;

int compare(element a,element b){
  if(a > b) return 1;
  else if(a <b) return -1;
  else return 0;
}
int randome(int min,int max){
    return min + rand()%(max + 1 - min);
}
void insertionSort(element list[], int n){ // Chen
  int i,j;
  element next;
  for( i = 1; i<n;i++){
    next = list[i];
    for( j = i - 1; j>=0 && next < list[j];j--)
      list[j+1] = list[j];
    list[j+1] = next;
  }
}

void selectionSort(element a[], int n){ // lua chon
  int i,j,min;
  element tmp;
  for(i = 0; i < n -1;i++){
    min = i;
    for(j = i+1;j < n;j++)
      if(compare(a[j].AAA, a[min].AAA) == -1);
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
