#include "../../abstractBST.h"
#include "../include/arrayBST.h"

int main(){
    arrayBST a;

    a.add(10);
    a.add(3);
    a.add(12);
    a.add(8);
    a.add(6);
    a.add(14);
    a.add(13);
    a.add(4);
    a.add(7);

    std::cout << std::endl;
    a.inOrderTraversal();

    std::cout << std::endl;
    std::cout << "Displays 1 if in the tree, otherwise displays 0" <<std::endl; 
    std::cout << a.search(48) << std::endl;
    std::cout << a.search(7) <<std::endl;

    a.preOrderTraversal();
    std::cout << std::endl << "Minimum value in given BST is: " << a.min() << std::endl;
    std::cout << "Maximum value in given BST is: " << a.max() << std::endl;

    a.del(4);
    std::cout << std::endl;

    a.del(10);
    std::cout << std::endl;
    a.inOrderTraversal();

    a.del(3);
    a.inOrderTraversal();

    a.del(29);

    std::cout << std::endl << "Minimum value in given BST is: " << a.min() << std::endl;
    std::cout << "Maximum value in given BST is: " << a.max() << std::endl;

return 0;
}
