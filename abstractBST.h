#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <iostream>

class BinarySearchTree{
public:
    virtual void preOrderTraversal() = 0;
    virtual void add(int)=0;
    virtual bool search(int ) = 0;
    virtual int min() = 0;
    virtual int max() = 0;
    virtual void inOrder() = 0;
    virtual void del(int ) = 0;
};


#endif // !BINARYSEARCHTREE_H