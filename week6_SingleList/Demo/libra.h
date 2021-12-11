#include <stdio.h>
#include <stdlib.h>
typedef phone element;
typedef struct node{
  element data;
  struct node *next;
} node;

node *root = NULL, *prev = NULL, *cur = NULL;

node *makeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->data = e;	
  new->next = NULL;
  return new;
}
void traversingList(){
  node *p = root;
  for(p=root;p!=NULL;p=p->next){
  displayNode(p);
  }
  return;
}

void insertAtHead(element A){
  node *new=makeNewNode(A);
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
//Cap nhat con tro prev
void updatePointerPrev(){
  node *tmp = root;
  while(tmp->next != cur && cur != NULL){
    tmp = tmp->next;
  }
  prev = tmp;
}
void insertAtTail(element A){
  node *new = makeNewNode(A);
  node *p = root;
  if(p == NULL){
    root = new;
    cur = root;
    prev = NULL;
  }else{
    while(p->next != NULL){
      p = p->next;
    }
    p->next = new;
    cur = new;
    updatePointerPrev();
  }
}
void insertAfterCurrent(element A){
  node *new = makeNewNode(A);
  if(root==NULL){
    insertAtHead(A);
  }else if(cur==NULL){
    printf("Current is NULL\n");
    return;
  }else{
    new->next = cur->next;
    prev = cur;
    cur->next = new;
    cur = new;
  }
}

void insertBeforeCurrent(element A){
  node *new = makeNewNode(A);
  if(root==NULL){
    root=new;
    cur=root;
    prev=NULL;
  }else{
    new->next=cur;
    if(cur==root){
      root=new;
      prev=NULL;
    }else{
      prev->next=new;
    }
    cur=new;
  }
}

node *insertAtPosition(element A,int n){
  node *new = makeNewNode(A);
  cur = root;
  int i;
  if(n == 0){
    insertAtHead(A);
  }
  for(i = 1; i < n ; i++){
    prev = cur;
    cur = cur->next;
    if(cur == NULL){
      printf("n > i vo li\n");
      return NULL;
    }
  }
  new->next = cur->next;
  cur->next = new;
  return new;
}
void delFirstElement(){
  node *del = root;
  if(del == NULL){
    printf("Error pointer");
    return ;
  }else{
    root = del->next;
    free(del);
    cur = root;
    prev = NULL;
  }
}
void delLastElement(){
  node *p = root;
  if(p == NULL){
    printf("Error pointer");
    return ;
  }else if(root->next == NULL){
    delFirstElement();
  }else{
    while( p->next->next != NULL)
      p = p->next;
  }
  p->next = NULL;
  cur = p;
  updatePointerPrev();
}
void delCurrentElement(){
  if(cur == NULL){
    return ;
  }
  if(cur == root){
    delFirstElement();
  }else{
    prev->next = cur->next;
    free(cur);
    cur = prev->next;

  }
}
node *delAtPosition(int k){
  int i = 1;
  node *p = root;
  if(p == NULL){
    printf("Error pointer");
  }else{
    for(i = 1;i<k;i++){
      p = p->next;
    }
    if( p == NULL){
      printf("Khong ton tai");
      return NULL;
    }else{
      cur = p;
      updatePointerPrev();
      prev->next = cur->next;
      free(cur);
      cur = prev->next;
    }
  }
  return root;
  }
void freeList(){
  node *fre = root;
  while(fre != NULL){
    root = root->next;
    free(fre);
    fre = root;
  }
}
node *list_reverse(node *root){
  node *cur = NULL, *prev = NULL;
  while(root != NULL){
    cur = root;
    root = root->next;
    cur->next = prev;
    prev = cur;
  }
  return prev;
}
