#include <stdio.h>

typedef struct Students{
  char NAME[20];
  char STT[20];
  char MSSV[20];
  char SDT[20];
  float Scout;
  
} SV;

int main(){
  FILE *fp1 , *fp2;
  int i = 0 , j;
  fp1 = fopen("SinhVien.txt","r");
  fp2 = fopen("Bangdiem.txt","w");
  if(fp1 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  if(fp2 == NULL){
    printf("Cannot open the file");
    return 1;
  }
  SV A[100];
  while(!feof(fp1)){
    fscanf(fp1,"%s%s%s%s%*c",A[i].STT,A[i].NAME,A[i].MSSV,A[i].SDT);
    i++;
  }
  printf("Input Score\n");
  for(j=1;j<i;j++){
    printf("SV %s: ",A[j].NAME);
    scanf("%f",&A[j].Scout);
    fprintf(fp2,"%-10s %-20s %-10s %-10s %-10.2f\n",A[j].STT,A[j].NAME,A[j].MSSV,A[j].SDT,A[j].Scout);
  }
  fclose(fp1);
  fclose(fp2);
  return 0;
}
