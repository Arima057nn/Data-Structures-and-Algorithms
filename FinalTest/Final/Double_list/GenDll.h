#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef sanPham element;
typedef struct Node{
  element data;
  struct Node *next;
  struct Node *prev;  
} node;

 
int compare(element a, element b)
{
    if (strcmp(a.ten, b.ten) == 0)
        return 0;
    if (strcmp(a.ten, b.ten) > 0)
        return 1;
    if (strcmp(a.ten, b.ten) < 0)
        return -1;
}
 
int compare2(element a, element b)
{
    if (a.gia == b.gia)
        return 0;
    if (a.gia > b.gia)
        return 1;
    if (a.gia < b.gia)
        return -1;
}
/*
int compare3(element x,element e){
  if( x.nam <e.nam) return 1;
  if( x.nam > e.nam) return -1;
  if( x.nam == e.nam){
    if(x.thang < e.thang) return 1;
    if(x.thang > e.thang) return -1;
    if( x.thang == e.thang){
      if(x.ngay < e.ngay) return 1;
      if( x.ngay > e.ngay) return -1;
      if( x.ngay ==e.ngay) return 0;
    }
  }
}
*/
void displayNode(node *p)
{
    if (p == NULL)
    {
        printf("Error Pointer");
    }
    else
    {
        printf("%-20d %-20d %-20d %-20s\n",p->data.maSP,p->data.gia,p->data.SL,p->data.ten);
    }
}
element input(){
    element new;
    printf("Ma SP: ");
    scanf("%d",&new.maSP);
    printf("Ten SP: ");
    scanf("%s%*c",new.ten);
    printf("Gia: " );
    scanf("%d",&new.gia);
    printf("So luong: ");
    scanf("%d",&new.SL);
    return new;
}
void initialize(node **root,node **cur,node **tail){
  *root = NULL;
  *tail = NULL;
  *cur = NULL;
}
node *makeNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  new->data = e;
  new->next = NULL;
  new->prev = NULL;
  return new;
}

void traversingList1(node *root,node *cur,node *tail){
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
void traversingList2(node *root,node *cur,node *tail){
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
void insertAtHead(element A,node **root,node **cur,node **tail){
  node *new=makeNewNode(A);
  if(*root==NULL){
    *root=new;
    *cur=*root;
    *tail=new;
  }else{
    (*root)->prev=new;
    new->next=*root;
    new->prev=NULL;
    *root=new;
    *cur=*root;
  }
  return;
}
void insertAtTail(element A,node **root,node **cur,node **tail){
  node *new=makeNewNode(A);
  if(*root==NULL){
    insertAtHead(A,root,cur,tail);
    return;
  }
  (*tail)->next=new;
  new->prev=*tail;
  *tail=new;
  *cur=new;
  return;
}
void insertBeforeCurrent(element A,node **root,node **cur,node **tail){
  node *new=makeNewNode(A);
  if(*root==NULL||*cur==*root){
    insertAtHead(A,root,cur,tail);
    return;
  }else if(*cur==NULL){
    printf("Current is NULL!\n");
    return;
  }else{
    new->next=*cur;
    new->prev=(*cur)->prev;
    (*cur)->prev->next=new;
    (*cur)->prev=new;
    *cur=new;
  }
  return;
}
void insertAfterCurrent(element A,node **root,node **cur,node **tail){
  node *new=makeNewNode(A);
  if(*root==NULL||*cur==*tail){
    insertAtTail(A,root,cur,tail);
    return;
  }else if(*cur==NULL){
    printf("Current is NULL!\n");
    return;
  }else{
    new->next=(*cur)->next;
    new->prev=*cur;
    (*cur)->next->prev=new;
    (*cur)->next=new;
    *cur=new;
  }
}
void insertAtPosition(element A,int n,node **root,node **cur,node **tail){    
  node *new=makeNewNode(A);
  *cur=*root;
  if(n<0){
    printf("n must be >=0!\n");
    return;
  }
  if(n==0){
    insertAtHead(A,root,cur,tail);
    return;
  }
  for(int i=1;i<n;i++){
    *cur=(*cur)->next;
    if(*cur==NULL){
      printf("n must be<=%d\n",i);
      return;
    }
  }
  insertAfterCurrent(A,root,cur,tail);
  return;
}

void deleteFirstElement(node **root,node **cur,node **tail){
  node *p=*root;
  if(*root==NULL){
    printf("root is NULL\n");
    return;
  }
  *root=(*root)->next;
  (*root)->prev=NULL;
  *cur=*root;
  free(p);
  return;
}
void deleteLastElement(node **root,node **cur,node **tail){
  node *p=*tail;
  if(*tail==NULL){
    printf("tail is NULL\n");
    return;
  }
  *tail=(*tail)->prev;
  (*tail)->next=NULL;
  *cur=*tail;
  free(p);
  return;
}
void deleteCurrentElement(node **root,node **cur,node **tail){
  node *p=*cur;
  if(*cur==NULL){
    printf("cur is NULL\n");
    return;
  }
  if(*cur==*root){
    deleteFirstElement(root,cur,tail);
    return;
  }
  if(*cur==*tail){
    deleteLastElement(root,cur,tail);
    return;
  }
  (*cur)->prev->next=(*cur)->next;
  (*cur)->next->prev=(*cur)->prev;
  *cur=(*cur)->next;
  free(p);
  return;
}
void deleteAtPosition(int n,node **root,node **cur,node **tail){
  *cur=*root;
  if(n<0){
    printf("n must be >=0!\n");
    return;
  }
  if(n==0){
    deleteFirstElement(root,cur,tail);
    return;
  }
  for(int i=1;i<n;i++){
    *cur=(*cur)->next;
    if(*cur==NULL){
      printf("n must be<=%d\n",i);
      return;
    }
  }
  deleteCurrentElement(root,cur,tail);
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
void searching(node *root,element e){
  node *p;
  int i = 0;
  for(p = root; p!= NULL;p = p->next){
    if(compare2(p->data,e) == 0){
        printf("Tim thay! \n");
        displayNode(p);
        i = 1;
        return;
    }
  }
  if(i == 0)  printf("Khong tim thay");
  return;
}
/* void swap(node **a,node **b){
  element temp;
  temp = (*a)->data;
  (*a)->data = (*b)->data;
  (*b)->data = temp;
}
 */
void sortList(node **root, node **tail)
{
  element tmp;
  node *p1, *p2;
  for (p1 = *root; p1->next != NULL; p1 = p1->next);
  *tail = p1;
  for (p1 = *root; p1 != *tail; p1 = p1->next)
  {
    for (p2 = p1->next; p2 != NULL; p2 = p2->next)
    {
      if (compare2(p1->data,p2->data) == 1)
      {
        tmp = p1->data;
        p1->data = p2->data;
        p2->data = tmp;
      }
    }
  }
}

void freeList(node **root,node **cur,node **tail){
  node *p = *root;
  while(p!=NULL){
    *root=(*root)->next;
    free(p);
    p=*root;
  }
  return;
}
void outPutFile(node *root,node *tail,FILE *ptr){
  node *p = root;
  while(p != NULL){
    fprintf(ptr, "%d\t%d\t%d\t%s\n", p->data.maSP, p->data.gia, p->data.SL, p->data.ten);
    p = p->next;     
  }
}

  




     
