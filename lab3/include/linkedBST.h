#include <iostream>
#include "abstractBST.h"

#ifndef LINKEDBST_H
#define LINKEDBST_H

class LinkedBST : public abstractBST
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
      void deleteitem(int item){}
      void preordertraversal(){}
      void inordertraversal(){}
      void search(int data){}
      int maximum(){}
      int minimum(){}


};

#endif