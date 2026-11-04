#include <iostream>
#include "generalTree.h"
 
int main(){
 
    GeneralTree tree('A');
 
    tree.addChild('A', 'B');
    tree.addChild('A', 'C');
    tree.addChild('A', 'D');
    tree.addChild('A', 'E');
    tree.addChild('A', 'F');
    tree.addChild('A', 'G');
 
    tree.addChild('D', 'H');
 
    tree.addChild('E', 'I');
    tree.addChild('E', 'J');
    tree.addChild('J', 'P');
    tree.addChild('J', 'Q');
 
    tree.addChild('F', 'K');
    tree.addChild('F', 'L');
    tree.addChild('F', 'M');
 
    tree.addChild('G', 'N');
 
    std::cout << "pre-order output: ";
    tree.preOrder(tree.getRoot());
    std::cout << std::endl;
 
    std::cout << "in-order output: ";
    tree.inOrder(tree.getRoot());
    std::cout << std::endl;
 
    std::cout << "post-order output: ";
    tree.postOrder(tree.getRoot());
    std::cout << std::endl;
 
    tree.findData(1, 'J');
 
    tree.addChild('G', 'O');
    tree.findData(2, 'O');
 
    return 0;
}
