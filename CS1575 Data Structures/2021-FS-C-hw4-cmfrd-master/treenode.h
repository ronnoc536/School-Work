#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
#include "abstractbstree.h"
#include "mybstree.h"
using namespace std;
template<typename T>
class TreeNode
{
  public:
    ~TreeNode();
    T m_data;
    TreeNode* m_right;
    TreeNode* m_left;
    TreeNode(T data, TreeNode<T> * rNode, TreeNode<T> * lNode);
};

template<typename T>
TreeNode<T>* clone(const TreeNode<T>* t);

#include "treenode.hpp"
#endif