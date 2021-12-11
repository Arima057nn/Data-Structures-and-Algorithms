#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define number 100
typedef struct phone_t{
  char name[50];
  int memory;
  float size;
  char price;
}phone;
typedef struct node_t{
  phone A;
  struct node_t *next;
}node;
node *root=NULL,*cur=NULL,*prev=NULL;
node *makenewnode(phone A){
  node *new=(node *)malloc(sizeof(node));
  new->A=A;
  new->next=NULL;
  return new;
}
phone readnode(FILE *ptr){
  phone A[1];
  fread(A,sizeof(phone),1,ptr);
  return A[0];
}
phone scanfnode(FILE *ptr){
  phone A[1];
  fscanf(ptr,"%s%d%f%s%*c",A[0].name,&A[0].memory,&A[0].size,&A[0].price);
  return A[0];
}
phone inputnode(){
  phone A[1];
  printf("Lan luot nhap ten, dung luong, kich thuoc, gia tien cua thiet bi:\n ");
  scanf("%s%d%f%s",A[0].name,&A[0].memory,&A[0].size,&A[0].price);
  return A[0];
}
void displaynode(node *p){
  if(p==NULL){
    printf("Loi con tro NULL\n");
  }
  printf("- %-25s %-20d %-20f %-20s\n",p->A.name,p->A.memory,p->A.size,p->A.price);
  return;
}
void insertathead(phone A){
  node *new=makenewnode(A);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  }else{
    new->next=root;
    root=new;
    cur=root;
    prev=NULL;
  }
}
void traversinglist(){
  node *p;
  for(p=root;p!=NULL;p=p->next){
    displaynode(p);
  }
  return;
}
void insertaftercurrent(phone A){
  node *new=makenewnode(A);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  }else{
    new->next=(*cur).next;
    prev=cur;
    (*cur).next=new;
    cur=new;
  }
}
void insertbeforecurrent(phone A){
  node *new=makenewnode(A);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  }else{
    (*new).next=cur;
    if(cur==root){
      root=new;
      prev=NULL;
    }else{
      (*prev).next=new;
    }
    cur=new;
  }
  return;
}

void updateprev(){
  node *p;
  if(cur==root){
    prev=NULL;
  }
  for(p=root;p!=NULL;p=p->next){
    if(p->next==cur){
      prev=p;
      return;
    }
  }
  return;
}
 
int main(){
  node *p;
  char k,C[100];
  FILE *ptr;
  phone *A;
  int i,n=0,j;
menu:
  printf("\nMenu:\n");
  printf("1.Import DB from text(Insert at head)\n");
  printf("2.Import DB from .dat(Insert after Current)\n");
  printf("3.Display list\n");
  printf("4.Search phone by Phone Model\n");
  printf("5.Search phone of which price under \n");
  printf("6.Export to DAT\n");
  printf("7.Manual insertion\n");
  printf("8.Exit\n");
  printf("Choose: ");
choose:
  __fpurge(stdin);
  scanf("%c",&k);
  __fpurge(stdin);
  switch(k){
  case '1':
    if((ptr=fopen("SmartPhone.txt","r"))==NULL){
      printf("Cannot open SmartPhone.txt file!\n");
      return 1;
    }
    while(!feof(ptr)){0s %-20s",A[0
      insertathead(scanfnode(ptr));
    }
    root=(*cur).next;
    free(cur);
    cur=root;
    prev=NULL;
    fclose(ptr);
    printf("Complete!\n");
    goto menu;
  case '2':
    p=root;
    while(p!=NULL){
      root=(*root).next;
      free(p);
      p=root;
    }
    if((ptr=fopen("PhoneDB.dat","rb"))==NULL){
      printf("Cannot open PhoneDB.dat file!\n");
      return 1;
    }
    while(!feof(ptr)){
      insertaftercurrent(readnode(ptr));
    }
    free(cur);
    cur=prev;
    (*cur).next=NULL;
    updateprev();
    fclose(ptr);
    printf("Complete!\n");
    goto menu;
  case '3':
    traversinglist();
    goto menu;
  case '4':
    j=0;
    printf("Search phone model: \n");
    scanf("%s%*c",C);
    printf("- %-25s%-20s%-20s%s\n","Model","Memory Space (GB)","Screen size (inch)","Price");
    for(p=root;p!=NULL;p=p->next){
      if(strcmp(C,p->A.name)==0){
        printf("- %-25s%-20d%-20.2f%d\n",p->A.name,p->A.memory,p->A.size,p->A.price);
        j=1;
      }
    }
    if(j==0){
      printf("Cannot find this phone!\n");
    }
    goto menu;
  case '5':
    j=0;
    printf("Input Price: ");
    scanf("%d",&i);
    printf("- %-25s%-20s%-20s%s\n","Model","Memory Space (GB)","Screen size (inch)","Price");
    for(p=root;p!=NULL;p=p->next){
      if(i>=p->A.price){
        printf("- %-25s%-20d%-20.2f%d\n",p->A.name,p->A.memory,p->A.size,p->A.price);
        j=1;
      }
    }
    if(j==0){
      printf("Cannot find this phone!\n");
    }
    goto menu;
  case '6':
    if((ptr=fopen("SmartPhone.dat","wb"))==NULL){
      printf("Cannot create PhoneDB.dat file\n");
      return 1;
    }
    for(p=root;p!=NULL;p=p->next){
      fwrite(&(p->A),sizeof(phone),1,ptr);
    }
    printf("Complete!\n");
    fclose(ptr);
    goto menu;
  case '7':
    printf("Input from:\n1.Before Current\n2.After Current\n");
    scanf("%d",&j);
    if(j==1){
      insertbeforecurrent(inputnode());
    }else if(j==2){
      insertaftercurrent(inputnode());
    }
    printf("Complete!\n");
    goto menu;
  case '8':
    p=root;
    while(p!=NULL){
      root=(*root).next;
      free(p);
      p=root;
    }
    return 0;  
  default:
    printf("Please choose only 1-5\n");
    goto choose;
  }
}
