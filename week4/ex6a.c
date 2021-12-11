#include <stdio.h>
#include <stdlib.h>
#define NUM 10


typedef struct PhoneAddress_t{
  char name[25];
  char tel[25];
  char mail[25];
}phone;

int main(){
  int i,irc,n;
  phone a[NUM];
  FILE *ptr;
  printf("Input contact : ");
  for(i=0;i<NUM;i++){
    printf("Name: ");
    gets(a[i].name);  
    printf("tel: ");
    gets(a[i].tel);
    printf("email: ");
    gets(a[i].mail);
  }
  ptr = fopen("PhoneAddress.dat","w+b");
  if(ptr == NULL){
    printf("cannot open the file");
    return 1;
  }
  irc = fwrite(a,sizeof(phone),NUM,ptr);
  printf("Fread return code = %d\n",irc);
  printf("%-20s %-15s %-20s\n","Name","Tel","Mail");
  for(i=0;i<NUM;i++){
    printf("%-20s %-15s %-20s\n",a[i].name,a[i].tel,a[i].mail);

     
  }
  fclose(ptr);
  
  return 0;
}
