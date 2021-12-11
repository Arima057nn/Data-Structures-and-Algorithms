#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 10
typedef struct Information{
  char name[25];
  char tel[25];
  char mail[25];
} phone;

int main(){
  FILE *ptr;
  int i,n = 3,m = 5,*irc;
  phone *a;
  if( (ptr = fopen("phone.dat","r+b")) == NULL){
	printf("Cannot open the file");
	return 1;
  }
  a = (phone*)malloc((m-n+1) * sizeof(phone));
  if((fseek(ptr,5*sizeof(phone),SEEK_SET)) != NULL){
    printf("Error");
    return 1;
  }
  fread(a,sizeof(phone),m-n+1,ptr);
  for(i=0;i<m-n+1;i++){
    printf("Name[%d]: ",i+1);
    gets(a[i].name);
    printf("Tel[%d]: ",i+1);
    gets(a[i].tel);
    printf("Mail[%d]: ",i+1);
    gets(a[i].mail);
  }
  if((fseek(ptr,5*sizeof(phone),SEEK_SET)) != NULL){
    printf("Error");
    return 1;
  }
  fwrite(a,sizeof(phone),m-n+1,ptr);
  free(a);
  fclose(ptr);
  return 0;
}
