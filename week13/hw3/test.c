#include <stdio.h>
#include <string.h>
typedef struct phoneDB{
  char model[30];
  int size;
  int memory;
  char price[15];
} phone;
typedef phone element;

void display(element A[],int n){
  int i;
  for(i = 1; i < n; i++){
    printf("%-20s %-20d %-20d %-20s\n",A[i].model,A[i].size,A[i].memory,A[i].price);      
  }
}
void adjust(element list[],int root, int n){
  int child;
  char rootkey[20];
  element temp;
  temp = list[root];
  strcpy(rootkey,list[root].model);
  child = 2*root;
  while( child <= n){
      if((child < n) && (strcmp(list[child].model,list[child + 1].model) < 0))
	child++;
      if(strcmp(rootkey,list[child].model) > 0) break;
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
int main(){
  FILE *ptr = fopen("PhoneDB.dat","rb");
  phone A[20];
  phone B[1];
  int i = 1;
  if(ptr == NULL){
    printf("Cannot open the file\n");
    return 1;
  }
  
  while( fread(B,sizeof(phone),1,ptr) != 0){
    i++;
    strcpy(A[i].model , B[0].model);
    A[i].size =  B[0].size;
    A[i].memory = B[0].memory;
    strcpy(A[i].price , B[0].price);

  }
  fclose(ptr);
  display(A,i);
  printf("=============\n");
  heapSort(A,i);
  display(A,i);
  return 0;
}
