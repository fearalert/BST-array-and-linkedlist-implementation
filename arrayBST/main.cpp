#include "../abstractBST.h"
#include "arrayBST.h"

int main(){
    arrayBST a;

    a.add(10);
    a.add(5);
    a.add(4);
    a.add(29);
    a.add(40);
    a.add(7);
    a.add(20);
    a.add(3);
    std::cout << std::endl;
    a.inOrderTraversal();
    a.search(48);
    std::cout << std::endl;
    a.preOrderTraversal();
    std::cout << std::endl << "Minimum value in given BST is: " << a.min() << std::endl;
    std::cout << "Maximum value in given BST is: " << a.max() << std::endl;
    std::cout << std::endl << "Left child of index 0  in BST is: " << a.getLeftChild(1) << std::endl;
    std::cout << "Right child of index 0 in BST is: " << a.getRightChild(1) << std::endl;
    a.del(49);
    a.del(3);
    std::cout << std::endl;
    a.inOrderTraversal();

    std::cout << "Minimum value in given BST is: " << a.min() << std::endl;
    std::cout << "Maximum value in given BST is: " << a.max() << std::endl;

return 0;
}
