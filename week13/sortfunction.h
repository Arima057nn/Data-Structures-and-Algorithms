#include <stdio.h>
#include <time.h>
#include <stdlib.h>
typedef phone element;
int randome(int min, int max){
    return min+rand()%(max + 1 - min);
}
int compare(element a,element b){
  if(a.price==b.price){
    return 0;
  }
  if(a.price>b.price){
    return 1;
  }
  if(a.price<b.price){
    return -1;
  }
}
void insertion_sort(int A[],int n){
  int i,j;
  int next;
  for(i=1;i<n;i++){
    next=A[i];
    for(j=i-1;j>=0&&next<A[j];j--){
      A[j+1]=A[j];
    }
    A[j+1]=next;
  }
}
void selection(int A[],int n){
  int i,j,min,tmp;
  for(i=0;i<n-1;i++){
    min=i;
    for(j=i+1;j<=n-1;j++){
      if(A[j]<A[min]){
	min=j;
      }
    }
    tmp=A[i];
    A[i]=A[min];
    A[min]=tmp;
  }
}
void adjust(element list[],int root,int n){
  int child,rootkey;
  element temp;
  temp=list[root];
  rootkey=list[root].price;
  child=2*root;;
  while(child<=n){
    if((child<n)&&(list[child].price<list[child+1].price)){
      child++;
    }
    if(rootkey>list[child].price){
      break;
    }else{
      list[child/2]=list[child];
      child*=2;
    }
  }
  list[child/2]=temp;
}
void heapsort(element list[],int n){
  int i,j;
  element temp;
  for(i=n/2;i>0;i--){
    adjust(list,i,n);
  }
  for(i=n-1;i>0;i--){
    temp=list[1];
    list[1]=list[i+1];
    list[i+1]=temp;
    adjust(list,1,i);
  }
}
void quicksort(int list[],int left,int right){
  int pivot,i,j;
  int temp;
  if(left<right){
    i=left;
    j=right+1;
    pivot=list[left];
    do{
      do{
	i++;
      }while(list[i]<pivot);
      do{
	j--;
      }while(list[j]>pivot);
      if(i<j){
	temp=list[i];
	list[i]=list[j];
	list[j]=temp;
      }
    }while(i<j);
    temp=list[left];
    list[left]=list[j];
    list[j]=temp;
    quicksort(list,left,j-1);
    quicksort(list,j+1,right);
  }
}
