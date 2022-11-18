#include <iostream>
#include "BinaryTree.h"


int main() {

    BinaryTree *bidTree = new BinaryTree();

    Limit oneL = Limit(25.00, 200, 200, NULL, NULL, NULL, NULL, NULL);
    Order one = Order(1, true, 300, 25.50, NULL, NULL, NULL); // How do you insert a specific limit in here?
    one.parentLimit = &oneL;
    
    bidTree->insert(bidTree->getRoot(), 43.43);
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