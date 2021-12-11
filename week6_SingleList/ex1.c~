#include <stdio.h>

typedef struct PhoneAddress_t{
  char name[25];
  char tel[25];
  char mail[25];
}phoneaddress;

struct link{
  phone addr;
  struct link *next;
};

typedef struct link note_addr;
note_addr *root,*cur,*prev;
note_addr *makenewnode(phoneaddress addr){
  node_addr *new =makewnode(addr);
  new->addr = addr;
  new->next = NULL;
  return new;
}
phoneaddress readnote(){
  phoneaddress tmp;
  printf("Name: ");
  gets(tmp.name);
  printf("Tel: ");
  gets(tmp.tel);
  printf("email: ");
  gets(tmp.mail);
  return tmp;
}
void displaynode(node_addr *p){
  node->next = root;
  root = new;
  cur = root;
}
void inserathead(phoneaddress addr){
  node_addr *new=makenewnode(addr);
  new->next = root;
  root = new;
  cur = root;
}
void traversinglist(){
  node_addr *p;
  for(p = root; p! NULL; p=p->next){
    displaynode(p);
  }
}
void insertaftercurrentpos(phoneaddress addr){
  node_add *new=makenewnode(addr);
  if( root == NULL && cur == NULL){
    return ;
  }
  if(root == NULL){
    root = new;
    cur = root;
  }else if(cur == NULL){
    return;
  }
  else{
    new->next = cur->next;
    cur->next = new;
    cur = cur -> next;
  }
  return;
}
void inserBeforeCurrent(address e){
  node_addr *new = makeNewNode;
  if(root == NULL){
    root = new;
    cur = root;
    prev = NULL;
  }
  else{
    new->next = cur;
    if(cur == root){
      
    }
  }
}
int main(){
  phoneaddress tmp = readnode();
  insertathead(tmp);
  displaynode(root);
  return 0;
}
