#include <iostream>
#include "BinaryTree.h"
#include "Order.h"


int main() {

    BinaryTree *bidTree = new BinaryTree();
    Order one = Order(1, 0, 300, 25.50);
    
    bidTree->insert(bidTree->getRoot(), 60.15);
    bidTree->insert(bidTree->getRoot(), 60.15);
    bidTree->insert(bidTree->getRoot(), 60.35);
    bidTree->insert(bidTree->getRoot(), 50.15);
    bidTree->insert(bidTree->getRoot(), 42.15);
    bidTree->insert(bidTree->getRoot(), 35.00);
    bidTree->insert(bidTree->getRoot(), 20.05);


    std::cout << "Buy order book: \n";
    bidTree->inOrder(bidTree->getRoot());
    std::cout << "\n";

    bool test = bidTree->isLimit(bidTree->getRoot(), 35); 
    std::cout << test << "\n";

    delete bidTree;

    return 0;
}