#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define number 100
typedef struct phone_t{
  char name[50];
  int memory;
  float size;
  int price;
}phone;
int main(){
  char k,C[300];
  FILE *ptr1,*ptr2;
  phone *A,B[number];
  int i,n=0,j;
menu:
  printf("\nMenu:\n");
  printf("1.Import DB from text\n");
  printf("2.Import from DB\n");
  printf("3.Print all database\n");
  printf("4.Search by phone by Phone Model\n");
  printf("5.Exit\n");
  printf("Choose: ");
choose:
  __fpurge(stdin);
  scanf("%c",&k);
  __fpurge(stdin);
  switch(k){
  case '1':
    if((ptr1=fopen("SmartPhone.txt","r"))==NULL){
      printf("Cannot open PhoneDB.txt file!\n");
      return 1;
    }
    if((ptr2=fopen("SmartPhone.dat","wb"))==NULL){
      printf("Cannot create PhoneDB.dat file!\n");
      return 1;
    }
    while(fgets(C,300,ptr1)!=NULL){
      n++;
    }
    if(fseek(ptr1,0,SEEK_SET)!=0){
      printf("fseek ERROR!\n");
      return 1;
    }
    if((A=(phone *)malloc(n*sizeof(phone)))==NULL){
      printf("Memory allocation error!\n");
      return 1;
    }
    for(i=0;i<n;i++){
      fscanf(ptr1,"%*c%s%d%f%d%*c",A[i].name,&A[i].memory,&A[i].size,&A[i].price);
    }
    fwrite(A,sizeof(phone),n,ptr2);
    n=0;
    free(A);
    fclose(ptr1);
    fclose(ptr2);
    printf("Complete!\n");
    goto menu;
  case '2':
    if((ptr1=fopen("SmartPhone.dat","rb"))==NULL){
      printf("Cannot open PhoneDB.dat file!\n");
      return 1;
    }
    printf("Choose starting position:\n1.Beginning\n2.End\n");
  re:
    scanf("%c",&k);
    __fpurge(stdin);
    if(k!='1'&&k!='2'){
      printf("Please choose only 1-2: \n");
      goto re;
    }
    printf("Choose the number of records from %s\n",k=='1'?"beginning":"end");
    scanf("%d",&j);
    if(k=='1'){
      if(fseek(ptr1,(j-1)*sizeof(phone),SEEK_SET)!=0){
	printf("fseek ERROR!\n");
	return 1;
      }
    }else{
      if(fseek(ptr1,-j*sizeof(phone),SEEK_END)!=0){
	printf("fseek ERROR!\n");
	return 1;
      }
    }
    n=fread(B,sizeof(phone),number,ptr1);
    fclose(ptr1);
    printf("Complete!\n");
    goto menu;
  case '3':
    if(n==0){
      printf("Please read database first!\n");
      goto menu;
    }
    printf("- %-25s%-20s%-20s%s\n","Model","Memory Space (GB)","Screen size (inch)","Price");
    for(i=0;i<n;i++){
      printf("- %-25s%-20d%-20.2f%d\n",B[i].name,B[i].memory,B[i].size,B[i].price);
    }
    goto menu;
  case '4':
    if(n==0){
      printf("Please read database first!\n");
      goto menu;
    }
    j=0;
    printf("Search: \n");
    scanf("%s%*c",C);
    printf("- %-25s%-20s%-20s%s\n","Model","Memory Space (GB)","Screen size (inch)","Price");
    for(i=0;i<n;i++){
      if(strcmp(C,B[i].name)==0){
        printf("- %-25s%-20d%-20.2f%d\n",B[i].name,B[i].memory,B[i].size,B[i].price);
        j=1;
      }
    }
    if(j==0){
      printf("Cannot find this phone!\n");
    }
    goto menu;
  case '5':
    return 0;
  default:
    printf("Please choose only 1-5\n");
    goto choose;
  }
}

