#include <stdio.h>
#include <stdlib.h>
#include<stdio_ext.h>

node *CreateNode(int value){
    node *new;
    new = (node*)malloc(sizeof(node));
    new->next = NULL;
    new->data = value;
    return new;
}
node *AddHead(node *head,int value){
    node *new = CreateNode(value);s
    if(head == NULL){
        head = new;
    }else{
      new->next = head;
      head = new;
      
    }
    return head;
}
node *addaftercurrent(node *head, int value){
  node *new=CreateNode(value);
  if(head == NULL){
    head=new;
    cur = head;
    prev= NULL;
  } else{
    new->next=cur->next;
    cur->next=new;
    prev=cur;/* cap nhat con tro prev de su dung sau nay */
    cur=cur->next;
  }
  return head;
}
node *addbeforecurrent(node *head,int value){
  node *new = CreateNode(value);
  if(head == NULL){
    head = new;
    cur = head;
    prev = NULL;
  }else{
    new->next = cur;
    if(cur == head){
      head = new;
    }
    else prev->next = new;
    cur = new;
  }
  return head;
}
node *AddTail(node *head,int value){
    node *p = head;
    node *new = CreateNode(value);
    if(head == NULL){
        head = new; 
    }else{
        while(p->next != NULL){
            p = p->next;
        }
        p->next = new;
    }
    return head;
}
node *DelTail(node *head){
    node *p = head;
    if(head == NULL){
        printf("KHong the xoa");
    }else if(head->next == NULL){
        head->next = NULL;
    }else{
        while(p->next->next != NULL){
            p = p->next;
        }
        p->next = NULL;
    }
    return head;
}
void Traveresing(node  *head){
    node *p = head;
    while(p != NULL){
        printf("%d\t",p->data);
	p=p->next;
    }
}
