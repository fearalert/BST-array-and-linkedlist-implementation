#include <iostream>

#include "../../abstractBST.h"
#define MAX 60

class arrayBST : public BinarySearchTree{
private:
    int array[MAX];

public: 
    arrayBST();
    ~arrayBST();

    void add(int key);
    void del(int key);
    bool search(int targetKey);
    bool isEmpty();
    int max();
    int min();
    void preOrderTraversal();
    void inOrderTraversal();
    int parent(int index);
    void print();
    
protected:
    int getLeftChild(int index);
    int getRightChild(int index);
    void preOrder(int index, char sep = ' ');
    void inOrder(int index, char sep = ' ');
    int max(int index);
    int min(int index);
    void deleteFromKey(int key);

private:
    void replaceNodePosition(int newPos, int prevPos);
};