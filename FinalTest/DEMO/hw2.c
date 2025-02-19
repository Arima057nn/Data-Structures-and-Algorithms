#include <stdio.h>
#include <string.h>
typedef struct hs{
  char ten[10];
  char dem[10];
  char ho[10];
} HS;
typedef struct Stduent{
  HS name;
  char id[10];
  float score;
  char address[20];
} student;

student input(){
  student new;
  char c;
  printf("Name: ");
  scanf("%s%s%s",new.name.ho,new.name.dem,new.name.ten);
  //gets(new.name->ho);
  printf("ID: ");
  c = getchar();
  gets(new.id);
  printf("Score: ");
  scanf("%f",&new.score);
  printf("Address: ");
  c = getchar();
  gets(new.address);
  return new;
}

int compare(student x,student e){
  if( strcmp(x.name.ten, e.name.ten) < 0) return 1;
  if( strcmp(x.name.ten , e.name.ten) > 0) return -1;
  if( strcmp(x.name.ten, e.name.ten) == 0){
    if(strcmp(x.name.dem, e.name.dem) < 0) return 1;
    if( strcmp(x.name.dem , e.name.dem) > 0) return -1;
    if( strcmp(x.name.dem, e.name.dem) == 0){
      if(strcmp(x.name.ho, e.name.ho) < 0) return 1;
      if( strcmp(x.name.ho , e.name.ho) > 0) return -1;
      if( strcmp(x.name.ho, e.name.ho) ==  0) return 0;
    }
  }
}

int TraVeDiem(float score, student e){
  if(score >= e.score) return 1;
  else return 0;
}

#include "GenBST.h"

int main(){
  FILE *ptr,*fptr;
  student A[1],B[1];
  int i = 0,k;
  float score;
  int luaChon;
  char s[30],c;
  tree T,found;
  makeNullTree(&found);
  makeNullTree(&T);
  printf("==================MENU=================\n");
  printf("1.Import data from file text\n");
  printf("2.Diplay\n");
  printf("3.Insert\n");
  printf("4.Delete\n");
  printf("5.Search\n");
  printf("6.Update\n");
  printf("7.Higher and Lower\n");
  printf("8.Save to File\n");
  printf("9.Quit\n");
  printf("=============");
  while(1){
    printf("\n--->Ban chon? ");
    scanf("%d",&luaChon);
    switch (luaChon){
    case 1:
      ptr = fopen("Student.txt","r");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      while(!feof(ptr)){
	fscanf(ptr,"%s%s%s%s%f%s%*c",A[0].name.ho,A[0].name.dem,A[0].name.ten,A[0].id,&A[0].score,A[0].address);
	insertNode(A[0],&T);
      }
      printf("\ncomplete!\n");
      fclose(ptr);
      break;
    case 2:
      printf("--> Node - Left - Right\n");
      preorderprint(T);
      printf("\n--> Left - Node - Right\n");
      inorderprint(T);
      printf("\ncomplete!\n");
      break;
    case 3: 
      insertNode(input(),&T);
      printf("\ncomplete!\n");
      break;  
    case 4:
      printf("Nhap ten muon xoa\n");
      scanf("%s%s%s%*c",A[0].name.ho,A[0].name.dem,A[0].name.ten);
      A[0].score = 0;
      strcmp(A[0].id,"0");
      strcmp(A[0].address,"0");
      DeleteNode(A[0],&T);
      printf("\ncomplete!\n");
      break;
    case 5:
      printf("Nhap ten de tim kiem: ");
      scanf("%s%s%s%*c",B[0].name.ho,B[0].name.dem,B[0].name.ten);
      
      found = Searching(B[0],T);
      if(found == NULL) printf("Khong tim thay\n");
      else printf("=== Tim thay ===\n%s %s %s %-20s %-20g %-20s\n",found->data.name.ho,found->data.name.dem,found->data.name.ten,found->data.id,found->data.score,found->data.address);
      break;
    case 6:
      printf("Nhap ten de tim kiem: ");
      scanf("%s%s%s",B[0].name.ho,B[0].name.dem,B[0].name.ten);
      /* found = Searching(B[0],T);
	 if(found == NULL) printf("Khong tim thay\n");
	 else{
	 DeleteNode(B[0],&T);
	 printf("Tim thay. Update: ");
	 insertNode(input(),&T);
	 }*/
      k = 0;
      SEARCHING(&k,B[0],T);
      if(k == 0) printf("Khong tim thay");
      else{
	DeleteNode(B[0],&T);
	insertNode(input(),&T);
      }
      break;
    case 7: 
      printf("Nhap Score: ");
      scanf("%f",&score);
      printf(" === So gia tri lon hon hoac bang %g la: %d\n",score,higherThankey(score,T));
      higher(score,T);
      printf(" === So gia tri nho hon %g la: %d\n",score,lowerThankey(score,T));
      lower(score,T);
      break;
    case 8:
    //Doc vao file txt
      ptr = fopen("StudentList.txt","w");
      if(ptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      OutPutFile(ptr,T);
     
      fclose(ptr);
      
      //Doc vao file dat
      fptr = fopen("Student.dat","wb");
      if(fptr == NULL){
	printf("cannot open the file");
	return 1;
      }
      OutPutFile2(fptr,T);
      printf("\ncomplete!\n");
      fclose(fptr);
      break;
      
    case 9:
      printf("Quit !!\n");
      freeTree(T);
      exit(0);
      break;
    default:
      printf("HAY CHON TU 1 - 9");
      break;
    }
  }
 

  return 0;
}
