#include <stdio.h>
#include <stdlib.h>
#define NUM 10
typedef struct PhoneAddress_t{
  char name[25];
  char tel[25];
  char mail[25];
}phone;

int main(){
  FILE *ptr;
  phone a[NUM];
  int i,irc;

  if( (ptr = fopen("phone.dat","r+b")) == NULL){
	printf("Cannot open the file");
	return 1;
  }
  fread(a,sizeof(phone),NUM,ptr);
  printf("\n\n");
  printf("%-20s %-20s %-20s\n","Name","Tel","Mail");
  for(i=0;i<NUM;i++){
    printf("%-20s %-20s %-20s\n",a[i].name,a[i].tel,a[i].mail);
  }
  fclose(ptr);
  return 0;
}
