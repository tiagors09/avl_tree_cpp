#ifndef AVL_TREE_H
#define AVL_TREE_H

class Node
{
public:
  int key;
  int balance;
  int height;
  Node *left;
  Node *right;

  Node(int k);
};

class AvlTree
{
private:
  Node *root;
  Node *insert(Node *node, int value);
  Node *fixupInsertion(Node *node, int value);
  Node *rightRotation(Node *node);
  Node *leftRotation(Node *node);
  int height(Node *node);
  int balance(Node *node);
  void printTree(Node *node, int space = 0, int levelSpace = 4);

public:
  AvlTree();
  void insert(int value);
  void printAvlTree();
};

#endif
