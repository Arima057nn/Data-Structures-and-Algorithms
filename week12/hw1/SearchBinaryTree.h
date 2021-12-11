#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef phone element;

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
  else if(TraVe(x,(*T)->data) == -1) return insertNode(x,&(*T)->left);
  else if(TraVe(x,(*T)->data) == 1) return insertNode(x,&(*T)->right);
}

/*void insertNode(element x, tree *T){
  if(*T == NULL){
    *T = createNewNode(x);
  }
  else if(x < (*T)->data) return insertNode(x,&(*T)->left);
  else if(x > (*T)->data) return insertNode(x,&(*T)->right);
}
*/

element DeleteMin(tree *T){
  element k;
  if( (*T)->left == NULL){
    k = (*T)->data;
    (*T) = (*T)->right;
    return k;
  }
  else return DeleteMin(&(*T)->left);
  }
void DeleteNode(element x, tree *T){
  if(*T != NULL){
    if(TraVe(x,(*T)->data) == -1) DeleteNode(x,&(*T)->left);
    else if(TraVe(x,(*T)->data) == 1) DeleteNode(x,&(*T)->right);
    else if(((*T)->left == NULL )&&((*T)->right == NULL))
      *T = NULL;
    else if((*T)->left == NULL)
      *T = (*T)->right;
    else if((*T)->right == NULL)
      *T = (*T)->left;
    else (*T)->data = DeleteMin(&(*T)->right);
  }
}
int Searching(element x, tree *T){
  if(*T == NULL){
    return 0;
  }
  if(TraVe(x,(*T)->data) == 0){ 
    return 1;
    }
  else if(TraVe(x,(*T)->data) == -1) return Searching(x,&(*T)->left);
  else if(TraVe(x,(*T)->data) == 1) return Searching(x,&(*T)->right);

}
element findMax();
element findMin();
void inorderprint(tree T){
  if(T != NULL){
    inorderprint(T->left);
   printf("%-20s %-20d %-20d %-20s\n",T->data.model,T->data.size,T->data.memory,T->data.price);  
   
    inorderprint(T->right);
  }
}


void preoderprint(tree T){
  if(T != NULL){
   printf("%-20s %-20d %-20d %-20s\n",T->data.model,T->data.size,T->data.memory,T->data.price);  
    preoderprint(T->left);
    preoderprint(T->right);
  }
}
void freeTree(tree T){
  if(T != NULL){
    freeTree(T->right);
    freeTree(T->left);
    free((void *)T);
  }
}

