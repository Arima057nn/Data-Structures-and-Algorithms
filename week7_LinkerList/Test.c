#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>
typedef int element;
typedef struct Node{
    element data;
    struct Node *next;
} node;
//node *head=NULL, *cur=NULL, *prev=NULL; 

node *makeNewNode(element value){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->data = value;
    return new;
}

void traveresingList(node  *head){
    node *p = head;
    while(p != NULL){
        printf("%d\t",p->data);
	p=p->next;
    }
}
node *insertAtHead(node **head,element value){
    node *new = makeNewNode(value);
    if(*head == NULL){
        *head = new;
    }else{
      new->next = *head;
      *head = new;    
    }
    return *head;
}
node *insertAtTail(node **head,element value){
    node *p = *head;
    node *new = makeNewNode(value);
    if(*head == NULL){
        *head = new; 
    }else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = new;
    }
    return *head;
}
/*node *insertAfterCurrent(node **head, element value){
  node *new=makeNewNode(value);
  if(*head == NULL){
    *head=new;
    cur = *head;
    prev= NULL;
  } else{
    new->next=cur->next;
    cur->next=new;
    prev=cur;/* cap nhat con tro prev de su dung sau nay */
    cur=cur->next;
  }
  //return *head;
}*/
/*node *insertBeforeCurrent(node **head,element value){
  node *new = makeNewNode(value);
  if(*head == NULL){
    *head = new;
    cur = *head;
    prev = NULL;
  }else{
    new->next = cur;
    if(cur == *head){
      *head = new;
    }
    else prev->next = new;
    cur = new;
  }
  return *head;
}
*/
node *delFirstElement(node **head)
{
  if(*head==NULL){
    printf("Cha co gi de xoa het\n");
    return NULL;
  }
  else{
    *head = (*head)->next;/*Xoa dau rat don gian , chi can cho thang ke tiep cua head lam head la dc*/
  }
  return *head;
}.0(p->next->next != NULL){
            p = p->next;
        }
        p->next = NULL;
    }
    return *head;
}


node *DelBatKi(node **head,element k){
  element i = 1;
  node *p = *head;
  if(*head == NULL || *head->next == NULL||k == 0){
    *head = delFirstElement(*head);
    return NULL;
  }else{
    while(p->next->next != NULL && i!= k){
      p = p->next;
      i++;
    }
    if(i<k){
      *head = delLastElement(*head);
    }else{
      p->next = p->next->next;
    }
    
  }
  return *head;
}
element main(){
    node *root;
    return 0;
}
