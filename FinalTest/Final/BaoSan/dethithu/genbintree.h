//updated at: 1/7
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef diary elementt;
typedef struct nodetree_t{
  elementt A;
  struct nodetree_t *left,*right;
}treetype;
int sosanhngay(elementt a,elementt b){
  if(a.ngay>b.ngay){
    return 1;
  }else if(a.ngay<b.ngay){
    return -1;
  }else{
    return 0;
  }
}
int sosanhthang(elementt a,elementt b){
  if(a.thang>b.thang){
    return 1;
  }else if(a.thang<b.thang){
    return -1;
  }else{
    return sosanhngay(a,b);
  }
}
int compare(elementt a,elementt b){
  if(a.nam>b.nam){
    return 1;
  }else if(a.nam<b.nam){
    return -1;
  }else{
    return sosanhthang(a,b);
  }
}
/*int compare2(elementt a,elementt b){
  if(a.score==b.score){
    return 0;
  }
  if(a.score>b.score){
    return 1;
  }
  if(a.score<b.score){
    return -1;
  }
  }*/
void displayelementt(elementt A){
  printf("\nNgay %d/%d/%d, %s. %d do\n%s\n",A.ngay,A.thang,A.nam,A.thoitiet,A.t,A.noidung);
}
int max(int a, int b){
  if(a>=b){                    
    return a;
  }
  return b;
}
void initialize(treetype **t){
  *t=NULL;
  return;
}
int isleaf(treetype *t){
  if(t==NULL){
    return -1;
  }
  return t->left==NULL&&t->right==NULL;
}
int isemptyt(treetype *t){
  return t==NULL;
}
void makenulltree(treetype **t){
  if(isemptyt(*t)){
    return;
  }
  if(isleaf(*t)){
    free(*t);
    return;
  }
  makenulltree(&(*t)->left);
  makenulltree(&(*t)->right);
  free(*t);
  return;
}
treetype *createnode(elementt A){
  treetype *p;
  p=(treetype*)malloc(sizeof(treetype));
  if(p!=NULL){
    p->left=NULL;
    p->right=NULL;
    p->A=A;
  }
  return p;
}
int numnode(treetype *t){
  if(isemptyt(t)){
    return 0;
  }
  return 1+numnode(t->left)+numnode(t->right);
}
/*treetype *createfrom2(elementt v,treetype *l,treetype *r){
  treetype *n;
  n=(treetype*)malloc(sizeof(treetype));
  n->A=v;
  n->left=l;
  n->right=r;
  return *n;
  }*/
void input(elementt v, treetype **t){
  if(*t==NULL){
    *t=createnode(v);
    return;
  }
  if(compare((*t)->A,v)>=0){
    input(v,&(*t)->left);
    return;
  }else{
    input(v,&(*t)->right);
    return;
  }
}
int hight(treetype *t){
  if(t==NULL){
    return 0;
  }
  return 1+max(hight(t->left),hight(t->right));
}
int numleaf(treetype *t){
  if(t==NULL){
    return 0;
  }
  if(isleaf(t)){
    return 1;
  }
  return numleaf(t->left)+numleaf(t->right);
}
int numinode(treetype *t){
  if(t==NULL){
    return 0;
  }
  if(isleaf(t)){
    return 0;
  }
  return 1+numinode(t->left)+numinode(t->right);
}
int numrchildren(treetype *t){
  if(t==NULL){
    return 0;
  }
  if(t->right==NULL){
    return numrchildren(t->left);
  }
  return 1+numrchildren(t->left)+numrchildren(t->right);
}
void inorderprint(treetype *t){
  if(t!=NULL){
    inorderprint(t->left);
    displayelementt(t->A);
    inorderprint(t->right);
  }
  return;
}
void postorderprint(treetype *t){
  if(t!=NULL){
    postorderprint(t->left);
    postorderprint(t->right);
    displayelementt(t->A);
  }
}
void preorderprint(treetype *t){
  if(t!=NULL){
    displayelementt(t->A);
    preorderprint(t->left);
    preorderprint(t->right);
  }
}
elementt deletemin(treetype **t){
  elementt k;
  if((*t)->left==NULL){
    k=(*t)->A;
    (*t)=(*t)->right;
    return k;
  }else{
    return deletemin(&(*t)->left);
  }
}
void deletenode(elementt k,treetype **t){
  if(*t!=NULL){
    if(compare(k,(*t)->A)==-1){
      deletenode(k,&(*t)->left);
    }else if(compare(k,(*t)->A)==1){
      deletenode(k,&(*t)->right);
    }else if(((*t)->left==NULL)&&((*t)->right==NULL)){
      *t=NULL;
    }else if((*t)->left==NULL){
      *t=(*t)->right;
    }else if((*t)->right==NULL){
      *t=(*t)->left;
    }else{
      (*t)->A=deletemin(&(*t)->right);
    }
  }
}
int lowerthankey(elementt A,treetype *t){
  if(t!=NULL){
    if(compare(A,t->A)>0){
      displayelementt(t->A);
      return 1+lowerthankey(A,t->left)+lowerthankey(A,t->right);
    }else{
      return lowerthankey(A,t->left)+lowerthankey(A,t->right);
    }
  }
  return 0;
}
int higherthankey(elementt A,treetype *t){
  if(t!=NULL){
    if(compare(A,t->A)<0){
      displayelementt(t->A);
      return 1+higherthankey(A,t->left)+higherthankey(A,t->right);
    }else{
      return higherthankey(A,t->left)+higherthankey(A,t->right);
    }
  }
  return 0;
}
void inordersearch(int *n,elementt *A,treetype *t){
  if(t!=NULL){
    inordersearch(n,A,t->left);
    if(compare(*A,t->A)==0){
      *n=1;
      *A=t->A;
    }
    inordersearch(n,A,t->right);
  }
  return;
}
//bai kiem tra
void inorderupdate(elementt B,treetype **t){
  if((*t)!=NULL){
    inorderupdate(B,&(*t)->left);
    if(compare(B,(*t)->A)==0){
      (*t)->A=B;
    }
    inorderupdate(B,&(*t)->right);
  }
  return;
}
void inordersearch2(int *n,elementt A,treetype *t){
  if(t!=NULL){
    inordersearch2(n,A,t->left);
    if(compare(A,t->A)==0){
      *n=1;
      displayelementt(t->A);
    }
    inordersearch2(n,A,t->right);
  }
  return;
}
/*void xuonghang(elementt A,treetype **t){
  if((*t)!=NULL){
    xuonghang(A,&(*t)->left);
    xuonghang(A,&(*t)->right);
    if((*t)->A.score<A.score){
      printf("%s\n",(*t)->A.name);
      deletenode((*t)->A,t);
    }
  }
  return;
  }*/
/*void xuatfile(FILE *ptr,treetype *t){
  if(t!=NULL){
    xuatfile(ptr,t->left);
    fprintf(ptr,"%s\t%d\n",t->A.name,t->A.score);
    xuatfile(ptr,t->right);
  }
  return;
  }*/
