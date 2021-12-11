#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef phone element;
typedef struct Node{
  element data;
  struct Node *next;
  struct Node *prev;
  
} node;
node *root = NULL, *tail = NULL, *cur = NULL;

void displayNode(node *p);
int isEmpty(){
  return root == NULL;
}
// Kiem tra so phan tu co trong list
int length(){
  int length = 0;
  node *p = root;
  for(p = root;p != NULL; p = p->next){
    length ++;
  }
  return length;
}

void traversingList(){
  node *p = root;
  if(root == NULL){
    printf("Error Pointer");
    return ;
  }
  while(p != NULL){
    displayNode(p);
    p = p->next;
  }
}
/*
void traversing_tail(){
  node *p = tail;
  if(tail == NULL){
    printf("Error Pointer");
    return ;
  }
  while(p != NULL){
    displayNode(p);
    p = p->prev;
  }
}*/
node *makeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->data = e;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void insertAtHead(element A){
  node *new = makeNewNode(A);
  if(root == NULL){
    root = new;
    tail = new;
    cur = new;
    return ;
  }
  new->next = root;
  root->prev = new;
  root = new;
  cur = root;
}

void insertAtTail(element A){
  node *new = makeNewNode(A);
  if(tail == NULL){
    root = new;
    tail = new;
    cur = new;
    return ;
  }
  tail->next = new;
  new->prev = tail;
  tail = new;
  cur = tail;
  tail->next=NULL;
}
void insertAfterCurrent(element e){
  node *new = makeNewNode(e);
  if(root == NULL){
    root = new;
    tail = new;
    cur = new;
    return ;
  }else if(cur == NULL){
    printf("Current pointer is NULL");
    return;
  }else{
    if(cur == tail || root->next == NULL){
      insertAtTail(e);
      return ; 
    }else{
      new->next = cur->next;
      cur->next->prev = new;
      cur->next = new;
      new->prev = cur;
      cur = new;
    }
  }
}
void insertBeforeCurrent(element e){
  node *new = makeNewNode(e);
  if(root == NULL){
    root = new;
    tail = new;
    cur = new;
    return ;
  }else if(cur == NULL){
    printf("Current pointer is NULL");
    return;
  }else{
    if(cur == root || root->next == NULL){
      insertAtHead(e);
      return ;
    }else{
      new->next = cur;
      new->prev = cur->prev;
      cur->prev->next =new;
      cur->prev = new;
      cur = new;
    }
  }
}
node *insertAtPosition(element e,int n){
  node *new = makeNewNode(e);
  int i;
  cur = root;
  if(n == 0){
    insertAtHead(e);
  }
  for(i = 1; i < n ;i++){
    cur = cur->next;
    if(cur == NULL){
      printf("n > i vo li");
      return NULL;
    }
  }
  insertAfterCurrent(e);
  return root;
}

void deleteFirstElement(){
  node *p = root;
  if(root == NULL){
    printf("\nKhong co gi de xoa\n");
    return ;
  }
  root = root->next;
  free(p);
  cur = root;
  root->prev = NULL;
  }
void deleteLastElement(){
  node *p = tail;
  if(tail == NULL){
    printf("\nKHong co gi de xoa\n");
    return ;
  }
  tail = tail->prev;
  tail->next = NULL;
  free(p);
  cur = tail;
}

void deleteCurrentElement(){
  if(root == NULL){
    printf("Khong co gi de xoa");
    return ;
  }else if(cur == NULL){
    printf("Error pointer");
    return;
  }else{
    if(cur == root){
      deleteFirstElement();
      return;
    }
    else if(cur == tail){
      deleteLastElement();
      return ;
    }else{
      cur->prev->next = cur->next;
      cur->next->prev = cur->prev;
      cur = cur->next;
    }
  }
  }
node *deleteAtPosition(int n){
  int i = 1;
  node *p = root;
  if(p == NULL){
    printf("Error pointer");
  }else{
    for(i = 1;i < n ;i++){
      p = p->next;
    }
    if( p == NULL){
      printf("Khong ton tai");
      return NULL;
    }
    else if( p == root){
      deleteFirstElement();
    }
    else if( p == tail){
      deleteLastElement();
    }else{
      p->prev->next = p->next;
      p->next->prev = p->prev;
      cur = p->next;
      free(p);
    }
  }
  return root;
}

void free_List(){
  node *p = root;
  while(p!=NULL){
    root=root->next;
    free(p);
    p=root;
  }
  return;
}
void Reverse_List(){
  node *p=cur=NULL;
  tail=root;
  while(root!=NULL){
    cur=root;
    root=root->next;
    cur->next=p;
    cur->prev=root;
    p=cur;
  }
  root=cur;
  return;
}
/*insertAtHead(inputNode());
  traversingList();
  insertAtHead(inputNode());
  traversingList();
  insertAfterCurrent(inputNode());
  traversingList();
  insertAfterCurrent(inputNode());
  traversingList();
  insertBeforeCurrent(inputNode());
  traversingList();
  root = insertAtPosition(inputNode(),3);
  traversingList();
  insertAtTail(inputNode());
  traversingList();
  printf("\nXoa phan tu dau tien\n");
  deleteFirstElement();
  traversingList();
  printf("\n");
  TraversingList();
  printf("\nXoa phan tu cuoi cung\n");
  deleteLastElement();
  traversingList();
  printf("\n");
  //root = deleteAtPosition(3);
  //traversingList();
  printf("\n");
  TraversingList();
  */

