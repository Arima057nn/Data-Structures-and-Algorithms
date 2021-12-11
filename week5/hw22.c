#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Num 10

typedef struct SmartPhone
{
  char model[25];
  char GB[5];     //Dung luong bo nho
  char inches[5]; //Kich thuoc man hinh
  char price[10];
} phone;

int main(){
  int i=0,n,k,j = 0;
  FILE *fp1,*fp2;
  phone *A,B[Num];
  char buff[300];
  int luaChon;
  do
    {
      printf("==================MENU=================\n");
      printf("1.file.txt -> file.dat\n");
      printf("2.read and output from file.\n");
      printf("3.Print All Nokia Database.\n");
      printf("4.Search by phone by Phone Model\n");
      printf("5.Exit");
      printf("\nBan chon? ");
      scanf("%d", &luaChon);
      if (luaChon != 2 && luaChon != 3 && luaChon != 4)
	{
	  i = 1;
	}
      if ((luaChon == 2 || luaChon == 3 || luaChon == 4) && i == 0)
	{
free(A);
	  fclose(fp1);
	  fclose(fp2);	  do
	    {
	      printf("Thuc hien 1 de chuyen sang file .dat truoc\n");
	      scanf("%d", &luaChon);
	    } while (luaChon == 2 || luaChon == 3 || luaChon == 4);
	}
      if(i = 1){
	if(luaChon == 2){
	  k = 1;
	}
	if(luaChon == 3 && k == 0){
	  printf("Thuc hien chuc nang 2 truoc");
	}
      }
      switch(luaChon)
	{
	case 1:
	  fp1 = fopen("SmartPhone.txt", "r");
	  fp2 = fopen("SmartPhone.dat", "w+b");
	  while(fgets(buff,300,fp1)!=NULL){
	    n++;
	  }
	  if(fseek(fp1,0,SEEK_SET) != 0){
	    printf("Fseek failed!\n");
	    return 1;
  }
	  A = (phone*)malloc(sizeof(phone));
	  if(fp1 == NULL)
	    {
	      printf("Cannot open the file\n");
	      return 1;
	    }
	  if (fp2 == NULL)
	    {
	      printf("Cannot create the file\n");
	      return 1;
	    }
	  for (i = 0; i < Num; i++)
	    {
	      fscanf(fp1, "%s%s%s%s%*c", A[i].model, A[i].GB, A[i].inches, A[i].price);
	      
	    }
	  fwrite(A, sizeof(phone), Num, fp2);
	  printf("Complete\n");
	  
	  break;
	case 2:
	  fp2 = fopen("SmartPhone.dat", "r+b");
	  if(fp2 == NULL)
	    {
	      printf("Cannot open the file\n");
	      return 1;
	    }    
	  int x1,x2;
	  
	  do{
	    printf("Ban muon doc tu: ");
	    scanf("%d%d",&x1,&x2);
	  }while(x1 > x2|| x1 > Num || x2 > Num);
	  
	  if(fseek(fp2,(x1-1)*sizeof(phone),SEEK_SET != 0)){
	    printf("fseek error");
	    return 1;
	  }
	  //Tai sao khong cap phat dong o day
	  n = fread(B,sizeof(phone),x2-x1+1,fp2);
	  
	 
	  break;
	case 3:	  
	  printf("%-20s %-20s %-20s %-20s\n","Model","Memory Space (GB)","Screen size (inch)","Price");
	  for(j=x1+1;j<x1+1+n;j++){
	    printf("%-20s %-20s %-20s %-20s\n",B[j].model,B[j].GB,B[j].inches,B[j].price);
	  }
	  fclose(fp2);
	  break;
	case 4:
	  printf("Tim kiem Mode: ");
	  char C[100];
	  int m = 0;
	  scanf("%s%*c",C);
	  printf("%-20s %-20s %-20s %-20s\n","Model","Memory Space (GB)","Screen size (inch)","Price");
	  for(j=0;j<Num;j++){
	    if(strcmp(C,A[j].model) == 0){
	    printf("%-20s %-20s %-20s %-20s\n\n",A[j].model,A[j].GB,A[j].inches,A[j].price);
	    m = 1;
	    }
	  }
	  if(m = 0){
	    printf("cannot find the model");
	  }
	  break;
		  
	case 5:
	  printf("Da Thoat");
	  break;    
    }
  while(luaChon != 5);

	  
  return 0;
}
