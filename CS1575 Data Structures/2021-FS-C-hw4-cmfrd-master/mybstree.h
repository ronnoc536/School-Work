#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "abstractbstree.h"
#include "treenode.h"
#include <iostream>
using namespace std;

template<typename T>
class MyBSTree : public AbstractBSTree<T>
{
  private:
    TreeNode<T>* m_root;
    int m_size;
    void insert(TreeNode<T>* node, const T& x);
    
  public:
    MyBSTree();
    MyBSTree<T>(const MyBSTree<T>& rhs);
    virtual ~MyBSTree();
    const T& getMax() const throw (Oops);
    const T& getMin() const throw (Oops);
    int size() const;
    bool isEmpty() const;
    int height() const;
    int find(const T& x) const;
    void clear();
    void insert(const T& x);
    void remove(const T& x);
    void print() const;
    void prettyPrint (const TreeNode<T>* t, int pad) const;
    void printPreOrder() const;
    void printPostOrder() const;
    void printPreOrder(TreeNode<T> * t) const;
    void printPostOrder(TreeNode<T>* t) const;
    void remove(TreeNode<T> * &t, const T& x);
    const T& getMax(TreeNode<T> * t) const;
    const T& getMin(TreeNode<T> * t) const;
    int height(TreeNode<T> * t) const;

    MyBSTree<T>& operator= (const MyBSTree<T>& rhs);  
};

#include "mybstree.hpp"
#endif