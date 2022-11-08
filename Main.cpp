#include <iostream>
#include "BinaryTree.h"



int main() {

    BinaryTree *buyTree = new BinaryTree();

    buyTree->insert(buyTree->getRoot(), 60.15);
    buyTree->insert(buyTree->getRoot(), 60.15);
    buyTree->insert(buyTree->getRoot(), 60.35);
    buyTree->insert(buyTree->getRoot(), 50.15);
    buyTree->insert(buyTree->getRoot(), 42.15);
    buyTree->insert(buyTree->getRoot(), 35.00);
    buyTree->insert(buyTree->getRoot(), 20.05);


    std::cout << "Buy order book: \n";
    buyTree->inOrder(buyTree->getRoot());
    std::cout << "\n";

    delete buyTree;

    return 0;
}