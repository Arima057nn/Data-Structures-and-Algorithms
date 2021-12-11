#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int element;
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
// Access left and righ child
tree leftChild(tree T){
  if(T != NULL)   return T->left;
  else return NULL;
}
tree rightChild(tree T){
  if(T != NULL)   return T->right;
  else return NULL;
  
}
//cheack if a tree is a NULL
int isEmpty(tree T){
  return T == NULL;
}

//Check if a node is a leaves
int isLeaf(tree T){
  if(T != NULL){
    return (leftChild(T) == NULL) && (rightChild(T) == NULL);
  }else return -1;
}

//Creat a tree from two sub-tree
tree createEfrom2(element e, tree l, tree r){
  tree N = (node*)malloc(sizeof(node));
  N->data = e;
  N->left = l;
  N->right = r;
  return N;
}


// Number of node
int nb_nodes(tree T){
  if(isEmpty(T)) return 0;
  else return 1 +nb_nodes(leftChild(T)) + nb_nodes(rightChild(T));
}


tree addRight(tree *T,element e){
  node *new = createNewNode(e);
  if(*T == NULL){
    *T = new;
  }else{
    node *Rnode = *T;
    while (Rnode->right != NULL)
      Rnode = Rnode->right;
    Rnode->right = new;
  }
  return new;
}
tree addLeft(tree *T,element e){
  node *new = createNewNode(e);
  if(*T == NULL){
    *T = new;
    }else{
    node *Lnode = *T;
    while (Lnode->left != NULL)
      Lnode = Lnode->left;
    Lnode->left = new;
  }
  return new;
}

// Number of leaf node
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

int nb_internalNode(tree T){
  if(isEmpty(T)) return 0;
  else if(isLeaf(T)) return 0;
  else return 1 + nb_internalNode(T->right) + nb_internalNode(T->left);

}
void inorderprint(tree T){
  if(T != NULL){
    inorderprint(T->left);
    printf("%4d\n",T->data);
    inorderprint(T->right);
  }
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
void DeleteNode(element x, tree *T){
  if(*T != NULL){
    if(x < (*T)->data) DeleteNode(x,&(*T)->left);
    else if(x > (*T)->data) DeleteNode(x,&(*T)->right);
    else if(((*T)->left == NULL )&&((*T)->right == NULL))
      *T = NULL;
    else if((*T)->left == NULL)
      *T = (*T)->right;
    else if((*T)->right == NULL)
      *T = (*T)->left;
    else (*T)->data = DeleteMin(&(*T)->right);
  }
}

void freeTree(tree T){
  if(T != NULL){
    freeTree(T->right);
    freeTree(T->left);
    free((void *)T);
  }
}

void insertNode(element x, tree *T){
  if(*T == NULL){
    *T = createNewNode(x);
  }
  else if(x < (*T)->data) return insertNode(x,&(*T)->left);
  else if(x > (*T)->data) return insertNode(x,&(*T)->right);
}

element findMax();
element findMin();

void preoderprint(tree T){
  if(T != NULL){
    printf("%4d\n",T->data);
    preoderprint(T->left);
    preoderprint(T->right);
  }
}