#include <iostream>

#include "..\abstractBST.h"
#define MAX 30

class arrayBST : public BinarySearchTree{
private:
    int array[MAX];

public: 
    arrayBST();
    ~arrayBST();

    void add(int data);
    void del(int data);
    bool search(int targetKey);
    bool isEmpty();
    int max();
    int min();
    void preOrderTraversal();
    void inOrderTraversal();
    int getLeftChild(int index);
    int getRightChild(int index);
    void preOrder(int index, char sep = ' ');
    void inOrder(int index, char sep = ' ');
};