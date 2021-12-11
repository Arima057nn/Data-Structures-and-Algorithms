#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef student element;
typedef struct nodeType {
  element data;
  struct nodeType *left, *right;
} node;
typedef struct nodeType *tree;

/*int compare(element a,element b){
  if( strcmp(a.ID,b.ID) == 0) return 0;
  if( strcmp(a.ID,b.ID) > 0) return 1;
  if( strcmp(a.ID,b.ID) < 0) return -1;
}
int compare2(element a,element b){
  if(a.Score == b.Score) return 0;
  if(a.Score > b.Score) return 1;
  if(a.Score < b.Score) return -1;

}
element input(){
  element new;
  printf("ID: ");
  gets(new.ID);
  printf("Score: ");
  scanf("%d",&new.Score);
  return new;
  }*/
void displayElement(element e){
  //printf("%s\t%d\n",e.ID,e.Score);  
  printf("%-6s %-6s %-6s %-15s %-15g %-15s\n",e.name.ho,e.name.dem,e.name.ten,e.id,e.score,e.address);  
}

void makeNullTree(tree *T){
  (*T) = NULL;
};
// create a new node
node *createNewNode(element e){
  node *new = (node*)malloc(sizeof(node));
  if(new != NULL){
    new->right = NULL;
    new->left = NULL;
    new->data = e;
  }
  return new;
}

tree leftChild(tree T){
  if(T != NULL)   return T->left;
  else return NULL;
}
tree rightChild(tree T){
  if(T != NULL)   return T->right;
  else return NULL;
  
}
int isEmpty(tree T){
  return T == NULL;
}

//Check if a node is a leaves			
int isLeaf(tree T){
  if(T != NULL){
    return (leftChild(T) == NULL) && (rightChild(T) == NULL);
  }else return -1;
}
// Number of node
int nb_nodes(tree T){
  if(isEmpty(T)) return 0;
  else return 1 +nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}
int nb_leaf(tree T){
  if(T == NULL) return 0;
  if(rightChild(T) == NULL || leftChild(T) == NULL) return 1;
  else return nb_leaf(leftChild(T)) + nb_leaf(rightChild(T));
}

int height(tree T){
  if(T == NULL) return 0;
  else{
    int right_Height = height(T->right);
    int left_Height = height(T->left);
    if(right_Height > left_Height)  return right_Height + 1;
    else return left_Height + 1;
  }
}
int nb_RightChild(tree T){
  if(T == NULL) return 0;
  if(T->right == NULL) return nb_RightChild(T->left);
  else return 1 + nb_RightChild(T->right) + nb_RightChild(T->left);
}



void insertNode(element e, tree *T){
  if(*T == NULL){
    *T = createNewNode(e);
    printf("Address of new node: %d",T);
  }
  else if(compare((*T)->data,e) == 1) return insertNode(e,&(*T)->left);
  else if(compare((*T)->data,e) == -1) return insertNode(e,&(*T)->right);
}

element DeleteMin(tree *T){
  element k;
  if( (*T)->left == NULL){
    k = (*T)->data;
    (*T) = (*T)->right;
    return k;
  }
  else return DeleteMin(&(*T)->left);
  }
void DeleteNode(element e, tree *T){
  if(*T != NULL){
    if(compare((*T)->data,e) == 1) DeleteNode(e,&(*T)->left);
    else if(compare((*T)->data,e) == -1) DeleteNode(e,&(*T)->right);
    else if(((*T)->left == NULL )&&((*T)->right == NULL))
      *T = NULL;
    else if((*T)->left == NULL)
      *T = (*T)->right;
    else if((*T)->right == NULL)
      *T = (*T)->left;
    else (*T)->data = DeleteMin(&(*T)->right);
  }
}

tree Searching(element x, tree T){
  if(T == NULL || compare(T->data,x) == 0) return T;
  else if(compare(T->data,x) == 1) return Searching(x,T->right);
  else if(compare(T->data,x) == -1) return Searching(x,T->left);
}
void SEARCHING(int *n,element e,tree T){
  if(T != NULL){
    SEARCHING(n,e,T->left);
    if(compare(T->data,e) == 0){
      *n = 1;
      displayElement(T->data);
    }
    SEARCHING(n,e,T->right);
  }
  return;
}

/*void update(int *n,element e,tree T){
  if(T != NULL){
    update(n,e,(T->left));
    if(compare(T->data,e) == 0){
      *n = 1;
      DeleteNode(e,&T);
      insertNode(input(),&T);
      return;
    }
    update(n,e,T->right);
  }
  return;
}*/
element findMax();
element findMin();
void inorderprint(tree T){
  if(T != NULL){
    inorderprint(T->left);
    displayElement(T->data);
    inorderprint(T->right);
  }
}

void InOrderPrint(tree T){
  if(T != NULL){
    InOrderPrint(T->right);
    displayElement(T->data);
    InOrderPrint(T->left);
  }
}
void preorderprint(tree T){
  if(T != NULL){
      displayElement(T->data);
      preorderprint(T->left);
      preorderprint(T->right);
  }
}
void postorderprint(tree T){
  if(T != NULL){
    preorderprint(T->left);
    preorderprint(T->right);
    displayElement(T->data);
      }
}
void freeTree(tree T){
  if(T != NULL){
    freeTree(T->right);
    freeTree(T->left);
    free((void *)T);
  }
}


//=====================================
//=====================================



int lowerThankey(int Score, tree T){
   if(T == NULL) return 0;
   else{
     if(Score > T->data.score) return lowerThankey(Score,T->left) + lowerThankey(Score,T->right) + 1;
    else return lowerThankey(Score,T->left) + lowerThankey(Score,T->right);
   }
}
int higherThankey(int Score, tree T){
   if(T == NULL) return 0;
   else{
     if(Score <= T->data.score) return higherThankey(Score,T->left) + higherThankey(Score,T->right) + 1;
    else return higherThankey(Score,T->left) + higherThankey(Score,T->right);
   }
}
element higher(int Score, tree T){
   if(T != NULL){
     if(Score <= T->data.score) displayElement(T->data);
     //printf("%s %s %s %-20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.Score,T->data.address);  
    higher(Score,T->left);
    higher(Score,T->right);
}
}
element lower(int Score, tree T){
   if(T != NULL){
     if(Score > T->data.score) displayElement(T->data);
     //printf("%s %s %s %-20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.Score,T->data.address);  
    lower(Score,T->left);
    lower(Score,T->right);
}
}
void OutPutFile(FILE *ptr,tree T){
  if(T != NULL){
    OutPutFile(ptr,T->left);
    fprintf(ptr,"%-6s %-6s %-6s %-15s %-15g %-15s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.score,T->data.address);
    OutPutFile(ptr,T->right);
  }
}
void OutPutFile2(FILE *ptr,tree T){
  if(T != NULL){
    OutPutFile2(ptr,T->left);
    fwrite(&(T->data),sizeof(element),1,ptr);
    OutPutFile2(ptr,T->right);
  }
}

