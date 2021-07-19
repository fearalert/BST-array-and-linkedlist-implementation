

#include <iostream>
#include "../../abstractBST.h"

#ifndef LINKEDBST_H
#define LINKEDBST_H

class LinkedBST : public BinarySearchTree
{
    private:
       int data;
       LinkedBST *left, *right;
      
    public:
      LinkedBST();
      LinkedBST(int);
      bool isEmpty();
      LinkedBST* addBST(LinkedBST* root, int value);
      bool searchBST(LinkedBST* root,int value);
      void inorder(LinkedBST* root);
      void preorder(LinkedBST* root);
      LinkedBST* minValue(LinkedBST* root);
      LinkedBST* maxValue(LinkedBST* root);
      LinkedBST*  removeBST(LinkedBST* root, int value);

      void add(int data){}
      void del(int data){}
      void preOrderTraversal(){
         LinkedBST *root;
         std::cout << "Pre Order Traversal is :" << std::endl;
         preorder(root);
         std::cout << std::endl;
      }
      void inOrderTraversal(){}
      bool search(int data){}
      int max(){}
      int min(){}


};

#endif