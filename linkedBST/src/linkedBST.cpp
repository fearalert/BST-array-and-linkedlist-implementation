#include "../include/linkedBST.h"

LinkedBST::LinkedBST()
{
    data = 0;
    left = NULL;
    right = NULL;
}

bool LinkedBST::isEmpty()
{
    LinkedBST* root;
    return root == NULL ;
}

LinkedBST::LinkedBST(int value)
{
  data = value;
  left = right = NULL;
}

LinkedBST* LinkedBST::addBST(LinkedBST* root, int value)
{
    if (!root)
    {
        return new LinkedBST(value);
    }
    if (value > root->data)
    {
        root->right = addBST(root->right, value);
    }
    else
    {
        root->left = addBST(root->left, value);
    }
 
    return root;
}

LinkedBST* LinkedBST::minValue(LinkedBST* root)
{
   if(root == NULL)
   {
      std::cout << "The tree is empty." << std::endl;
   }
   else if(root->left == NULL)
   {
       return root;
   }
   else{
       return  minValue(root->left);
   }
}

LinkedBST* LinkedBST::maxValue(LinkedBST* root)
{
   if(root == NULL)
   {
       return root;
   }
   else if(root->right == NULL)
   {
       return root;
   }
   else{
       return maxValue(root->right);
   }
}

bool LinkedBST::searchBST(LinkedBST* root,int value)
{
 if(root == NULL || root -> data == value)
 {
   return root;
 }
 else if(value < root -> data)
 {
   return searchBST(root -> left,value);
 }
 else 
 {
   return searchBST(root -> right,value) ;
 }
 return root;
}

void LinkedBST::inorder(LinkedBST* root)
{
    if (root != NULL) 
    {
        inorder(root -> left);
        std::cout << root -> data << " ";
        inorder(root -> right);
    }
    
}

void LinkedBST::preorder(LinkedBST* root)
{
    if (root != NULL) 
    {
        std::cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}


LinkedBST*  LinkedBST::removeBST(LinkedBST* root, int value)
{
  LinkedBST* temp;
  if(root == NULL)
  {
      return root ;
  }

  else if(value < root->data)
  {
      root->left = removeBST(root->left,value);
  }
  else if(value > root->data)
  {
      root->right = removeBST(root->right,value);
  }
  else if(root->left && root->right)
        {
            temp = minValue(root -> right);
            root->data = temp->data;
            root->right = removeBST(root->right,root->data);
        }
        else
        {
            temp = root;
            if(root->left == NULL)
                root = root->right;
            else if(root->right == NULL)
                root = root->left;
            delete temp;
        }

        return root;
}