#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char KeyType;

typedef struct
{
  char model[50];
  int memory;
  int space;
  double screen_size;
  int price;
} phone_t;
typedef phone_t DataType;

typedef struct NodeType{
  KeyType key[50];
  DataType data;
  struct NodeType *left, *right;
} NodeType;

typedef struct NodeType* TreeType;

void makeNullTree(TreeType *T){
  (*T) = NULL;
}

int isEmptyTree(TreeType T){
  return T == NULL;
}

TreeType leftChild(TreeType n){
  if(n != NULL) return n->left;
  else return NULL;
}

TreeType rightChild(TreeType n){
  if(n != NULL) return n->right;
  else return NULL;
}

NodeType *createNode(DataType NewData){
  NodeType *N = NULL;
  N = (NodeType *) malloc(sizeof(NodeType));

  if(N != NULL){
    N->left = NULL;
    N->right = NULL;
    N->data = NewData;
    strcpy(N->key, NewData.model);
  }
  return N;
}

int isLeaf(TreeType n){
  if(n != NULL)
    return (leftChild(n) == NULL) && (rightChild(n) == NULL);
  else return -1;
}

int numNodes(TreeType T){
  if(isEmptyTree(T)) return 0;
  else return 1+numNodes(leftChild(T))+numNodes(rightChild(T));
}

void insertNode(DataType x, TreeType *Root){
  if(*Root == NULL){
    *Root = (NodeType *) malloc(sizeof(NodeType));
    (*Root)->data = x;
    strcpy((*Root)->key, x.model);
    (*Root)->left = NULL;
    (*Root)->right = NULL;
  }
  else if(strcmp(x.model, (*Root)->key) < 0) insertNode(x, &((*Root)->left));
  else if(strcmp(x.model, (*Root)->key) > 0) insertNode(x, &((*Root)->right));
}

KeyType *deleteMin(TreeType *Root){
  KeyType *k;
  if((*Root)->left == NULL){
    strcpy(k, (*Root)->key);
    (*Root) = (*Root)->right;
    return k;
  }
  else return deleteMin(&(*Root)->left);
}

void deleteNode(KeyType x[], TreeType *Root){
  if(*Root != NULL){
    if(strcmp(x, (*Root)->key) < 0) deleteNode(x, &(*Root)->left);
    else if(strcmp((*Root)->key, x)) deleteNode(x, &(*Root)->right);
    else if(((*Root)->left == NULL) && ((*Root)->right == NULL)){
      *Root = NULL;
    }
    else if((*Root)->left == NULL) *Root = (*Root)->right;
    else if((*Root)->right == NULL) *Root = (*Root)->left;
    else strcpy((*Root)->key, deleteMin(&(*Root)->right));
  }
}

// void inOrderPrint(TreeType tree){
//   if(tree != NULL){
//     inOrderPrint(tree->left);
//     printData(tree->data);
//     inOrderPrint(tree->right);
//   }
// }

// void preOrderPrint(TreeType tree){
//   if(tree != NULL){
//     printf("%4d\n", tree->key);
//     preOrderPrint(tree->left);
//     preOrderPrint(tree->right);
//   }
// }

void freeTree(TreeType *tree){
  if(*tree != NULL){
    freeTree(&((*tree)->left));
    freeTree(&((*tree)->right));
    free(*tree);
  }
}

void FindMin();
void FindMax();
int elementCompare();

TreeType Search(KeyType *x, TreeType Root){
  if(Root == NULL || strcmp(x, Root->key) == 0) return Root;
  else if(strcmp(x, Root->key) < 0) return Search(x, Root->left);
  else if(strcmp(x, Root->key) > 0) return Search(x, Root->right);
}