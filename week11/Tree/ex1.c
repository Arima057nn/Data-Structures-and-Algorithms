#include <stdio.h>
#include <stdlib.h>
#define FALSE -1

typedef int elementtype;

typedef struct node
{
  elementtype data;
  struct node *left, *right;
} node;

typedef node* tree;

void Initialize(tree* t)
{
  *t = NULL;
  return;
}

int IsEmpty(tree t)
{
  return t == NULL;
}

tree LeftChild(tree t)
{
  if (t != NULL)
    return t->left;
  return NULL;
}

tree RightChild(tree t)
{
  if (t != NULL)
    return t->right;
  return NULL;
}

node* CreateNode(elementtype data)
{
  node* n = (node*)malloc(sizeof(node));
  if (n != NULL)
    {
      n->data = data;
      n->left = NULL;
      n->right = NULL;
    }
  return n;
}

int IsLeaf(tree t)
{
  if (t != NULL)
    return LeftChild(t) == NULL && RightChild(t) == NULL;
  return FALSE;
}

int NumNode(tree t)
{
  if (IsEmpty(t))
    return 0;
  return 1 + NumNode(LeftChild(t)) + NumNode(RightChild(t));
}

tree CreateFrom2(elementtype data, tree t_left, tree t_right)
{
  tree t = (node*)malloc(sizeof(node));
  if (t != NULL)
    {
      t->data = data;
      t->left = t_left;
      t->right = t_right;
    }
  return t;
}

tree AddLeft(tree *t, elementtype data)
{
  node* n = (node*)malloc(sizeof(node));
  if (n == NULL)
    return NULL;
  n = CreateNode(data);
  if (*t == NULL)
    *t = n;
  else
    {
      node* p = *t;
      while (p->left != NULL)
	p = p->left;
      p->left = n;
    }
  return n;
}

tree AddRight(tree *t, elementtype data)
{
  node* n = (node*)malloc(sizeof(node));
  if (n == NULL)
    return NULL;
  n = CreateNode(data);
  if (*t == NULL)
    *t = n;
  else
    {
      node* p = *t;
      while (p->right != NULL)
	p = p->right;
      p->right = n;
    }
  return n;
}

int Max(int a, int b)
{
  if (a > b) return a;
  return b;
}

int High(tree t)
{
  if (t == NULL)
    return 0;
  else return 1 + Max( High(t->left), High(t->right) );
}

int NumLeaf(tree t)
{
  if (t == NULL)
    return 0;
  else if (IsLeaf(t) == 1)
    return 1;
  else return ( NumLeaf(t->right) + NumLeaf(t->left) );
}

int NumIntlNode(tree t)
{
  if (t == NULL)
    return 0;
  else if (IsLeaf(t) == 1)
    return 0;
  else return 1 + NumIntlNode(t->left) + NumIntlNode(t->right);
}

int NumRChild(tree t)
{
  if (t == NULL)
    return 0;
  if (t->right == NULL)
    return NumRChild(t->left);
  return 1 + NumRChild(t->left) + NumRChild(t->right);
}
int main(){

  int i;
  tree t = (node*)malloc(sizeof(node));
  Initialize(&t);
  for (i = 0; i < 6; ++i)
    AddRight(&t, i);
  for (i = 0; i < 3; ++i)
    AddLeft(&t, i);
  AddRight(&t->left, 0);
  AddRight(&t->left, 1);
  AddRight(&t->left->left, 0);
  AddRight(&t->left->left, 1);
  printf("%d\t%d\t%d\t%d\n", High(t), NumLeaf(t), NumIntlNode(t), NumRChild(t));

  return 0;
}
