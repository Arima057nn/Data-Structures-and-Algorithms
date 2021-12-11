#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef student element;
typedef struct nodeType {
  element data;
  struct nodeType *left, *right;
} node;
typedef struct nodeType *tree;
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

void insertNode(element x, tree *T){
  if(*T == NULL){
    *T = createNewNode(x);
  }
  else if(TraVe((*T)->data,x) == -1) return insertNode(x,&(*T)->left);
  else if(TraVe((*T)->data,x) == 1) return insertNode(x,&(*T)->right);
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
    if(TraVe((*T)->data,e) == -1) DeleteNode(e,&(*T)->left);
    else if(TraVe((*T)->data,e) == 1) DeleteNode(e,&(*T)->right);
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
  if(T == NULL || TraVe(T->data,x) == 0){
    return T;
  }
  else if(TraVe(T->data,x) == 1) return Searching(x,T->right);
  else if(TraVe(T->data,x) == -1) return Searching(x,T->left);
}

element findMax();
element findMin();
void inorderprint(tree T){
  if(T != NULL){
    inorderprint(T->left);
    printf("%s %s %s %20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.score,T->data.address);
    inorderprint(T->right);
  }
}


void preorderprint(tree T){
  if(T != NULL){
      printf("%s %s %s %-20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.score,T->data.address);
      preorderprint(T->left);
    preorderprint(T->right);
  }
}
void postorderrprint(tree T){
  if(T != NULL){
    preorderprint(T->left);
    preorderprint(T->right);
    printf("%s %s %s %-20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.score,T->data.address);
      }
}
void freeTree(tree T){
  if(T != NULL){
    freeTree(T->right);
    freeTree(T->left);
    free((void *)T);
  }
}

int lowerThankey(float score, tree T){
   if(T == NULL) return 0;
   else{
     if(score > T->data.score) return lowerThankey(score,T->left) + lowerThankey(score,T->right) + 1;
    else return lowerThankey(score,T->left) + lowerThankey(score,T->right);
   }
}
int higherThankey(float score, tree T){
   if(T == NULL) return 0;
   else{
     if(score <= T->data.score) return higherThankey(score,T->left) + higherThankey(score,T->right) + 1;
    else return higherThankey(score,T->left) + higherThankey(score,T->right);
   }
}
element higher(float score, tree T){
   if(T != NULL){
     if(score <= T->data.score) printf("%s %s %s %-20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.score,T->data.address);  
    higher(score,T->left);
    higher(score,T->right);
}
}
element lower(float score, tree T){
   if(T != NULL){
     if(score > T->data.score) printf("%s %s %s %-20s %-20g %-20s\n",T->data.name.ho,T->data.name.dem,T->data.name.ten,T->data.id,T->data.score,T->data.address);  
    lower(score,T->left);
    lower(score,T->right);
}
}
