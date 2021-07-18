#include "arrayBST.h"

arrayBST::arrayBST(){
    for(int index=0;index<MAX;index++){
        this->array[index] = 0;
    }
}

bool arrayBST::isEmpty(){
    return this->array[0] == 0;
}

void arrayBST::add(int data){
    std::cout << std::endl << "Data added is: " << data << std::endl;

    if(this->array[0]==0){
            this->array[1] = data;
    }
    else{
        for(int index=1; index<MAX;){
            if(this->array[index]==0){
                this->array[index] = data;
                break;
            }
            else if(this->array[index] <= data){
                if(this->array[index] == data){
                    std::cout << "Data already exists." << std::endl;
                    break;
                }
                else{
                    std::cout << "Inserting right..... " << std::endl;
                    index = (2*index + 1);
                }
            }
            else if(this->array[index] >= data){
                if(this->array[index] == data){
                    std::cout << "Data already exists." << std::endl;
                    break;
                }
                else{
                    std::cout << "Inserting left..... " << std::endl;
                    index = 2*index;
                }
            }
            else{
                break;
            }
        }
    }
    this->array[0]++;
}

bool arrayBST::search(int targetKey){
    std::cout << std::endl << "Searching for given key " << targetKey << " in a BST" << std::endl;
    for(int index=1; index<MAX;){
        if(this->array[index]== targetKey){
            std::cout << "Target Key Found."<< std::endl;
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
        else{
            return false;
        }
        
    } 
}

int arrayBST::getLeftChild(int index){
    if(this->array[2*index] != 0 && 2*index < MAX){
        int leftChild = 2*index;
        return this->array[leftChild];
    }
  
}

int arrayBST::getRightChild(int index){
    if(this->array[2*index+1] != 0 && 2*index+1 < MAX){
        int rightChild = 2*index+1;
        return this->array[rightChild];
    }
    
}


void arrayBST::del(int data){

    bool found = search(data);
    if(found == true)
    {for(int index=1; index<MAX; index++){
        if(isEmpty()){
            std::cout << "Tree is empty" << std::endl;
        }
        else{
            if(data == this->array[index]){
                int left = this->array[getLeftChild(index)];
                int right = this->array[getRightChild(index)];
                
                if(left == 0 && right != 0){
                    left = getLeftChild(right);
                    while(left != 0){
                        left = getLeftChild(left);
                    }
                    std::cout << this->array[index] << " is deleted now" << std::endl;
                    this->array[index] = left;
                    this->array[left] = 0;
                    break;
                }
                else if(right == 0 && left != 0){
                    right = getRightChild(left);
                    while(right != 0){
                        right = getRightChild(right);
                    }
                    std::cout << this->array[index] << " is deleted now" << std::endl;
                    this->array[index] = right;
                    this->array[right] = 0;
                    break;
                }
                else{
                    std::cout << this->array[index] << " is deleted now" << std::endl;
                    this->array[index] = 0;
                    break;
                }
            }
        }
      }
    }
    if(!found){
        std::cout << data << " that you entered is not in the tree." << std::endl;
    }
}


int arrayBST::min(){
    int minimum;
    for(int index = 1; index < MAX;){
        if(this->array[2*index]!=0){
            minimum = this->array[2*index];
            index = 2*index;
        }
        else{
            break;
        }
    }
    return minimum;
}

int arrayBST::max(){
    int maximum;
    for(int index = 1; index < MAX;){
        if(this->array[2*index+1]!=0 && (2*index+1) < MAX){
            maximum = this->array[2*index+1];
            index = 2*index+1;
        }
        else{
            break;
        }
    }
    return maximum;
}

void arrayBST::inOrder(int index, char sep){

    if(index <= MAX && this->array[index] != 0){
        inOrder(2*index);
        std::cout << this->array[index] << sep;
        inOrder(2*index+1);
    }
}

void arrayBST::preOrder(int index, char sep){
    if(index !=0 && index < MAX && this->array[index] != 0)    {
        std::cout << this->array[index] << sep;
        preOrder(2*index);
        preOrder(2*index+1);
    }
}

void arrayBST::inOrderTraversal(){
    std::cout << "InOrder Traversal for given BST is: " << std::endl;
    inOrder(1);
    std::cout << std::endl;
}

void arrayBST::preOrderTraversal(){
    std::cout << "preOrderTraversal for given BST is: " << std::endl;
    preOrder(1);
    std::cout << std::endl;
}

arrayBST::~arrayBST(){

}