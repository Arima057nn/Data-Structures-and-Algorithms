typedef struct diary_t{
  int ngay,thang,nam,t;
  char thoitiet[50];
  char noidung[500];
}diary;
#include "genbintree.h"
#include <time.h>
#include <ctype.h>
int randome(int min, int max){
    return min+rand()%(max + 1 - min);
}
void capnhat(FILE *ptr,treetype *t){
  if(t!=NULL){
    capnhat(ptr,t->left);
    fprintf(ptr,"%d/%d/%d %s %d %s\n",t->A.ngay,t->A.thang,t->A.nam,t->A.thoitiet,t->A.t,t->A.noidung);
    capnhat(ptr,t->right);
  }
}
void incauvan(elementt A){
  char temp[500];
  strcpy(temp,A.noidung);
  temp[0]=toupper(A.noidung[0]);
  temp[strlen(temp)+2]='\0';
  temp[strlen(temp)+1]=' ';
  temp[strlen(temp)]='.';
  printf("%s",temp);
}
void indoanvan(treetype *t){
  if(t!=NULL){
    indoanvan(t->left);
    incauvan(t->A);
    indoanvan(t->right);
  }
  return;
}
void treetoarray(int *i,elementt A[],treetype *t){
  if(t!=NULL){
    treetoarray(i,A,t->left);
    A[*i]=t->A;
    (*i)++;
    treetoarray(i,A,t->right);
  }
}
void inrandom(treetype *t){
  int i=0,j;
  elementt A[100],temp;;
  treetoarray(&i,A,t);
  i--;
  while(i>=0){
    j=randome(0,i);
    displayelementt(A[j]);
    temp=A[i];
    A[i]=A[j];
    A[j]=temp;
    i--;
  }
}
int main(){
  int k,n;
  elementt A;
  treetype *root;
  char m;
  FILE *ptr;
  initialize(&root);
  srand((int)time(0));
  while(1){
    printf("\n\nMy diary\n"
	   "1.Nap noi dung\n"
	   "2.Hien thi noi dung\n"
	   "3.Them/sua\n"
	   "4.Viet nhat ki duoi dang doan van\n"
	   "5.In random\n"
	   "6.Thoat\n"
	   "Choose: ");
    scanf("%d",&k);
    switch(k){
    case 1:
      makenulltree(&root);
      if((ptr=fopen("mydiary.txt","r"))==NULL){
	printf("Cannot open mydiary.txt file!\n");
	return 1;
      }
      while(fscanf(ptr,"%d%*c%d%*c%d%*c%[^0123456789]%d%*c%[^\n]%*c",&A.ngay,&A.thang,&A.nam,A.thoitiet,&A.t,A.noidung)==6){
	A.thoitiet[strlen(A.thoitiet)-1]='\0';
	input(A,&root);
      }
      fclose(ptr);
      printf("Complete!\n");
      break;
    case 2:
      printf("Noi dung nhat ki:\n\n");
      inorderprint(root);
      break;
    case 3:
      if((ptr=fopen("newdiary.txt","w"))==NULL){
	printf("Cannot open mydiary.txt file!\n");
	return 1;
      }
      printf("Nhap vao ngay/thang/nam: ");
      scanf("%d%*c%d%*c%d%*c",&A.ngay,&A.thang,&A.nam);
      n=0;
      inordersearch(&n,&A,root);
      if(n==1){
	printf("Nhat ki da ton tai, ban co muon chinh sua noi dung? (y/n)\n");
	scanf("%c%*c",&m);
	if(m=='y'){
	  printf("Nhap noi dung chinh sua:\n");
	  gets(A.noidung);
	  inorderupdate(A,&root);
	}
      }else{
	printf("Nhap lan luot <thoi tiet> <nhiet do> <noi dung>:\n");
	scanf("%[^0123456789]%d%*c%[^\n]%*c",A.thoitiet,&A.t,A.noidung);
	A.thoitiet[strlen(A.thoitiet)-1]='\0';
	input(A,&root);
      }
      capnhat(ptr,root);
      printf("Complete!\n");
      fclose(ptr);
      break;
    case 4:
      printf("\t");
      indoanvan(root);
      printf("\n");
      printf("Complete!\n");
      break;
    case 5:
      inrandom(root);
      printf("Complete!\n");
      break;
    case 6:
      makenulltree(&root);
      return 0;
    }
  }
}
      
