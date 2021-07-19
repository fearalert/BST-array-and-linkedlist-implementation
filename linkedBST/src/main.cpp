#include "../include/linkedBST.h"

int main()
{
    LinkedBST L , *root = NULL;
    root = L.addBST(root, 45);
    L.addBST(root, 50);
    L.addBST(root, 49);
    L.addBST(root, 60);
    L.addBST(root, 70);
    L.addBST(root, 80);
    L.addBST(root, 30);
    L.addBST(root, 33);
    L.addBST(root, 34);
    L.addBST(root, 100);
    L.addBST(root, 103);
    std::cout << "Binary Search Tree arranged in inorder traversal:"  << std::endl;
    L.inorder(root);
    std::cout << std::endl << "Binary Search Tree arranged in preorder traversal:"  << std::endl;
    L.preorder(root);
    std::cout << std::endl << "Displays '1' if element is in the tree else displays '0'." << std::endl;
    std::cout << L.searchBST(root,12) << std::endl;
    std::cout << L.searchBST(root,100) << std::endl;
    L.removeBST(root,45);
    std::cout << "After Deletion" << std::endl;
    std::cout << "Binary Search Tree arranged in Inorder traversal:" << std::endl;
    L.inorder(root);
    L.removeBST(root,30);
    std::cout << std::endl << "Binary Search Tree arranged in Inorder traversal:" << std::endl;
    L.inorder(root);
    
    
    return 0;
}