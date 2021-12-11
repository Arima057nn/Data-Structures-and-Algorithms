#include <stdio.h>

typedef struct phoneDB{
  int maSP;
  char ten[20];
  int gia;
  int soluong;
} phone;
void fileText(FILE *ptr){
    phone A[1];
    char c;
    int i;
    while(1){
	  printf("Nhap thong tin nguoi dung: \n");
	  do{ 
	    printf("Ma san pham: ");
	    scanf("%d",&A[i].maSP);
	  }while(A[i].maSP < 0);
	  if(A[i].maSP == 0) break;
	  printf("Ten san pham: ");
	  c = getchar();
	  gets(A[i].ten);

	  do{
	    printf("Gia: ");
	    scanf("%d",&A[i].gia);
	  }while(A[i].gia < 0);
	  do{
	    printf("So luong: ");
	    scanf("%d",&A[i].soluong);
	  }while(A[i].soluong < 0);
	   fprintf(ptr,"%d %s %d %d\n",A[i].maSP,A[i].ten,A[i].gia,A[i].soluong);
	   i++;
	}
}
int main(){
    FILE *ptr;
    ptr = fopen("hihi.txt","w");
    if(ptr == NULL){
        printf("Cannot open the file");
        return 1;
    }
    fileText(ptr);
    fclose(ptr);
    return 0;
}