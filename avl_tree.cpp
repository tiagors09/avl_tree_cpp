#include <iostream>
#include <algorithm>
#include "avl_tree.h"

using namespace std;

Node::Node(int k) : key(k), balance(0), height(1), left(nullptr), right(nullptr) {}

AvlTree::AvlTree() : root(nullptr) {}

Node *AvlTree::insert(Node *node, int value)
{
  if (node == nullptr)
  {
    return new Node(value);
  }
  else if (value < node->key)
  {
    node->left = insert(node->left, value);
  }
  else if (value > node->key)
  {
    node->right = insert(node->right, value);
  }

  return fixupInsertion(node, value);
}

Node *AvlTree::fixupInsertion(Node *node, int value)
{
  node->height = 1 + max(height(node->left), height(node->right));
  node->balance = balance(node);

  if (node->balance < -1 && value < node->left->key)
  {
    return rightRotation(node);
  }
  if (node->balance < -1 && value > node->left->key)
  {
    node->left = leftRotation(node->left);
    return rightRotation(node);
  }
  if (node->balance > 1 && value > node->right->key)
  {
    return leftRotation(node);
  }
  if (node->balance > 1 && value < node->right->key)
  {
    node->right = rightRotation(node->right);
    return leftRotation(node);
  }

  return node;
}

Node *AvlTree::rightRotation(Node *p)
{
  Node *u = p->left;
  p->left = u->right;
  u->right = p;

  p->height = 1 + max(height(p->left), height(p->right));
  u->height = 1 + max(height(u->left), height(u->right));

  return u;
}

Node *AvlTree::leftRotation(Node *p)
{
  Node *u = p->right;
  p->right = u->left;
  u->left = p;

  p->height = 1 + max(height(p->left), height(p->right));
  u->height = 1 + max(height(u->left), height(u->right));

  return u;
}

int AvlTree::height(Node *node)
{
  if (node == nullptr)
    return 0;
  return node->height;
}

int AvlTree::balance(Node *node)
{
  return height(node->right) - height(node->left);
}

void AvlTree::printTree(Node *node, int space, int levelSpace)
{
  if (node == nullptr)
    return;

  space += levelSpace;
  printTree(node->right, space);

  for (int i = levelSpace; i < space; i++)
  {
    cout << " ";
  }
  cout << node->key << " (H:" << node->height << ", B:" << node->balance << ")\n";

  printTree(node->left, space);
}

void AvlTree::insert(int value)
{
  root = insert(root, value);
}

void AvlTree::printAvlTree()
{
  printTree(root);
}
