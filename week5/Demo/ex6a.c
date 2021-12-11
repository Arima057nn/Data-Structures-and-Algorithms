#include <stdio.h>
#include <stdlib.h>
#define NUM 10
typedef struct Information{
  char name[25];
  char tel[25];
  char mail[25];
} phone;
int main(){
  int i,irc;
  phone a[NUM];
  FILE *ptr;
  printf("Information:");
  for(i=0;i<NUM;i++){
    printf("Name[%d]: ",i+1);
    gets(a[i].name);
    printf("Tel[%d]: ",i+1);
    gets(a[i].tel);
    printf("Mail[%d]: ",i+1);
    gets(a[i].mail);
  }
  if( (ptr = fopen("phone.dat","w+b")) == NULL){
	printf("Cannot open the file");
	return 1;
  }
  
  irc =  fwrite(a,sizeof(phone),NUM,ptr);
  printf("\n\n");
  printf("%-20s %-20s %-20s\n","Name","Tel","Mail");
  for(i=0;i<NUM;i++){
    printf("%-20s %-20s %-20s\n",a[i].name,a[i].tel,a[i].mail);
  }
  fclose(ptr);  
  return 0;
}
