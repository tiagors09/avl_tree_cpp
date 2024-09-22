#include "avl_tree.h"

int main()
{
  AvlTree tree;
  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  tree.printAvlTree();
  return 0;
}
