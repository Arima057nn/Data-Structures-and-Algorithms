#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define Num 10
#define NumL 3
typedef struct SmartPhone
{
  char model[25];
  char GB[5];     //Dung luong bo nho
  char inches[5]; //Kich thuoc man hinh
  char price[10];
} phone;

int main()
{
  int i,j=0, n = 0;
  int count = 0,k = 0;
  phone *a,b[Num];
  char c[25];
  char buff[500];
  FILE *fp1, *fp2;
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
	  do
	    {
	      printf(" ");
	      scanf("%d", &luaChon);
	    } while (luaChon == 2 || luaChon == 3 || luaChon == 4);
	}
      switch(luaChon)
	{
	case 1:
	  fp1 = fopen("SmartPhone.txt", "r");
	  fp2 = fopen("SmartPhone.dat", "wb");
	  while(fgets(buff,500,fp1)!=NULL){
      n++;
    }
	  if (fp1 == NULL)
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
	     fscanf(fp1, "%s%s%s%s%*c", a[i].model, a[i].GB, a[i].inches, a[i].price);
	     
	    }
	  fwrite(a, sizeof(phone), Num, fp2);
	  printf("Complete\n");
	  free(a);
    fclose(fp1);
    fclose(fp2);
	case 2:
	  /* int k = 1;
	  Printf("Chon so phan tu ban muon doc");
	  if( k == 1){
	    fp2 = fopen("SmartPhone.dat", "w+b");
	     if(fp2 == NULL)
	       {
		 printf("Cannot open the file");
		 return 1;
	       }
	       }*/
	  break;
	case 3:
	  
	  fread(b, sizeof(phone), Num, fp2);
	  for (i = 0; i < Num; i++)
	    {
	      printf("%-25s %-15s %-20s %-20s\n", b[i].model, b[i].GB, b[i].inches, b[i].price);
	      count++;
	      if(count == NumL){
		k++;
		count = 0;
		printf("%45d\n",k);
		getchar();
	      }
	    }
	  if(count <NumL){
	    for(;count <NumL;count++){
	      printf("\n");
	    }
	  }
	  printf("%45d\n",k+1);
	  break;
	case 4:
		printf("Search: ");
	  gets(c);
	  printf("\n");
	  for(i = 0;i< Num;i++){
	    if( strcmp( a[i].model,c) == 0){
	      
	      printf("%-25s %-15s %-20s %-20s\n", a[i].model, a[i].GB, a[i].inches, a[i].price);
	      j = 1;
	    }
	  }
	  if(j == 0){
	    printf("cannot find  this phone\n");
	  }
	      break;
	  
	case 5:
	  printf("Da thoat chuong trinh");
	  break;
	default:
	  printf("Khong co chuc nang nay");
	  break;
	}
    }
  while (luaChon != 5)
    ;
  free(a);
  fclose(fp1);
  fclose(fp2);
  
  
  return 0;
}
