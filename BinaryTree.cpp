#include "BinaryTree.h"


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


bool BinaryTree::isLimit(Limit *limit, float priceLevel) {
    if(limit == NULL) {
        return false;
    }

    if(limit->limitPrice == priceLevel) {
        return true;
    }

    bool res1 = isLimit(limit->leftChild, priceLevel);
    if(res1) return true;

    bool res2 = isLimit(limit->rightChild, priceLevel);
    return res2;
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


