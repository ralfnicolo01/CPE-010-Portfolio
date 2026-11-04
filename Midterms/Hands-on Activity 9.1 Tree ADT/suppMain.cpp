#include <iostream>
#include "BST.h"
 
int main(){
 
    BinarySearchTree<int>* tree = new BinarySearchTree(2);
 
    tree->insert(3);
    tree->insert(9);
    tree->insert(18);
    tree->insert(0);
    tree->insert(1);
    tree->insert(4);
    tree->insert(5);
    
    std::cout<<"pre-order output: ";
    tree->preOrder();
    std::cout<<std::endl;
 
    std::cout<<"in-order output: ";
    tree->inOrder();
    std::cout<<std::endl;
 
    std::cout<<"post-order output: ";
    tree->postOrder();
    std::cout<<std::endl;
 
    return 0;
}
