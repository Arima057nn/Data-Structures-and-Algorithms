#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef phone element;
typedef struct Node{
  element data;
  struct Node *next;
  struct Node *prev;  
} node;
void displayNode(node *p);

void initialize(node **root,node **cur,node **tail){
  *root = NULL;
  *tail = NULL;
  *cur = NULL;
}
// Kiem tra so phan tu co trong list
int length(node *root,node * tail){
  int length = 0;
  node *p = root;
  for(p = root;p != NULL; p = p->next){
    length ++;
  }
  return length;
}

void traversingList1(node *root){
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
void traversingList2(node *tail){
  node *p = tail;
  if(tail == NULL){
    printf("Error Pointer");
    return ;
  }
  while(p != NULL){
    displayNode(p);
    p = p->prev;
  }
}
node *makeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->data = e;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

node *insertAtHead(element A,node **root,node **cur,node **tail){
  node *new = makeNewNode(A);
  if(*root == NULL){
    *root = new;
    *tail = new;
    *cur = new;
    return *root;
  }
  new->next = *root;
  (*root)->prev = new;
  new->prev = NULL;
  *root = new;
  *cur = *root;
}

node *insertAtTail(element A,node **root,node **cur,node **tail){
  node *new = makeNewNode(A);
  if(*tail == NULL){
    *root = new;
    *tail = new;
    *cur = new;
    return *cur;
  }
  (*tail)->next = new;
  new->prev = *tail;
  *tail = new;
  *cur = *tail;
  (*tail)->next=NULL;
}
node insertAfterCurrent(element e,node **root,node **cur,node **tail){
  node *new = makeNewNode(e);
  if(*root == NULL){
    *root = new;
    *tail = new;
    *cur = new;
    return *cur;
  }else if(*cur == NULL){
    printf("Current pointer is NULL");
    return *cur;
  }else{
    if(*cur == *tail || (*root)->next == NULL){
      return insertAtTail(e,root,cur,tail);
    }else{
      new->next = (*cur)->next;
      (*cur)->next->prev = new;
      (*cur)->next = new;
      new->prev = cur;
      *cur = new;
      return *cur;
    }
  }
}
node *insertBeforeCurrent(element e,node **root,node **cur,node **tail){
  node *new = makeNewNode(e);
  if(*root == NULL||*cur == *root){
    return insertAtHead(A,root,cur,tail); 
  }else if(*cur == NULL){
    printf("Current is NULL!\n");
    return *cur;
  }else{
    new->next = *cur;
    new->prev = (*cur)->prev;
    (*cur)->prev->next = new;
    (*cur)->prev = new;
    *cur=new;
  }
  return *cur;
}

node *insertAtPosition(element e,int n,node **root,node **cur,node **tail){
  node *new = makeNewNode(e);
  if(n < 0){
    printf("cannot insert!");
    return *cur;
  }
  if(n == 0){
    insertAtHead(e,&(*root),&(*cur),&(*tail));
//    return *root;
  }
  for(i = 1; i < n ;i++){
    *cur = (*cur)->next;
    if(cur == NULL){
      printf("n > i vo li");
      return *root;
    }
  }
  insertAfterCurrent(e); 
}

node *deleteFirstElement(node **root,node **cur,node **tail){
  node *p = *root;
  if(*root == NULL){
    printf("\nKhong co gi de xoa\n");
    return *root;
  }
  (*root) = (*root)->next;
  free(p);
  *cur = *root;
  (*root)->prev = NULL;
  return *root;
  }
node *deleteLastElement(node **root,node **cur,node **tail){
  node *p = tail;
  if(*tail == NULL){
    printf("\nKHong co gi de xoa\n");
    return *tail;
  }
  *tail = (*tail)->prev;
  (*tail)->next = NULL;
  free(p);
  *cur = *tail;
  return *tail;
}

node *deleteCurrentElement(node **root,node **cur,node **tail){
  node *p =*cur;
  if(*cur == NULL){
    printf("cur is NULL\n");
    return *root;
  }
  if(*cur == *root){
    return deleteFirstElement(root,cur,tail);
  }
  if(*cur == *tail){
    return deleteLastElement(root,cur,tail);
  }
  (*cur)->prev->next=(*cur)->next;
  (*cur)->next->prev=(*cur)->prev;
  *cur=(*cur)->next;
  free(p);
  return *cur;
  }

node *deleteAtPosition(int n,node **root,node **cur,node **tail){
  int i;
  *cur=*root;
  if(n < 0){
    printf("n must be >=0!\n");
    return *root;
  }
  if(n==0){
    return deleteFirstElement(root,cur,tail);
  }
  for(i = 1;i<n;i++){
    *cur=(*cur)->next;
    if(*cur == NULL){
      printf("n must be<=%d\n",i);
      return *root;
    }
  }
  return deleteCurrentElement(root,cur,tail);
  
}

void free_List(node **root,node **cur,node **tail){
  node *p = *root;
  while(p!=NULL){
    *root=(*root)->next;
    free(p);
    p=*root;
  }
  return;
}
void Reverse_List(node **root,node **cur,node **tail){
  node *p= *cur=NULL;
  *tail=*root;
  while(*root != NULL){
    *cur=*root;
    *root=(*root)->next;
    (*cur)->next=p;
    (*cur)->prev=*root;
    p=*cur;
  }
  *root=*cur;
  return;
}