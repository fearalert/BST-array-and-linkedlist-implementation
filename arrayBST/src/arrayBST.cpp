#include "../include/arrayBST.h"

arrayBST::arrayBST(){
    for(int index=0;index<MAX;index++){
        this->array[index] = 0;
    }
}

bool arrayBST::isEmpty(){
    return this->array[0] == 0;
}

//function to add key to a BST
void arrayBST::add(int key){
    std::cout << "key added is: " << key << std::endl;

    if(this->array[0]==0){
            this->array[1] = key;
    }
    else{
        for(int index=1; index<MAX;){
            if(this->array[index]==0){
                this->array[index] = key;
                break;
            }
            else if(this->array[index] == key){
                    std::cout << "key already exists." << std::endl;
                    break;
                }
            else if(this->array[index] < key){
                    std::cout << "Inserting right..... " << std::endl;
                    index = (2*index + 1);
            }
            else if(this->array[index] > key){
                    std::cout << "Inserting left..... " << std::endl;
                    index = 2*index;
            }
            else{
                break;
            }
        }
    }
    this->array[0]++;
}

// searches if the key is present in the BST or not
// returns true, if in the BST else return false
bool arrayBST::search(int targetKey){
    std::cout << "Searching for " << targetKey << " in the BST: ";
    for(int index=1; index<MAX;){
        if(this->array[index]== targetKey){
            return true;
        }
        else if(this->array[index] > targetKey || this->array[index] < targetKey){  
            if(this->array[index]> targetKey){
                index= (2*index);
            }
            else{
                index= (2*index)+1;
            }
        }
    } 
    return false;
}

int arrayBST::getLeftChild(int index){
        int leftChild = 2*index;
        return leftChild;
}

int arrayBST::getRightChild(int index){
        int rightChild = 2*index+1;
        return rightChild;
}

int arrayBST::parent(int index){
    return index/2;
}

void arrayBST::deleteFromKey(int key){
    int left = this->array[getLeftChild(key)];
    int right = this->array[getRightChild(key)];

    // if a BST doesnot have any child node
    if(left == 0 && right ==0){
        this->array[key] = 0;
    }

    //If a BST has one child node on right
    if(right != 0 && left == 0){
        this->array[key] = right;

        int right_pos = getRightChild(key);
        this->array[right_pos] = 0;

        replaceNodePosition(key,right_pos);
    }

    //If a BST has one child node on left
    if(left != 0 && right == 0){
        this->array[key] = left;
        int left_pos = getLeftChild(key);
        this->array[left_pos] = 0;
        replaceNodePosition(key,left_pos);
    }

    //if a BST has two children node
    if(left != 0 && right != 0){
        int rightKey = getRightChild(key);
        int index = getLeftChild(rightKey);

        while(this->array[index] != 0){
            index = getLeftChild(index);
        }
        this->array[key] = this->array[parent(index)];
        this->array[parent(index)] = 0;
        replaceNodePosition(key,parent(index));
    }
}

//function to replace node position
void arrayBST::replaceNodePosition(int newPos, int prevPos){

    int newLeftPosition = getLeftChild(newPos);
    int newRightPosition = getRightChild(newPos);
    int leftPos = getLeftChild(prevPos);
    int rightPos = getRightChild(prevPos);

    if(this->array[leftPos] != 0){
       this->array[newLeftPosition] = this->array[leftPos];
       this->array[leftPos] = 0;
    }
    if(this->array[rightPos] != 0){
       this->array[newRightPosition] = this->array[rightPos];
       this->array[rightPos] = 0;
    }
    if(this->array[getLeftChild(leftPos)] != 0 || this->array[getRightChild(leftPos)] != 0){
        replaceNodePosition(newLeftPosition, leftPos);
    }
    if(this->array[getLeftChild(rightPos)] != 0 || this->array[getRightChild(rightPos)] != 0){
        replaceNodePosition(newRightPosition, rightPos);
    }

}

//returns the minimum value in the BST
int arrayBST::min(int index){
    int minimum;
    for(index = 1; index < MAX;){
        if(this->array[2*index]!=0){
            index = 2*index;
        }
        else{
            minimum = this->array[index];
            break;
        }
    }
    return minimum;
}

//returns the maximum value in the BST
int arrayBST::max(int index){
    int maximum;
    for(index = 1; index < MAX;){
        if(this->array[2*index+1]!=0 && (2*index+1) < MAX){
            index = 2*index+1;
        }
        else{
            maximum = this->array[index];
            break;
        }
    }
    return maximum;
}

//function for in order traversal
void arrayBST::inOrder(int index, char sep){

    if(index <= MAX && this->array[index] != 0){
        inOrder(2*index);
        std::cout << this->array[index] << sep;
        inOrder(2*index+1);
    }
}

//function for preOrder traversal
void arrayBST::preOrder(int index, char sep){
    if(index < MAX && this->array[index] != 0)    {
        std::cout << this->array[index] << sep;
        preOrder(2*index);
        preOrder(2*index+1);
    }
}

//function for checking the keys of BST
void arrayBST::print(){
    std::cout << "The key in the given BST is presented as:" << std::endl;
     for(int index=1;index<MAX;index++){
            std::cout << this->array[index] << ' ';
        }
        std::cout << std::endl;
}


void arrayBST::del(int key){
    bool found = search(key);
    if(found == true)
    {
        for(int index=1; index<MAX; index++){
            if(key == this->array[index]){
                std::cout << "key found in BST, now deleting  " << key << std::endl;
                deleteFromKey(index);
                break;
            }
        }
    }
    if(found==false){
        std::cout << "Cannot delete.Given key is not found in BST" << std::endl;
    }
}

void arrayBST::inOrderTraversal(){
    int index = 1;
    std::cout << "InOrder Traversal for given BST is: " << std::endl;
    inOrder(index);
    std::cout << std::endl;
}

void arrayBST::preOrderTraversal(){
    int index = 1;
    std::cout << "PreOrderTraversal for given BST is: " << std::endl;
    preOrder(index);
    std::cout << std::endl;
}

int arrayBST::min(){
    int index=1;
    min(index);
}

int arrayBST::max(){
    int index=1;
    max(index);
}

arrayBST::~arrayBST(){
}
