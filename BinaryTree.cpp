#include <iostream>
#include "BinaryTree.h"


// Create a new Order
Order *BinaryTree::createNewOrder(int orderNumber, bool orderType, int volume, float orderPriceLevel) {
    Order *newOrder = new Order();
    newOrder->idNumber = orderNumber;
    newOrder->buyOrSell = orderType;
    newOrder->size = volume;
    newOrder->entryTime = 0;
    newOrder->nextOrder == NULL;
    newOrder->prevOrder == NULL;
    newOrder->parentLimit == NULL;

    return newOrder;
}


// Create a new Limit Node
Limit *BinaryTree::createNewLimit(float priceLevel) {
    Limit *newLimit = new Limit();
    newLimit->limitPrice = priceLevel;
    newLimit->leftChild = NULL;
    newLimit->rightChild = NULL;
    newLimit->headOrder = NULL;
    newLimit->tailOrder = NULL;
    return newLimit;
}

// In-order traversal binary search tree
void BinaryTree::inOrder(Limit *limit) {
    if(limit == NULL) {
        return;
    }
    inOrder(limit->leftChild);
    std::cout << limit->limitPrice << ",";
    inOrder(limit->rightChild);
}

// Insert new Limit price level on binary tree
void BinaryTree::insert(Limit *limit, float priceLevel) {
    if(root == NULL) {
        root = new Limit();
        root->limitPrice = priceLevel;
        root->leftChild = NULL;
        root->rightChild = NULL;
        root->headOrder = NULL;
        root->tailOrder = NULL;
        return;
    }

    float compareValue = priceLevel - limit->limitPrice;

    if(compareValue < 0) {
        if(limit->leftChild == NULL) {
            limit->leftChild = createNewLimit(priceLevel);
        } else {
            insert(limit->leftChild,priceLevel);
        }
    } else if(compareValue > 0) {
        if(limit->rightChild == NULL) {
            limit->rightChild = createNewLimit(priceLevel);
        } else {
            insert(limit->rightChild, priceLevel);
        }
    }
}

Limit *BinaryTree::getRoot() {
    return root;
}

// Free memory
void BinaryTree::freeMemory(Limit *limit) {
    if(limit == NULL) {
        return;
    }
    freeMemory(limit->leftChild);
    freeMemory(limit->rightChild);

    delete limit;
}

BinaryTree::~BinaryTree() { freeMemory(root); }


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